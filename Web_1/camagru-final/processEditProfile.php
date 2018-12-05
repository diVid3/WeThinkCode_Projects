<?php
session_start();
require_once ('inc/errors.php');
require_once ('inc/connect.php');
require_once ('inc/initialize.php');
require_once ('inc/usercheck.php');

if (isset($_SESSION['username']) == false || isset($_SESSION['password']) == false ||
isset($_SESSION['email']) == false || isset($_SESSION['notification']) == false)
    exit;

if (isset($_POST['editProfileFormUsername']) == false || isset($_POST['editProfileFormPassword']) == false || 
isset($_POST['editProfileFormConfirmPassword']) == false || isset($_POST['editProfileFormEmail']) == false ||
isset($_POST['editProfileFormNotification']) == false)
    exit;

$editProfileFormUsername = trim($_POST['editProfileFormUsername']);
$editProfileFormPassword = trim($_POST['editProfileFormPassword']);
$editProfileFormConfirmPassword = trim($_POST['editProfileFormConfirmPassword']);
$editProfileFormEmail = trim($_POST['editProfileFormEmail']);
$editProfileFormNotification = trim($_POST['editProfileFormNotification']);

// Connect to db.

$query1 = 'USE ' . $DB_DATABASE_NAME . ';';
$PDO = connectDBMS();
$PDO->query($query1);

// Username checks.

if (strlen($editProfileFormUsername) > 32 == true) {
    $json = ['usernameTooLong' => 1];
    echo json_encode($json);
    exit;
}
if (strlen($editProfileFormUsername) < 4 == true) {
    $json = ['usernameTooShort' => 1];
    echo json_encode($json);
    exit;
}
if (preg_match('/\W+/', $editProfileFormUsername) === 1) {
    $json = ['usernameSpecCharFound' => 1];
    echo json_encode($json);
    exit;
}
$usernameArr = preg_split('/\s+/', $editProfileFormUsername);
if (array_key_exists(0, $usernameArr) == true && array_key_exists(1, $usernameArr) == true) {
    $json = ['usernameMultipleWords' => 1];
    echo json_encode($json);
    exit;
}
try {
    $query2 = 'SELECT * FROM `users` WHERE `username` = ?';
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$editProfileFormUsername]);
}
catch (PDOexception $e) {
    error_log($e);
}
if ($stmt->rowCount() > 0) {
    $loweredUsernameFromSession = strtolower($_SESSION['username']);
    $loweredUsernameFromEditForm = strtolower($editProfileFormUsername);
    if ($loweredUsernameFromSession != $loweredUsernameFromEditForm) {
        $json = ['usernameTaken' => 1];
        echo json_encode($json);
        exit;
    }
}

// Password checks.

if (strlen($editProfileFormPassword) < 7 == true) {
    $json = ['passwordTooShort' => 1];
    echo json_encode($json);
    exit;
}
if (preg_match('/[A-Z]/', $editProfileFormPassword) === 0) {
    $json = ['passwordNoMix' => 1];
    echo json_encode($json);
    exit;
}
if ($editProfileFormPassword != $editProfileFormConfirmPassword) {
    $json = ['passwordMatch' => 0];
    echo json_encode($json);
    exit;
}

// Email checks.

if (strlen($editProfileFormEmail) > 32 == true) {
    $json = ['emailTooLong' => 1];
    echo json_encode($json);
    exit;
}
if (filter_var($editProfileFormEmail, FILTER_VALIDATE_EMAIL) == false) {
    $json = ['emailNotValid' => 1];
    echo json_encode($json);
    exit;
}
try {
    $query2 = 'SELECT * FROM `users` WHERE `email` = ?';
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$editProfileFormUsername]);
}
catch (PDOexception $e) {
    error_log($e);
}
if ($stmt->rowCount() > 0) {
    $loweredEmailFromSession = strtolower($_SESSION['email']);
    $loweredEmailFromEditForm = strtolower($editProfileFormEmail);
    if ($loweredEmailFromSession != $loweredEmailFromEditForm) {
        $json = ['emailTaken' => 1];
        echo json_encode($json);
        exit;
    }
}

// Notification checks.

if ($editProfileFormNotification == 'true') 
    $editProfileFormNotificationValue = 1;
else
    $editProfileFormNotificationValue = 0;

// Edit profile.

try {
    $hash = password_hash($editProfileFormPassword, PASSWORD_BCRYPT, ['cost' => 11]);
    $query1 = 'UPDATE `users` SET `username` = ?, `password` = ?, `email` = ?, `notification` = ?  WHERE `username` = ?';
    $stmt = $PDO->prepare($query1);
    $stmt->execute([$editProfileFormUsername, $hash, $editProfileFormEmail, $editProfileFormNotificationValue, $_SESSION['username']]);
}
catch (PDOexception $e) {
    error_log($e);
}

// Migrating picture ownership.

try {
    $query1 = 'UPDATE `pictures` SET `username` = ? WHERE `username` = ?';
    $stmt = $PDO->prepare($query1);
    $stmt->execute([$editProfileFormUsername, $_SESSION['username']]);
}
catch (PDOexception $e) {
    error_log($e);
}

// Updating session.

$_SESSION['username'] = $editProfileFormUsername;
$_SESSION['email'] = $editProfileFormEmail;
$_SESSION['password'] = $hash;
$_SESSION['notification'] = $editProfileFormNotificationValue;

// Notify modal.

$json = ['editedProfile' => 1];
echo json_encode($json);
?>

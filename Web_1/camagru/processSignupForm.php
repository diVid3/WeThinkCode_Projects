<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');

$signupFormUsername = trim($_POST['signupFormUsername']);
$signupFormPassword = trim($_POST['signupFormPassword']);
$signupFormConfirmPassword = trim($_POST['signupFormConfirmPassword']);
$signupFormEmail = trim($_POST['signupFormEmail']);
$signupFormNotification = trim($_POST['signupFormNotification']);

// Username checks.

if (strlen($signupFormUsername) > 32 == true) {
    $json = ['usernameTooLong' => 1];
    echo json_encode($json);
    exit;
}
if (strlen($signupFormUsername) < 4 == true) {
    $json = ['usernameTooShort' => 1];
    echo json_encode($json);
    exit;
}
if (preg_match('/\W+/', $signupFormUsername) === 1) {
    $json = ['usernameSpecCharFound' => 1];
    echo json_encode($json);
    exit;
}
$usernameArr = preg_split('/\s+/', $signupFormUsername);
if (array_key_exists(0, $usernameArr) == true && array_key_exists(1, $usernameArr) == true) {
    $json = ['usernameMultipleWords' => 1];
    echo json_encode($json);
    exit;
}
try {
    $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
    $query2 = 'SELECT `username` FROM `users` WHERE `username` = ?';
    $PDO = connectDBMS();
    $PDO->query($query1);
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$signupFormUsername]);
}
catch (PDOexception $e) {
    error_log($e);
}
if ($stmt->rowCount() > 0) {
    $json = ['usernameTaken' => 1];
    echo json_encode($json);
    exit;
}

// Password checks. Need to add mix case check.

if (strlen($signupFormPassword) < 7 == true) {
    $json = ['passwordTooShort' => 1];
    echo json_encode($json);
    exit;
}
if ($signupFormPassword != $signupFormConfirmPassword) {
    $json = ['passwordMatch' => 0];
    echo json_encode($json);
    exit;
}

// Email checks.

if (strlen($signupFormEmail) > 32 == true) {
    $json = ['emailTooLong' => 1];
    echo json_encode($json);
    exit;
}
if (filter_var($signupFormEmail, FILTER_VALIDATE_EMAIL) == false) {
    $json = ['emailNotValid' => 1];
    echo json_encode($json);
    exit;
}
try {
    $query2 = 'SELECT `email` FROM `users` WHERE `email` = ?';
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$signupFormEmail]);
}
catch (PDOexception $e) {
    error_log($e);
}
if ($stmt->rowCount() > 0) {
    $json = ['emailTaken' => 1];
    echo json_encode($json);
    exit;
}

// Notification checks.

if ($signupFormNotification == 'true') 
    $signupFormNotificationValue = 1;
else
    $signupFormNotificationValue = 0;

// Account creation.

try {
    $hash = password_hash($signupFormPassword, PASSWORD_BCRYPT, ['cost' => 11]);
    $verify_hash = bin2hex(random_bytes(32));
    $verified = 0;
    $query2 = 'INSERT INTO `users` (`username`, `password`, `email`, `notification`, `verify_hash`, `verified`) VALUES (?,?,?,?,?,?)';
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$signupFormUsername, $hash, $signupFormEmail, $signupFormNotificationValue, $verify_hash, $verified]);
}
catch (PDOexception $e) {
    error_log($e);
}

// Send verification email.

$to = $signupFormEmail;
$subject = 'Camagru | Verification';
$message = 'Thank you for signing up to Camagru! To complete your registration, just click on the link below to activate your account.

Please click on this link:
http://127.0.0.1:8080/verify.php?email=' . $signupFormEmail . '&verify_hash=' . $verify_hash;

mail($to, $subject, $message);

// Notifiy modal.

$json = ['accountCreated' => 1];
echo json_encode($json);

?>

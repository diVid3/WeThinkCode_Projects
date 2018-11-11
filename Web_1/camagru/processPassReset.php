<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');

$resetPassFormUsername = trim($_POST['resetPassFormUsername']);
$resetPassFormPassword = trim($_POST['resetPassFormPassword']);
$resetPassFormConfirmPassword = trim($_POST['resetPassFormConfirmPassword']);
$resetPassFormToken = trim($_POST['resetPassFormToken']);

// Username checks.

if (preg_match('/\W+/', $resetPassFormUsername) === 1) {
    $json = ['usernameSpecCharFound' => 1];
    echo json_encode($json);
    exit;
}

try {
    $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
    $query2 = 'SELECT * FROM `users` WHERE `username` = ?';
    $PDO = connectDBMS();
    $PDO->query($query1);
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$resetPassFormUsername]);
}
catch (PDOexception $e) {
    error_log($e);
}
if ($stmt->rowCount() == 0) {
    $json = ['usernameNotRegistered' => 1];
    echo json_encode($json);
    exit;
}

// Password checks.

if (strlen($resetPassFormPassword) < 7 == true) {
    $json = ['passwordTooShort' => 1];
    echo json_encode($json);
    exit;
}
if ($resetPassFormPassword != $resetPassFormConfirmPassword) {
    $json = ['passwordMatch' => 0];
    echo json_encode($json);
    exit;
}

// Token checks.

try {
    $query1 = 'SELECT * FROM `users` WHERE `username` = ? AND `reset_hash` = ?';
    $stmt = $PDO->prepare($query1);
    $stmt->execute([$resetPassFormUsername, $resetPassFormToken]);
}
catch (PDOexception $e) {
    error_log($e);
}
if ($stmt->rowCount() == 0) {
    $json = ['tokenInvalid' => 1];
    echo json_encode($json);
    exit;
}

// Reset password.

try {
    $newPassword = password_hash($resetPassFormPassword, PASSWORD_BCRYPT, ['cost' => 11]);
    $query1 = 'UPDATE `users` SET `password` = ? WHERE `username` = ? AND `reset_hash` = ?';
    $stmt = $PDO->prepare($query1);
    $stmt->execute([$newPassword, $resetPassFormUsername, $resetPassFormToken]);
    $query2 = 'UPDATE `users` SET `reset_hash` = ? WHERE `username` = ? AND `reset_hash` = ?';
    $stmt = $PDO->prepare($query2);
    $newResetHash = bin2hex(random_bytes(32));
    $stmt->execute([$newResetHash, $resetPassFormUsername, $resetPassFormToken]);
}
catch (PDOexception $e) {
    error_log($e);
}

// Notify modal.

$json = ['passResetSuccessful' => 1];
echo json_encode($json);

?>

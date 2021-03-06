<?php
session_start();
require_once ('inc/errors.php');
require_once ('inc/connect.php');
require_once ('inc/initialize.php');
require_once ('inc/usercheck.php');

if (isset($_POST['forgotPasswordFormUsername']) == false)
    exit;

$forgotPasswordFormUsername = trim($_POST['forgotPasswordFormUsername']);

if (preg_match('/\W+/', $forgotPasswordFormUsername) === 1) {
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
    $stmt->execute([$forgotPasswordFormUsername]);
}
catch (PDOexception $e) {
    error_log($e);
}
if ($stmt->rowCount() == 0) {
    $json = ['usernameNotRegistered' => 1];
    echo json_encode($json);
    exit;
}

// Insert reset hash into database.

try {
    $reset_hash = bin2hex(random_bytes(32));
    $query2 = 'UPDATE `users` SET `reset_hash` = ? WHERE `username` = ?';
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$reset_hash, $forgotPasswordFormUsername]);
}
catch (PDOexception $e) {
    error_log($e);
}

// Retrieve associated email account.

$query1 = 'SELECT `email` FROM `users` WHERE `username` = ?';
$stmt = $PDO->prepare($query1);
$stmt->execute([$forgotPasswordFormUsername]);
$rowArr = $stmt->fetch(PDO::FETCH_ASSOC);
$forgotPasswordFormEmail = $rowArr['email'];

// Send reset password email.

$to = $forgotPasswordFormEmail;
$subject = 'Camagru | Reset Password';

$passwordResetPagePath = catPathToString('reset_pass.php');
$message = 'A password reset for the Camagru account connected to this email address has been requested, please click the link below to reset your password. You\'ll need to enter your username as well as the token that is supplied in this email. If this was not you, you can safely ignore this message.

Link to password reset page:
' . $passwordResetPagePath . '

The reset token:
' . $reset_hash;

mail($to, $subject, $message);

// Notify modal.

$json = ['forgotPasswordEmailSent' => 1];
echo json_encode($json);

?>

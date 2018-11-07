<?php
session_start();
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');

$forgotPasswordFormEmail = trim($_POST['forgotPasswordFormEmail']);

if (strlen($forgotPasswordFormEmail) > 32 == true) {
    $json = ['emailTooLong' => 1];
    echo json_encode($json);
    exit;
}
if (filter_var($forgotPasswordFormEmail, FILTER_VALIDATE_EMAIL) == false) {
    $json = ['emailNotValid' => 1];
    echo json_encode($json);
    exit;
}
try {
    $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
    $query2 = 'SELECT `email` FROM `users` WHERE `email` = ?';
    $PDO = connectDBMS();
    $PDO->query($query1);
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$forgotPasswordFormEmail]);
}
catch (PDOexception $e) {
    error_log($e);
}
if ($stmt->rowCount() == 0) {
    $json = ['emailNotRegistered' => 1];
    echo json_encode($json);
    $PDO = NULL;
    exit;
}

// Insert reset hash into database.

try {
    $reset_hash = bin2hex(random_bytes(32));
    $query2 = 'UPDATE `users` SET `reset_hash` = ? WHERE `email` = ?';
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$reset_hash, $forgotPasswordFormEmail]);
}
catch (PDOexception $e) {
    error_log($e);
}

// Send reset password email.

$to = $forgotPasswordFormEmail;
$subject = 'Camagru | Reset Password';
$message = 'A password reset for the Camagru account connected to this email address has been requested, please click the link below to go to the related web page to reset your password. You\'ll be required to enter your username If this was not you, you can safely ignore this message.

Please click on this link:
http://127.0.0.1:8080/reset_pass.php?email=' . $forgotPasswordFormEmail . '&reset_hash=' . $reset_hash;

mail($to, $subject, $message);

// Notify modal.

$json = ['forgotPasswordEmailSent' => 1];
echo json_encode($json);

$PDO = NULL;
?>

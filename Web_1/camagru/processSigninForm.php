<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');

$signinFormUsername = trim($_POST['signinFormUsername']);
$signinFormPassword = trim($_POST['signinFormPassword']);

// Check if username is valid.

try {
    $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
    $query2 = 'SELECT `password` FROM `users` WHERE `username` = ?';
    $PDO = connectDBMS();
    $PDO->query($query1);
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$signinFormUsername]);
}
catch (PDOexception $e) {
    error_log($e);
}
if ($stmt->rowCount() == 0) {
    $json = ['usernameInvalid' => 1];
    echo json_encode($json);
    exit;
}

// Check if password is valid.

try {
    $query1 = 'SELECT `password` FROM `users` WHERE `username` = ?';
    $stmt = $PDO->prepare($query1);
    $stmt->execute([$signinFormUsername]);
    $rowArr = $stmt->fetch(PDO::FETCH_ASSOC);
    $userPassword = $rowArr['password'];
}
catch (PDOexception $e) {
    error_log($e);
}
if (password_verify($signinFormPassword, $userPassword) == false) {
    $json = ['passwordInvalid' => 1];
    echo json_encode($json);
    exit;
}

// Check if account has been verified.

try {
    $query1 = 'SELECT `verified` FROM `users` WHERE `username` = ?';
    $stmt = $PDO->prepare($query1);
    $stmt->execute([$signinFormUsername]);
    $rowArr = $stmt->fetch(PDO::FETCH_ASSOC);
    $userVerified = $rowArr['verified'];
}
catch (PDOexception $e) {
    error_log($e);
}
if ($userVerified == 0) {
    $json = ['accountNotVerified' => 1];
    echo json_encode($json);
    exit;
}

// Setting $_SESSION variables.

$query1 = 'SELECT * FROM `users` WHERE `username` = ?';
$stmt = $PDO->prepare($query1);
$stmt->execute([$signinFormUsername]);
$rowArr = $stmt->fetch(PDO::FETCH_ASSOC);
$userEmail = $rowArr['email'];
$_SESSION['username'] = $signinFormUsername;
$_SESSION['email'] = $userEmail;
$_SESSION['password'] = $signinFormPassword;

// Notify successful sign in.

$json = ['successfulSignin' => 1, 'username' => $signinFormUsername];
echo json_encode($json);
?>

<?php
session_start();
require_once ('inc/errors.php');
require_once ('inc/connect.php');
require_once ('inc/initialize.php');
require_once ('inc/usercheck.php');

// If any part is lacking, exit.
if ((isset($_GET['email']) == true && empty($_GET['email']) == false &&
isset($_GET['verify_hash']) == true && empty($_GET['verify_hash']) == false) == false)
    exit;

// Checking if email and verify_hash exists.
try {
    $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
    $query2 = 'SELECT * FROM `users` WHERE `email` = ? AND `verify_hash` = ?';
    $PDO = connectDBMS();
    $PDO->query($query1);
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$_GET['email'], $_GET['verify_hash']]);
}
catch (PDOexception $e) {
    error_log($e);
}
if ($stmt->rowCount() == 0) {
    header('Location: ' . catPathToString('index.php?verify=fail'));
    exit;
}

// Updating verified field.
try {
    $query2 = 'UPDATE `users` SET `verified` = ?  WHERE `email` = ?';
    $stmt = $PDO->prepare($query2);
    $stmt->execute([1, $_GET['email']]);
}
catch (PDOexception $e) {
    error_log($e);
}

// Need to redirect here upon success.
header('Location: ' . catPathToString('index.php?verify=success'));
exit;
?>

<?php
session_start();
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');

// If any part is lacking, exit.
if ((isset($_GET['email']) == true && empty($_GET['email']) == false && isset($_GET['verify_hash']) == true && empty($_GET['verify_hash']) == false) == false) {
    echo "Unauthorized Access - Go away." . '<br>';
    exit;
}

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
    header("Location: http://127.0.0.1:8080/index.php?verify=fail");
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
header("Location: http://127.0.0.1:8080/index.php?verify=success");
exit;
?>

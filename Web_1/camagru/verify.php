<?php
session_start();
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');

// If any part is lacking, exit.
if ((isset($_GET['email']) == true && empty($_GET['email']) == false && isset($_GET['verify_hash']) == true && empty($_GET['verify_hash']) == false) == false) {
    echo "Unauthorized access" . '<br>';
    exit;
}

// Checking if account has been activated already.
try {
    $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
    $query2 = 'SELECT ``,`` FROM `users` WHERE `email` = ?';
    $PDO = connectDBMS();
    $PDO->query($query1);
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$_GET['email']]);
    $row = $stmt->fetch(PDO::FETCH_ASSOC);
    print_r($row);
}
catch (PDOexception $e) {
    error_log($e);
}

?>

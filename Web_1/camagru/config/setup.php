<?php
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
include_once ($_SERVER['DOCUMENT_ROOT'] . '/config/database.php');
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');

function createDB() {
    global $DB_DATABASE_NAME;

    try {
        $PDO = connectDBMS();
        $PDO->query("CREATE DATABASE IF NOT EXISTS $DB_DATABASE_NAME");
        $PDO = NULL;
    }
    catch (PDOexception $e) {
        error_log($e);
    }
}

function createUserTable() {
    global $DB_DATABASE_NAME;

    $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
    $query2 = 'CREATE TABLE IF NOT EXISTS `users` (
        `user_id` VARCHAR(64) PRIMARY KEY,
        `username` VARCHAR(16) NOT NULL UNIQUE,
        `password` VARCHAR(32) NOT NULL,
        `email` VARCHAR(32) NOT NULL UNIQUE
    );';
    try {
        $PDO = connectDBMS();
        $PDO->query($query1);
        $PDO->query($query2);
        $PDO = NULL;
    }
    catch (PDOexecption $e) {
        error_log($e);
    }
}

createDB();
createUserTable();

// Might need to add the ability to drop database and reconstruct.

?>

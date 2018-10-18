<?php
include ("database.php");

function createDB() {
    global $DB_SERVER;
    global $DB_USER;
    global $DB_PASSWORD;
    global $DB_DATABASE_NAME;
    global $DB_DSN;

    try {
        $PDO = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
        $PDO->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $PDO->query("CREATE DATABASE IF NOT EXISTS $DB_DATABASE_NAME");
        $PDO = NULL;
    }
    catch (PDOexception $e) {
        echo "Failed to create database $DB_DATABASE_NAME" . PHP_EOL;
        echo "Exception message: " . $e->getMessage();
    }
}

createDB();
?>

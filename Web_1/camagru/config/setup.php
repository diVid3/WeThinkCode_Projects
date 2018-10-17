<?php
include("database.php");

function createDB() {
    try {
        $PDO = new PDO($DB_DSN, $DB_USERNAME, $DB_PASSWORD);
        $PDO->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $PDO->exec("CREATE DATABASE IF NOT EXISTS $DB_DATABASE_NAME");
        echo "Created database $DB_DATABASE_NAME" . PHP_EOL;
        return $PDO;
    }
    catch (PDOexception $e) {
        echo "Failed to create database $DB_DATABASE_NAME" . PHP_EOL;
        echo "Exception message: " . $e->getMessage();
    }
}

createDB();
?>

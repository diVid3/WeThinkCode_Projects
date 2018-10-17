<?php
include("database.php");

function createDB() {
    try {
        $PDO = new PDO("mysql:host=$DB_SERVER", $DB_USERNAME, $DB_PASSWORD);
        $PDO->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $PDO->query("CREATE DATABASE IF NOT EXISTS $DB_DATABASE_NAME");
        $PDO = NULL;
        echo "DB made!\n";
    }
    catch (PDOexception $e) {
        echo "Failed to create database $DB_DATABASE_NAME" . PHP_EOL;
        echo "Exception message: " . $e->getMessage();
    }
}

createDB();
?>

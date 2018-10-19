<?php
session_start();
include_once ("database.php");

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
        $_SESSION['errorMsg'] = 'Failed to create database ' . $DB_DATABASE_NAME . '<br/>';
        $_SESSION['errorObj'] = serialize($e);
        //header("Location: ../error.php");
        header("Location: http://127.0.0.1:8080/camagru/error.php");
    }
}

function connectDB() {
    global $DB_DSN;
    global $DB_USER;
    global $DB_PASSWORD;
    global $DB_DATABASE_NAME;

    try {
        $PDO = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
        return ($PDO);
    }
    catch (PDOexception $e) {
        $_SESSION['errorMsg'] = 'Failed to connect to database' . $DB_DATABASE_NAME . '<br/>';
        $_SESSION['errorObj'] = serialize($e);
        header("Location: ../error.php");
    }
}

function createUserTable() {
    $query = "";
}
?>

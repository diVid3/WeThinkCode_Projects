<?php
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
include_once ($_SERVER['DOCUMENT_ROOT'] . '/config/database.php');

function connectDBMS() {
    global $DB_DSN;
    global $DB_USER;
    global $DB_PASSWORD;

    try {
        $PDO = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
        $PDO->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        return ($PDO);
    }
    catch (PDOexception $e) {
        error_log($e);
    }
}
?>

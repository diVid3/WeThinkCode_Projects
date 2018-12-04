<?php
require_once ('inc/errors.php');
require_once ('config/database.php');

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

// Function concatenates a given string to the path to this script.
// One can thus supply relative paths.
function catPathToString($fileString) {
    $URL = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
    $arr = explode("/", $URL);
    $arr = array_slice($arr, 0, sizeof($arr) - 1);
    return (implode ("/", $arr) . '/' . $fileString);
}
?>

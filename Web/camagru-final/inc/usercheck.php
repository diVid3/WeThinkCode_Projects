<?php
if (session_id() == '' || isset($_SESSION) == false) {
    session_start();
}
require_once ('inc/errors.php');
require_once ('inc/connect.php');
require_once ('inc/initialize.php');

if (isset($_SESSION['username']) == true &&
isset($_SESSION['password']) == true && isset($_SESSION['email'])) {
    try {
        $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
        $query2 = 'SELECT `username` FROM `users` WHERE `username` = ?';
        $PDO = connectDBMS();
        $PDO->query($query1);
        $stmt = $PDO->prepare($query2);
        $stmt->execute([$_SESSION['username']]);
    }
    catch (PDOexception $e) {
        error_log($e);
        require_once ('sign_out.php');
        exit;
    }
    if ($stmt->rowCount() == 0) {
        require_once ('sign_out.php');
    }
}
?>

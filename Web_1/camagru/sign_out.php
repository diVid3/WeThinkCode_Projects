<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');

if (isset($_SESSION['username']) == true && isset($_SESSION['password']) == true &&
isset($_SESSION['email']) == true && isset($_SESSION['notification']) == true) {
    // unset($_SESSION['username']);
    // unset($_SESSION['password']);
    // unset($_SESSION['email']);
    unset($_SESSION['username']);
    unset($_SESSION['email']);
    unset($_SESSION['password']);
    unset($_SESSION['notification']);
}
header('Location: ' . catPathToString('index.php'));
?>

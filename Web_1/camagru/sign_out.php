<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');

if (isset($_SESSION['username']) == true && isset($_SESSION['password']) == true && isset($_SESSION['email'])) {
    unset($_SESSION['username']);
    unset($_SESSION['password']);
    unset($_SESSION['email']);
}
header("Location: http://127.0.0.1:8080/index.php");
?>

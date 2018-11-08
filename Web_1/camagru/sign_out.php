<?php
session_start();
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
if (isset($_SESSION['username']) == true && isset($_SESSION['password']) == true) {
    unset($_SESSION['username']);
    unset($_SESSION['password']);
}
header("Location: http://127.0.0.1:8080/index.php");
?>

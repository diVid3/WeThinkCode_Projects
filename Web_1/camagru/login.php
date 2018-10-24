<?php
session_start();
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
$_SESSION['loggedIn'] = 0;
header('Location: http://localhost:8080/index.php');
?>

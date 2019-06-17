<?php
if (session_id() == '' || isset($_SESSION) == false) {
    session_start();
}
require_once ('inc/errors.php');
require_once ('inc/connect.php');
require_once ('inc/initialize.php');

if (isset($_SESSION['username']) == true && isset($_SESSION['password']) == true &&
isset($_SESSION['email']) == true && isset($_SESSION['notification']) == true) {
    unset($_SESSION['username']);
    unset($_SESSION['email']);
    unset($_SESSION['password']);
    unset($_SESSION['notification']);
}
header('Location: ' . catPathToString('index.php'));
?>

<?php
session_start();
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');

if (isset($_POST['signupFormUsername']))
    echo $_POST['signupFormUsername'] . "\n";
if (isset($_POST['signupFormPassword']))
    echo $_POST['signupFormPassword'] . "\n";
if (isset($_POST['signupFormConfirmPassword']))
    echo $_POST['signupFormConfirmPassword'] . "\n";
if (isset($_POST['signupFormEmail']))
    echo $_POST['signupFormEmail'] . "\n";

// if (isset($_POST[]))
?>

<?php
session_start();
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
// Need to change this, as button is navbar without signed in.
if (isset($_SESSION['username']) == false && isset($_SESSION['password']) == false) {
    header('HTTP/1.1 403 Forbidden');
    exit;
}
echo "Click!" . '<br>';
?>

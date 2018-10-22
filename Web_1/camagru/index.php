<?php
session_start();
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');

if (file_exists('errors.log') == false) {
    $errorLog = fopen('errors.log', 'w');
    fclose($errorLog);
}
if (file_exists('initialized.txt') == false) {
    include_once ($_SERVER['DOCUMENT_ROOT'] . '/config/setup.php');
    $initFile = fopen('initialized.txt', 'w');
    fclose($initFile);
}
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Camagru</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="main.css" />
    <script src="main.js"></script>
</head>
<body>
    hi
</body>
</html>

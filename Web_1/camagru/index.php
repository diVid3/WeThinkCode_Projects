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
    <div class="float-header">
        <!-- <form action="login.php" method="POST">
            Username:
            <input type="text" name="username">
            Password:
            <input type="text" name="password">
            <input type="submit" name="submit">
        </form> -->
        <div class="box-1">
            <div style="text-align:center;">
                <a href='gallery.php'>Gallery</a>
            </div>
        </div>
        <div class="box-2">
            <div style="text-align:center;">
                <a href='sign_up.php'>Take a Photo</a>
            </div>
        </div>
        <div class="box-3">
            <div style="text-align:center;">
                <a href='sign_up.php'>Sign Up</a>
            </div>
        </div>
        <div class="box-4">
            <div style="text-align:center;">
                <a href='login.php'>Log In</a>
            </div>
        </div>
    </div>
    <div id="body-push">
    </div>
    <div style="font-size:500%;">
        Lorem ipsum dolor sit amet, consectetur adipisicing elit. Soluta laborum perspiciatis aut, quibusdam recusandae eveniet fuga facere eos. Natus esse rem ipsa temporibus, enim earum deleniti officiis culpa qui autem.
        Lorem ipsum dolor sit amet consectetur adipisicing elit. Molestias impedit, numquam facilis aliquam magni excepturi veniam fuga at, expedita magnam est vel veritatis eligendi, error dicta eos beatae repellendus ut.
    </div>
</body>
</html>
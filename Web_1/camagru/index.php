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
<html style="height:100%;">
<head>
    <meta charset="utf-8" />
    <title>Camagru</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="main.css" />
    <script src="main.js"></script>
</head>
<body style="height:100%;">
    <div class="float-header">
        <!-- <form action="login.php" method="POST">
            Username:
            <input type="text" name="username">
            Password:
            <input type="text" name="password">
            <input type="submit" name="submit">
        </form> -->
        <div class="float-header-box" onclick="location.href='take_photo.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='take_photo.php'>Take a Photo</a>
            </div>
        </div>
        <div class="float-header-box" onclick="location.href='gallery.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='gallery.php'>Gallery</a>
            </div>
        </div>
        <div class="float-header-box" onclick="location.href='sign_up.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='sign_up.php'>Sign Up</a>
            </div>
        </div>
        <div class="float-header-box" onclick="location.href='login.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='login.php'>Log In</a>
            </div>
        </div>
    </div>
    <div id="body-push">
    </div>
    <div style="font-size:300%;">
        <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Soluta laborum perspiciatis aut, quibusdam recusandae eveniet fuga facere eos. Natus esse rem ipsa temporibus, enim earum deleniti officiis culpa qui autem.</p><br>
        <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Molestias impedit, numquam facilis aliquam magni excepturi veniam fuga at, expedita magnam est vel veritatis eligendi, error dicta eos beatae repellendus ut.</p><br>
        <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Molestias impedit, numquam facilis aliquam magni excepturi veniam fuga at, expedita magnam est vel veritatis eligendi, error dicta eos beatae repellendus ut.</p><br>
        <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Molestias impedit, numquam facilis aliquam magni excepturi veniam fuga at, expedita magnam est vel veritatis eligendi, error dicta eos beatae repellendus ut.</p>
    </div>
</body>
</html>
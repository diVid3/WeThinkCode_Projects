<?php
session_start();
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Camagru</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/sign_up.css"/>
    <script src="sign_up.js"></script>
</head>
<body>
    <header class="header">
        <div class="header-box">
            <div style="text-align:center;display:inline-block;">
                <a href='index.php' class="click" style="display:inline-block" onclick="location.href='index.php';" style="cursor:pointer;text-align:center;">
                    <p>Camagru</p>
                </a>
            </div>
        </div>
        <div class="header-box">
            <div style="text-align:center;display:inline-block;">
                <a href='take_photo.php' class="click" style="display:inline-block" onclick="location.href='take_photo.php';" style="cursor:pointer;text-align:center;">
                    <p>Take a pic</p>
                </a>
            </div>
        </div>
        <div class="header-box">
            <div style="text-align:center;display:inline-block;">
                <a href='gallery.php' class="click" style="display:inline-block" onclick="location.href='gallery.php';" style="cursor:pointer;text-align:center;">
                    <p>Gallery</p>
                </a>
            </div>
        </div>
        <div class="header-box">
            <div style="text-align:center;display:inline-block;">
                <a href='sign_up.php' class="click" style="display:inline-block;" onclick="location.href='sign_up.php';" style="cursor:pointer;text-align:center;">
                    <p>Sign up</p>
                </a>
            </div>
        </div>
        <div class="header-box">
            <div style="text-align:center;display:inline-block;">
                <a href='login.php' class="click" style="display:inline-block;" onclick="location.href='login.php';" style="cursor:pointer;text-align:center;">
                    <p>Sign in</p>
                </a>
            </div>
        </div>
    </header>
    <div class="push-content">
    </div>
    <div class="content">
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <form class="grid-item-center" action="login.php" method="POST">
            <div class="sign_up-items" style="text-align:center;">
                <div style="display:inline-block;flex-grow:1;">
                    <p class="sign-up-form">Sign up</p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:flex-end;">
                <div style="flex-grow:1;padding-bottom:3px;">
                    <p>Username:</p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;">
                <div style="flex-grow:1;">
                    <input type="text" name="username" required placeholder="Enter your username...">
                </div>
            </div>
            <div class="sign_up-items" style="align-items:flex-end;">
                <div style="flex-grow:1;padding-bottom:3px;">
                    <p>Password:</p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;">
                <div style="flex-grow:1;">
                    <input type="password" name="password" minlength="8" required placeholder="Enter your password...">
                </div>
            </div>
            <div class="sign_up-items" style="align-items:flex-end;">
                <div style="flex-grow:1;padding-bottom:3px;">
                    <p>Confirm password:</p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;">
                <div style="flex-grow:1;">
                    <input type="password" name="password" minlength="8" required placeholder="Enter your password...">
                </div>
            </div>
            <div class="sign_up-items" style="align-items:flex-end;">
                <div style="flex-grow:1;padding-bottom:3px;">
                    <p>Email:</p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;padding-bottom:4%;">
                <div style="flex-grow:1;">
                    <input type="text" name="email" required placeholder="Enter your email...">
                </div>
            </div>
            <button class="sign_up-item-button" name="name" value="value" type="submit">
                <div style="flex-grow:1;text-align:center;">
                    <p>Sign up</p>
                </div>
            </button>
        </form>
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item"></div>
    </div>
    <footer class="footer">
        <div class="footer-box">
            <div style="text-align:center;">
                <p>Copyright | diVid3 2018</p>
            </div>
        </div>
    </footer>
</body>
</html>

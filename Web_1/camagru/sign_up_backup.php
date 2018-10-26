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
</head>
<body>
    <header class="header">
        <div class="header-box" onclick="location.href='index.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='index.php'><p>Camagru</p></a>
            </div>
        </div>
        <div class="header-box" onclick="location.href='take_photo.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='take_photo.php'><p>Take a pic</p></a>
            </div>
        </div>
        <div class="header-box" onclick="location.href='gallery.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='gallery.php'><p>Gallery</p></a>
            </div>
        </div>
        <div class="header-box" onclick="location.href='sign_up.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='sign_up.php'><p>Sign up</p></a>
            </div>
        </div>
        <div class="header-box" onclick="location.href='login.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='login.php'><p>Log in</p></a>
            </div>
        </div>
    </header>
    <div class="push-content">
    </div>
    <div class="content">
        <!-- <form action="login.php" method="POST">
            <p>Username:
            <input type="text" name="username"></p>
            <p>Password:</p>
            <input type="text" name="password">
            <input type="submit" name="submit">
        </form> -->
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item-center">
            <div class="sign_up-item-first">
            </div>
            <div class="sign_up-items">
            <div style="flex-grow:1;">
                    <p>Sign up</p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;">
                <div style="flex-grow:1;">
                    <p>Username:</p>
                </div>
            </div>
            <div class="sign_up-items">
                <div style="flex-grow:1;">
                    <input type="text" placeholder="Enter your username...">
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;">
                <div style="flex-grow:1;">
                    <p>Password:</p>
                </div>
            </div>
            <div class="sign_up-items">
                <div style="flex-grow:1;">
                    <input type="text" placeholder="Enter your password...">
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;">
                <div style="flex-grow:1;">
                    <p>Confirm password:</p>
                </div>
            </div>
            <div class="sign_up-items">
                <div style="flex-grow:1;">
                    <input type="text" placeholder="Enter your password...">
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;">
                <div style="flex-grow:1;">
                    <p>Email:</p>
                </div>
            </div>
            <div class="sign_up-items">
                <div style="flex-grow:1;">
                    <input type="text" placeholder="Enter your email...">
                </div>
            </div>     
            <div class="sign_up-item-button" onclick="location.href='#';" style="cursor: pointer;">
                <div style="flex-grow:1;text-align:center">
                    <p>Sign up</p>
                </div>
            </div>
            <div class="sign_up-item-last">
            </div>
        </div>
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item"></div>
    </div>
    <footer class="footer">
        <div class="footer-box">
            <div style="text-align:center;">
                <p>Copyright &copy diVid3 2018</p>
            </div>
        </div>
    </footer>
</body>
</html>

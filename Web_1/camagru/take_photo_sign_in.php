<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Camagru</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/take_photo_sign_in.css"/>
</head>
<body>
    <!-- Modal markup -->
    <div id="formModal" class="modal">
        <div id="modalRow" class="modal-row">
            <div class="modal-column">
                <p class="modalHeader" id="modalHeader">Please sign in</p><br>
                <p class="errorModal" id="modalText"> You need to be signed in to take a picture.</p><br>
                <div id="okButton" class="okButton"><p>ok</p></div>
            </div>
        </div>
    </div>
    <!-- Normal body -->
    <header class="header">
        <div class="header-box">
            <div style="text-align:center;display:inline-block;">
                <a href='index.php' id="nav1href" class="click" style="display:inline-block" onclick="location.href='index.php';" style="cursor:pointer;text-align:center;">
                    <p id="nav1text">Camagru</p>
                </a>
            </div>
        </div>
        <div class="header-box">
            <div style="text-align:center;display:inline-block;">
                <a href='take_photo.php' id="nav2href" class="click" style="display:inline-block" onclick="location.href='take_photo.php';" style="cursor:pointer;text-align:center;">
                    <p id="nav2text">Take a pic</p>
                </a>
            </div>
        </div>
        <div class="header-box">
            <div style="text-align:center;display:inline-block;">
                <a href='gallery.php' id="nav3href" class="click" style="display:inline-block" onclick="location.href='gallery.php';" style="cursor:pointer;text-align:center;">
                    <p id="nav3text">Gallery</p>
                </a>
            </div>
        </div>
        <div class="header-box">
            <div style="text-align:center;display:inline-block;">
                <a href='sign_up.php' id="nav4href" class="click" style="display:inline-block;" onclick="location.href='sign_up.php';" style="cursor:pointer;text-align:center;">
                    <p id="nav4text">Sign up</p>
                </a>
            </div>
        </div>
        <div class="header-box">
            <div style="text-align:center;display:inline-block;">
                <a href='sign_in.php' id="nav5href" class="click" style="display:inline-block;" onclick="location.href='sign_in.php';" style="cursor:pointer;text-align:center;">
                    <p id="nav5text">Sign in</p>
                </a>
            </div>
        </div>
    </header>
    <div class="push-content">
    </div>
    <div class="content">
    </div>
    <footer class="footer">
        <div class="footer-box">
            <div style="text-align:center;">
                <p>Copyright | diVid3 2018</p>
            </div>
        </div>
    </footer>
    <!-- JS source here -->
    <script src="js/take_photo_sign_in.js"></script>
</body>
</html>

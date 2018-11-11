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
    <link rel="stylesheet" type="text/css" media="screen" href="css/gallery.css"/>
</head>
<body>
    <!-- Modal markup -->
    <div id="formModal" class="modal">
        <div id="modalRow" class="modal-row">
            <div class="modal-column">
                <p class="modalHeader" id="modalHeader">Double-check form</p><br>
                <p class="errorModal" id="modalText"></p><br>
                <div id="okButton" class="okButton"><p>ok</p></div>
            </div>
        </div>
    </div>
    <!-- Normal body -->
    <?php
        if (isset($_SESSION['username']) == false && isset($_SESSION['password']) == false)
            require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/header_sign_in.html');
        else
            require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/header_sign_out.html');
    ?>
    <div class="push-content">
    </div>
    <div class="content">
        <!-- <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item-center"></div> -->
        <!-- <form class="grid-item-center" id="editProfileForm">
            <div class="sign_up-items" style="text-align:center;">
                <div style="display:inline-block;flex-grow:1;">
                    <p class="sign-up-form">Edit profile</p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:flex-end;">
                <div style="flex-grow:1;padding-bottom:3px;">
                    <p>New username:</p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;">
                <div style="flex-grow:1;">
                    <input type="text" name="username" placeholder="Enter your username..." id="editProfileFormUsername">
                </div>
            </div>
            <div class="sign_up-items" style="align-items:flex-end;">
                <div style="flex-grow:1;padding-bottom:3px;">
                    <p>New password:</p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;">
                <div style="flex-grow:1;">
                    <input type="password" name="password" placeholder="Enter your password..." id="editProfileFormPassword">
                </div>
            </div>
            <div class="sign_up-items" style="align-items:flex-end;">
                <div style="flex-grow:1;padding-bottom:3px;">
                    <p>Confirm password:</p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;">
                <div style="flex-grow:1;">
                    <input type="password" name="password" placeholder="Enter your password..." id="editProfileFormConfirmPassword">
                </div>
            </div>
            <div class="sign_up-items" style="align-items:flex-end;">
                <div style="flex-grow:1;padding-bottom:3px;">
                    <p>New email:</p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;padding-bottom:4%;">
                <div style="flex-grow:1;">
                    <input type="text" name="email" placeholder="Enter your email..." id="editProfileFormEmail">
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;">
                <div style="flex-grow:1;padding-bottom:3px;">
                    <p>Email notifications:</p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;padding-bottom:4%;">
                <div style="flex-grow:1;">
                    <input type="checkbox" name="notification" id="editProfileFormNotification">
                </div>
            </div>
            <button class="sign_up-item-button" name="name" value="value" type="submit">
                <div style="flex-grow:1;text-align:center;">
                    <p>Edit profile</p>
                </div>
            </button>
        </form> -->
        <!-- <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item"></div> -->
    </div>
    <footer class="footer">
        <div class="footer-box">
            <div style="text-align:center;">
                <p>Copyright | diVid3 2018</p>
            </div>
        </div>
    </footer>
    <!-- JS source here -->
    <script src="js/gallery.js"></script>
</body>
</html>

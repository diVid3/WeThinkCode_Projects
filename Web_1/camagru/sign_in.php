<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/usercheck.php');

if (isset($_SESSION['username']) == true && isset($_SESSION['password']) == true &&
isset($_SESSION['email']) == true && isset($_SESSION['notification']) == true) {
    header('Location: ' . catPathToString('sign_out.php'));
}
// if (isset($_SESSION['username']) == true && isset($_SESSION['password']) == true) {
//     unset($_SESSION['username']);
//     unset($_SESSION['password']);
//     unset($_SESSION['email']);
//     header('Location: ' . catPathToString('sign_in.php'));
// }
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Camagru</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/sign_in.css"/>
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
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <div class="grid-item"></div>
        <form class="grid-item-center" id="signinForm">
            <div class="sign_up-items" style="text-align:center;">
                <div style="display:inline-block;flex-grow:1;">
                    <p class="sign-up-form" id="formHeader">Sign in</p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:flex-end;">
                <div style="flex-grow:1;padding-bottom:3px;">
                    <p>Username:</p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;">
                <div style="flex-grow:1;">
                    <input type="text" name="username" placeholder="Enter your username..." id="signinFormUsername">
                </div>
            </div>
            <div class="sign_up-items" style="align-items:flex-end;">
                <div style="flex-grow:1;padding-bottom:3px;">
                    <p>Password:</p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;">
                <div style="flex-grow:1;">
                    <input type="password" name="password" placeholder="Enter your password..." id="signinFormPassword">
                </div>
            </div>
            <div class="sign_up-items" style="align-items:flex-end;">
                <div style="flex-grow:1;padding-bottom:3px;">
                    <p></p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;">
                <div style="flex-grow:1;">
                </div>
            </div>
            <div class="sign_up-items" style="align-items:flex-end;">
                <div style="flex-grow:1;padding-bottom:3px;">
                    <p></p>
                </div>
            </div>
            <div class="sign_up-items" style="align-items:center;">
                <div style="flex-grow:1;">
                </div>
            </div>
            <div class="sign_up-items" style="align-items:flex-end;">
                <div style="flex-grow:1;padding-bottom:3px;">
                    <p></p>
                </div>
            </div>
            <div class="sign_up-items" style="flex-direction:column;align-items:center;padding-bottom:4%;">
                <div style="flex-grow:1;">
                    <p style="color:#4285F4;cursor:pointer;" onclick="location.href='forgot_pass.php'">Forgot password?</p>
                </div>
            </div>
            <button class="sign_up-item-button" name="name" value="value" type="submit">
                <div style="flex-grow:1;text-align:center;">
                    <p>Sign in</p>
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
    <!-- JS source here -->
    <script src="js/sign_in.js"></script>
</body>
</html>

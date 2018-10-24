<?php
// echo 'Signed Up!' . '<br>';
session_start();
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Sign Up</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="main.css" />
    <script src="main.js"></script>
</head>
<body style="height:100%;">
    <div class="float-header">
        <div class="float-header-box" onclick="location.href='take_photo.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='take_photo.php'><p class="responsive">Take a Photo</p></a>
            </div>
        </div>
        <div class="float-header-box" onclick="location.href='gallery.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='gallery.php'><p class="responsive">Gallery</p></a>
            </div>
        </div>
        <div class="float-header-box" onclick="location.href='sign_up.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='sign_up.php'><p class="responsive">Sign Up</p></a>
            </div>
        </div>
        <?php
        if ($_SESSION['loggedIn'] == 1)
            echo "<div class='float-header-box' onclick='location.href='login.php';' style='cursor: pointer;'><div style='text-align:center;'><a href='login.php'><p class='responsive'>Log Out</p></a></div></div>";
        else
            echo "<div class='float-header-box' onclick='location.href='login.php';' style='cursor: pointer;'><div style='text-align:center;'><a href='login.php'><p class='responsive'>Log In</p></a></div></div>";
        ?>
        <!-- <div style="flex: 20%" class="float-header-box" onclick="location.href='login.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='login.php'><p class="responsive">Log In</p></a>
            </div>
        </div> -->
    </div>
    <!-- This invisible div is used to push the body down so the body aligns with the floating navbar. -->
    <div id="body-push">
    </div>
    <div>
        <form action="login.php" method="POST">
            <p class="responsive">Username:</p>
            <input type="text" name="username">
            <p class="responsive">Password:</p>
            <input type="text" name="password">
            <input type="submit" name="submit">
        </form>
    </div>
    <!-- Here you can better see the structure of 3 container flexbox use. -->
    <div class="footer">
        <div class="footer-box">
            <div style="text-align:center;">
                <p class="responsive">Copyright &copy diVid3 2018</p>
            </div>
        </div>
        <!-- Add another div node here to better understand the 3 container flexbox use. -->
    </div>
</body>
</html>

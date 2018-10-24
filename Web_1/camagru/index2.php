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
// $_SESSION['loggedIn'] = 1;
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
        <!-- <div class="float-header-box" onclick="location.href='login.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='login.php'><p class="responsive">Log In</p></a>
            </div>
        </div> -->
    </div>
    <!-- This invisible div is used to push the body down so the body aligns with the floating navbar. -->
    <div id="body-push">
    </div>
    <!-- Actual body div -->
    <div>
        <p class="responsive">Lorem ipsum dolor sit amet, consectetur adipisicing elit. Soluta laborum perspiciatis aut, quibusdam recusandae eveniet fuga facere eos. Natus esse rem ipsa temporibus, enim earum deleniti officiis culpa qui autem.</p><br>
        <p class="responsive">Lorem ipsum dolor sit amet consectetur adipisicing elit. Molestias impedit, numquam facilis aliquam magni excepturi veniam fuga at, expedita magnam est vel veritatis eligendi, error dicta eos beatae repellendus ut.</p><br>
        <p class="responsive">Lorem ipsum dolor sit amet consectetur adipisicing elit. Molestias impedit, numquam facilis aliquam magni excepturi veniam fuga at, expedita magnam est vel veritatis eligendi, error dicta eos beatae repellendus ut.</p><br>
        <p class="responsive">Lorem ipsum dolor sit amet consectetur adipisicing elit. Molestias impedit, numquam facilis aliquam magni excepturi veniam fuga at, expedita magnam est vel veritatis eligendi, error dicta eos beatae repellendus ut.</p>
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
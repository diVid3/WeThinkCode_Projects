<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/usercheck.php');

if (isset($_SESSION['username']) == false && isset($_SESSION['password']) == false &&
isset($_SESSION['email']) == false && isset($_SESSION['notification']) == false) {
    header('Location: ' . catPathToString('take_photo_sign_in.php'));
    exit;
}
// if (isset($_SESSION['username']) == false && isset($_SESSION['password']) == false && isset($_SESSION['email']) == false) {
//     header('Location: ' . catPathToString('take_photo_sign_in.php'));
//     exit;
// }
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Camagru</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/take_photo.css"/>
</head>
<body>
    <!-- Modal markup -->
    <div id="formModal" class="modal">
        <div id="modalRow" class="modal-row">
            <div class="modal-column">
                <p class="modalHeader" id="modalHeader">Get a pic first</p><br>
                <p class="errorModal" id="modalText">You need to either take a pic first or upload a png image before attempting to save it.</p><br>
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
                <a href='edit_profile.php' id="nav4href" class="click" style="display:inline-block;" onclick="location.href='edit_profile.php';" style="cursor:pointer;text-align:center;">
                    <p id="nav4text">Edit profile</p>
                </a>
            </div>
        </div>
        <div class="header-box">
            <div style="text-align:center;display:inline-block;">
                <a href='sign_out.php' id="nav5href" class="click" style="display:inline-block;" onclick="location.href='sign_out.php';" style="cursor:pointer;text-align:center;">
                    <p id="nav5text">Sign out</p>
                </a>
            </div>
        </div>
    </header>
    <div class="push-content">
    </div>
    <div class="content">
        <div class="content-flex-child" id="videoDiv" style="position:relative;">
            <video id="video" style="flex-grow:1;width:50%;">Stream not active</video>
            <!-- <img id="sticker1" src="img/none.png" style="position:absolute;width:78.25%;height:87.46%;left:10.85%;"> -->
        </div>
        <div class="content-flex-child" id="canvasDiv" style="position:relative;">
            <canvas id="canvas" style="flex-grow:1;width:50%;"></canvas>
            <!-- <img id="sticker2" src="img/none.png" style="position:absolute;width:100%;height:87.46%;left:0%;"> -->
        </div>
        <div class="content-flex-child">
            <select id="stickers">
                <option value="img/none.png">None</option>
                <option value="img/daway.png">daway</option>
                <option value="img/heartbreak.png">heartbreak</option>
                <option value="img/minecraft.png">minecraft</option>
                <option value="img/cod4.png">cod4</option>
            </select>
        </div>
        <div class="content-flex-child">
            <button id="takePicButton" style="flex-grow: 1;">Take pic</button>
        </div>
        <div class="content-flex-child">
            <button id="clearButton" style="flex-grow: 1;">Clear</button>
        </div>
        <!-- <form enctype="multipart/form-data" action="uploadPic.php" method="post">
            <input id="uploadButton" type="file">
            <input type="submit" value="uploadedImage" name="submit">
        </form> -->
        <div class="content-flex-child" style="text-align:center;">
            <!-- <input type="file" id="uploadFile" style="flex-grow: 1; width:5%;"> -->
            <label id="uploadButtonContainer">
                <input type="file" id="uploadButton"/>
                    Upload pic
            </label>
        </div>
        <div class="content-flex-child">
            <button id="saveButton" style="flex-grow: 1;">Save pic</button>
        </div>
        <div class="content-flex-child">
            <div id="picture" style="flex-grow: 1;"></div>
        </div>
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
        <p>Click on a thumbnail to delete a picture</p>
        <div class="userPictureGallery" id="userPictureGallery1">
            <?php
                try {
                    $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
                    $query2 = 'SELECT `id`, `picture` FROM `pictures` WHERE `username` = ?';
                    $PDO = connectDBMS();
                    $PDO->query($query1);
                    $stmt = $PDO->prepare($query2);
                    $stmt->execute([$_SESSION['username']]);
                    $rowArr = $stmt->fetchAll(PDO::FETCH_ASSOC);
                }
                catch (PDOexception $e) {
                    error_log($e);
                }
                foreach($rowArr as $row) {
                    $pictureID = $row['id'];
                    $encodedPicture = $row['picture'];
                    echo '<img src="' . $encodedPicture . '" ' . 'class="userPicture" ' . 'id="userPic' . $pictureID . '" ' . 'onclick="delUserPic(this)" ' . '/>';
                }
            ?>
        </div>
    </div>
    <footer class="footer">
        <div class="footer-box">
            <div style="text-align:center;">
                <p>Copyright | diVid3 2018</p>
            </div>
        </div>
    </footer>
    <!-- JS source here -->
    <script src="js/take_photo.js"></script>
</body>
</html>

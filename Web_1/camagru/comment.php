<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/usercheck.php');
if (isset($_SESSION['username']) == false && isset($_SESSION['password']) == false && isset($_SESSION['email']) == false) {
    header('Location: ' . catPathToString('take_photo_sign_in.php?comment=true'));
    exit;
}
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Camagru</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/comment.css"/>
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
        <div class="content-flex-child">
            <!-- Need to move php tags otherwise multiple DB connections -->
            <?php
                require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
                require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
                require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');
                require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/usercheck.php');

                if (isset($_GET['pictureID']) == true)
                    $pictureID = $_GET['pictureID'];
                else {
                    header('Location: ' . catPathToString('gallery.php'));
                    // error_log('comment.php - pictureID invalid.');
                    exit;
                }
                if ($pictureID <= 0) {
                    header('Location: ' . catPathToString('gallery.php'));
                    // header('Location: ' . catPathToString('pageDoesNotExist.html'));
                    exit;
                }

                try { 
                    $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
                    $query2 = 'SELECT `picture` FROM `pictures` WHERE `id` = ?';
                    $PDO = connectDBMS();
                    $PDO->query($query1);
                    $stmt = $PDO->prepare($query2);
                    $stmt->execute([$pictureID]);
                    if ($stmt->rowCount() == 0) {
                        header('Location: ' . catPathToString('gallery.php'));
                        // header('Location: ' . catPathToString('pageDoesNotExist.php'));
                        exit;
                    }
                    $rowArr = $stmt->fetch(PDO::FETCH_ASSOC);
                    $encodedPicture = $rowArr['picture'];
                }
                catch (PDOexception $e) {
                    error_log($e);
                    exit;
                }

                echo '<div>';
                echo '<img src="' . $encodedPicture . '" ' . 'class="commentPicture">'; 
                echo '</div>';
            ?>
        </div>
        <div class="content-flex-child">
            <!-- Need to let JS ajax the like -->
            <button style="flex-grow: 1;" onclick="addLikeToPic(this, $pictureID); this.onclick=null;">Like</button>
        </div>
        <div class="content-flex-child">
            <?php
                
            ?>
        </div>
        <div class="content-flex-child">hi</div>
        <div class="content-flex-child">hi</div>
        <div class="content-flex-child">hi</div>
        <div class="content-flex-child">hi</div>
        <!-- <div class="content-flex-child" id="videoDiv" style="position:relative;">
            <video id="video" style="flex-grow:1;width:50%;">Stream not active</video>
        </div>
        <div class="content-flex-child" id="canvasDiv" style="position:relative;">
            <canvas id="canvas" style="flex-grow:1;width:50%;"></canvas>
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
        <div class="content-flex-child" style="text-align:center;">
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
        </div> -->
    </div>
    <footer class="footer">
        <div class="footer-box">
            <div style="text-align:center;">
                <p>Copyright | diVid3 2018</p>
            </div>
        </div>
    </footer>
    <!-- JS source here -->
    <script src="js/comment.js"></script>
</body>
</html>

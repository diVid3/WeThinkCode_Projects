<?php
session_start();
require_once ('inc/errors.php');
require_once ('inc/connect.php');
require_once ('inc/initialize.php');
require_once ('inc/usercheck.php');
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
        <?php
            echo '<div class="content-flex-child">';
                require_once ('inc/errors.php');
                require_once ('inc/connect.php');
                require_once ('inc/initialize.php');
                require_once ('inc/usercheck.php');

                if (isset($_GET['pictureID']) == true)
                    $pictureID = $_GET['pictureID'];
                else {
                    header('Location: ' . catPathToString('gallery.php'));
                    exit;
                }
                if ($pictureID <= 0) {
                    header('Location: ' . catPathToString('gallery.php'));
                    exit;
                }

                try { 
                    $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
                    $query2 = 'SELECT * FROM `pictures` WHERE `id` = ?';
                    $PDO = connectDBMS();
                    $PDO->query($query1);
                    $stmt = $PDO->prepare($query2);
                    $stmt->execute([$pictureID]);
                    if ($stmt->rowCount() == 0) {
                        header('Location: ' . catPathToString('gallery.php'));
                        exit;
                    }
                    $table = $stmt->fetchAll(PDO::FETCH_ASSOC);
                    $encodedPicture = $table[0]['picture'];
                }
                catch (PDOexception $e) {
                    error_log($e);
                    exit;
                }

                echo '<div>';
                    echo '<img src="' . $encodedPicture . '" ' . 'class="commentPicture">'; 
                echo '</div>';
            echo '</div>';
            echo '<div class="content-flex-child">';
                $likesArr = unserialize($table[0]['likes']);
                $likes = count($likesArr);
                echo '<p id="picNumLikes">' . ($likes - 1) . '</p>';
            echo '</div>';
            echo '<div class="content-flex-child">';
                echo '<button style="flex-grow: 1;" onclick="addLikeToPic(this, ' . $pictureID . '); this.onclick=null;">Like</button>';
            echo '</div>';
            $commentsArr = unserialize($table[0]['comments']);
            echo '<div>';
                echo '<table id="commentTable">';
                    echo '<tr>';
                        echo '<th><p>Username:</p></th>';
                        echo '<th><p>Comment:</p></th>';
                    echo '</tr>';
                    $dummyCommentSkip = 0;
                    foreach ($commentsArr as $element) {
                        if ($dummyCommentSkip == 0) {
                            $dummyCommentSkip++;
                            continue;
                        }
                        echo '<tr>';
                        echo '<td><p>' . htmlspecialchars($element[0]) . '</p></td>';
                        echo '<td><p>' . htmlspecialchars($element[1]) . '</p></td>';
                        echo '</tr>';
                    }
                echo '</table>';
            echo '</div>';
            echo '<div>';
                echo '<input id="commentBox" placeholder="Comment here...">';
                echo '<form id="usrform">';
                    echo '<input type="submit" onclick="addCommentToPic(event, ' . $pictureID . ');">';
                echo '</form>';
                echo '<br>';
            echo '</div>';
        ?>
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

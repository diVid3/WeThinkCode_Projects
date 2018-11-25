<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/usercheck.php');
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
    <?php
    echo '<div class="content">';
        echo '<div class="galleryWrapper">';
            try {
                $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
                $query2 = 'SELECT * FROM `pictures`';
                $PDO = connectDBMS();
                $PDO->query($query1);
                $stmt = $PDO->prepare($query2);
                $stmt->execute();
                $rowCount = $stmt->rowCount(); // Number of pictures in pictures table.
            }
            catch (PDOexception $e) {
                error_log($e);
                exit;
            }
            $resultsPerPage = 10; // Results of pictures to display per page.
            if (isset($_GET['page']) == false)
                $page = 1;
            else
                $page = $_GET['page'];
            $numberOfPages = ceil($rowCount / $resultsPerPage);
            if ($page > $numberOfPages || $page < 0)
                $page = 1;
            try {
                $startLimitNumber = ($page - 1) * $resultsPerPage;
                $query2 = 'SELECT * FROM `pictures` ORDER BY `id` DESC LIMIT ' . $startLimitNumber . ',' . $resultsPerPage . ';';
                $stmt = $PDO->prepare($query2);
                $stmt->execute();
                $rowArr = $stmt->fetchAll(PDO::FETCH_ASSOC); // Associative array of pictures.
            }
            catch (PDOexception $e) {
                error_log($e);
                exit;
            }
            foreach($rowArr as $row) {
                $pictureID = $row['id'];
                $encodedPicture = $row['picture'];
                echo '<div>';
                echo '<img src="' . $encodedPicture . '" ' . 'class="galleryPicture" ' . 'id="galleryPic' . $pictureID . '" ' . '/>';
                // echo '<img src="' . $encodedPicture . '" ' . 'class="userPicture" ' . 'id="userPic' . $pictureID . '" ' . 'onclick="delUserPic(this)" ' . '/>';
                echo '</div>';
            }
        echo '</div>';
    echo '</div>';
    echo '<div style="text-align: center;padding: 10px;background-color: #eee;">';
    $pathToThisPage = catPathToString('gallery.php');
    for ($page = 1; $page <= $numberOfPages; $page++)
        echo '<a href="' . $pathToThisPage . '?page=' . $page . '" ' . 'class="pageLink"' . '>' . '<p style="display: inline-block;margin-left: 10px;margin-right: 10px;">' . $page . '</p>' . '</a>';
    echo '</div>';
    ?>
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

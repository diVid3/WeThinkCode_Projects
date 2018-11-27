<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/usercheck.php');

if (isset($_SESSION['username']) == false || isset($_SESSION['password']) == false ||
isset($_SESSION['email']) == false || isset($_SESSION['notification']) == false)
    exit;

// Function to merge a picture with a sticker, writes to file. $imgURL is a base64 string.
function mergePictures($imgURL, $stickerPath) {
    try {
        $imgURL = str_replace('data:image/png;base64,', '', $imgURL);
        $imgURL = str_replace(' ', '+', $imgURL);
        file_put_contents('picture.png', base64_decode($imgURL));
        $picture = imagecreatefrompng('picture.png');
        $sticker = imagecreatefrompng($stickerPath);
        imagecolortransparent($sticker, imagecolorat($sticker, 0, 0));
        imagecopymerge($picture, $sticker, 0, 0, 0, 0, imagesx($sticker), imagesx($sticker), 100);
        imagepng($picture, 'fused.png');
        imagedestroy($picture);
        imagedestroy($sticker);
        unlink('picture.png');
    }
    catch (Exception $e) {
        error_log($e);
        $json = ['creationError' => 1];
        echo json_encode($json);
        exit;
    }
}

function storeFusedPicture() {
    global $DB_DATABASE_NAME;
    try {
        $username = $_SESSION['username'];
        $email = $_SESSION['email'];
        $notification = $_SESSION['notification'];
        // $commentsArr = [['dummyUsername', 'dummyComment']];
        $commentsArr = [['', '']];
        $comments = serialize($commentsArr);
        // $likesArr = ['dummyUsername'];
        $likesArr = [''];
        $likes = serialize($likesArr);
        $type = pathinfo('fused.png', PATHINFO_EXTENSION);
        $data = file_get_contents('fused.png');
        $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
        unlink('fused.png');
        $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
        $query2 = 'INSERT INTO `pictures` (`username`, `email`, `notification`, `comments`, `likes`, `picture`) VALUES (?,?,?,?,?,?)';
        $PDO = connectDBMS();
        $PDO->query($query1);
        $stmt = $PDO->prepare($query2);
        $stmt->execute([$username, $email, $notification, $comments, $likes, $base64]);
        $json = ['creationSuccess' => 1, 'doneSavingPic' => 1];
        echo json_encode($json);
    }
    catch (PDOexception $e) {
        error_log($e);
        $json = ['creationError' => 1];
        echo json_encode($json);
        exit;
    }
}

// Merge picture and stickers. These activate when a picture was taken via webcam.
if (isset($_POST['imgURL']) == true && isset($_POST['sticker2']) == true &&
isset($_POST['sticker4']) == true && isset($_POST['sticker6']) == true && isset($_POST['sticker8']) == true) {
    mergePictures($_POST['imgURL'], $_POST['sticker2']);
    $type = pathinfo('fused.png', PATHINFO_EXTENSION);
    $data = file_get_contents('fused.png');
    $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
    mergePictures($base64, $_POST['sticker4']);
    $type = pathinfo('fused.png', PATHINFO_EXTENSION);
    $data = file_get_contents('fused.png');
    $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
    mergePictures($base64, $_POST['sticker6']);
    $type = pathinfo('fused.png', PATHINFO_EXTENSION);
    $data = file_get_contents('fused.png');
    $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
    mergePictures($base64, $_POST['sticker8']);
    storeFusedPicture();
}
else if (isset($_POST['imgURL']) == true && isset($_POST['sticker2']) == true &&
isset($_POST['sticker4']) == true && isset($_POST['sticker6']) == true) {
    mergePictures($_POST['imgURL'], $_POST['sticker2']);
    $type = pathinfo('fused.png', PATHINFO_EXTENSION);
    $data = file_get_contents('fused.png');
    $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
    mergePictures($base64, $_POST['sticker4']);
    $type = pathinfo('fused.png', PATHINFO_EXTENSION);
    $data = file_get_contents('fused.png');
    $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
    mergePictures($base64, $_POST['sticker6']);
    storeFusedPicture();
}
else if (isset($_POST['imgURL']) == true && isset($_POST['sticker2']) == true &&
isset($_POST['sticker4']) == true) {
    mergePictures($_POST['imgURL'], $_POST['sticker2']);
    $type = pathinfo('fused.png', PATHINFO_EXTENSION);
    $data = file_get_contents('fused.png');
    $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
    mergePictures($base64, $_POST['sticker4']);
    storeFusedPicture();
}
else if (isset($_POST['imgURL']) == true && isset($_POST['sticker2']) == true) {
    mergePictures($_POST['imgURL'], $_POST['sticker2']);
    storeFusedPicture();
}

// Merge picture and stickers. These activate when a picture was uploaded.
else if (isset($_POST['formData']) == true && isset($_FILES['uploadPicture']) == true) {
    try {
        $valid = array(IMAGETYPE_PNG);
        $picture = $_FILES['uploadPicture'];
        $dest = $_SERVER['DOCUMENT_ROOT'] . '/' . $picture['name'];
        $imageInfo = @getimagesize($picture['tmp_name']);
        if (!$imageInfo || !is_array($imageInfo)) {
            $json = ['uploadError' => 1, 'uploadErrorMsg' => 'The only image type that\'s supported is .png'];
            echo json_encode($json);
            exit;
        }
        if (!isset($imageInfo[2]) || !in_array($imageInfo[2], $valid) || !is_readable($picture['tmp_name'])) {
            $json = ['uploadError' => 1, 'uploadErrorMsg' => 'Invalid format or image is not readable'];
            echo json_encode($json);
            exit;
        }
        if (!move_uploaded_file($picture['tmp_name'], $dest)) {
            $json = ['uploadError' => 1, 'uploadErrorMsg' => 'Error in uploading file'];
            echo json_encode($json);
            exit;
        }
    }
    catch (Exception $e) {
        error_log($e);
        $json = ['creationError' => 1];
        echo json_encode($json);
        exit;
    }
    if (isset($_POST['sticker2']) == true && isset($_POST['sticker4']) == true &&
    isset($_POST['sticker6']) == true && isset($_POST['sticker8']) == true) {
        $type = pathinfo($picture['name'], PATHINFO_EXTENSION);
        $data = file_get_contents($picture['name']);
        $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
        mergePictures($base64, $_POST['sticker2']);
        $type = pathinfo('fused.png', PATHINFO_EXTENSION);
        $data = file_get_contents('fused.png');
        $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
        mergePictures($base64, $_POST['sticker4']);
        $type = pathinfo('fused.png', PATHINFO_EXTENSION);
        $data = file_get_contents('fused.png');
        $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
        mergePictures($base64, $_POST['sticker6']);
        $type = pathinfo('fused.png', PATHINFO_EXTENSION);
        $data = file_get_contents('fused.png');
        $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
        mergePictures($base64, $_POST['sticker8']);
        storeFusedPicture();
        unlink($picture['name']);
    }
    else if (isset($_POST['sticker2']) == true && isset($_POST['sticker4']) == true &&
    isset($_POST['sticker6']) == true) {
        $type = pathinfo($picture['name'], PATHINFO_EXTENSION);
        $data = file_get_contents($picture['name']);
        $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
        mergePictures($base64, $_POST['sticker2']);
        $type = pathinfo('fused.png', PATHINFO_EXTENSION);
        $data = file_get_contents('fused.png');
        $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
        mergePictures($base64, $_POST['sticker4']);
        $type = pathinfo('fused.png', PATHINFO_EXTENSION);
        $data = file_get_contents('fused.png');
        $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
        mergePictures($base64, $_POST['sticker6']);
        storeFusedPicture();
        unlink($picture['name']);
    }
    else if (isset($_POST['sticker2']) == true && isset($_POST['sticker4']) == true) {
        $type = pathinfo($picture['name'], PATHINFO_EXTENSION);
        $data = file_get_contents($picture['name']);
        $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
        mergePictures($base64, $_POST['sticker2']);
        $type = pathinfo('fused.png', PATHINFO_EXTENSION);
        $data = file_get_contents('fused.png');
        $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
        mergePictures($base64, $_POST['sticker4']);
        storeFusedPicture();
        unlink($picture['name']);
    }
    else if (isset($_POST['sticker2']) == true) {
        $type = pathinfo($picture['name'], PATHINFO_EXTENSION);
        $data = file_get_contents($picture['name']);
        $base64 = 'data:image/' . $type . ';base64,' . base64_encode($data);
        mergePictures($base64, $_POST['sticker2']);
        storeFusedPicture();
        unlink($picture['name']);
    }
}
?>

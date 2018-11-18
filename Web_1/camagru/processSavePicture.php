<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');
if (isset($_SESSION['username']) == false && isset($_SESSION['password']) == false &&
    isset($_SESSION['email']) == false)
    exit;

 // If-else logic to create picture either taken or uploaded.
if (isset($_POST['imgURL']) == true && isset($_POST['stickerPath']) == true) {
    try {
        $imgURL = $_POST['imgURL'];
        $stickerPath = $_POST['stickerPath'];
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
        $json = ['creationSuccess' => 1];
        echo json_encode($json);
    }
    catch (Exception $e) {
        error_log($e);
    }
    // Need to add to db here.
}
else if (isset($_POST['formData']) == true && isset($_POST['stickerPath']) == true &&
    isset($_FILES['uploadPicture']) == true) {
    try {
        $valid = array(IMAGETYPE_PNG);
        $picture = $_FILES['uploadPicture'];
        $dest = $_SERVER['DOCUMENT_ROOT'] . '/uploads/' . $picture['name'];
        $stickerPath = $_POST['stickerPath'];
        $imageInfo = @getimagesize($picture['tmp_name']);
        // File checks before file move.
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
        $pictureUploaded = imagecreatefrompng($_SERVER['DOCUMENT_ROOT'] . '/uploads/' . $picture['name']);
        $sticker = imagecreatefrompng($stickerPath);
        imagecolortransparent($sticker, imagecolorat($sticker, 0, 0));
        imagecopymerge($pictureUploaded, $sticker, 0, 0, 0, 0, imagesx($sticker), imagesx($sticker), 100);
        imagepng($pictureUploaded, 'fused.png');
        imagedestroy($pictureUploaded);
        imagedestroy($sticker);
        $json = ['creationSuccess' => 1];
        echo json_encode($json);
        unlink($dest);
    }
    catch (Exception $e) {
        error_log($e);
    }
    // Need to add to db here.
}
else {
    $json = ['creationError' => 1];
    echo json_encode($json);
}
?>

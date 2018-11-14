<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');
if (isset($_SESSION['username']) == false && isset($_SESSION['password']) == false && isset($_SESSION['email']) == false) {
    // header("Location: http://127.0.0.1:8080/take_photo_sign_in.php");
    exit;
}

function mergeImages($imageEncoded, $stickerPath) {
    file_put_contents('picture.png', base64_decode($imageEncoded));
    $picture = imagecreatefrompng('picture.png');
    $sticker = imagecreatefrompng($stickerPath);
    imagecopymerge($picture, $sticker, 0, 0, 0, 0);
}
?>

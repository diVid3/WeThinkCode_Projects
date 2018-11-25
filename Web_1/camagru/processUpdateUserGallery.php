<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/usercheck.php');

try {
    $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
    $query2 = 'SELECT `id`, `picture` FROM `pictures` WHERE `username` = ? ORDER BY `id` DESC LIMIT 1';
    $PDO = connectDBMS();
    $PDO->query($query1);
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$_SESSION['username']]);
    $rowArr = $stmt->fetch(PDO::FETCH_ASSOC);
}
catch (PDOexception $e) {
    error_log($e);
    $json = ['updateUserGalleryFail' => 1];
    echo json_encode($json);
    exit;
}

$pictureID = $rowArr['id'];
$encodedPicture = $rowArr['picture'];
$json = ['gotNewestPic' => 1, 'pictureID' => $pictureID, 'encodedPicture' => $encodedPicture];
echo json_encode($json);
exit;
?>

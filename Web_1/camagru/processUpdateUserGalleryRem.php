<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/usercheck.php');

try {
    $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
    $query2 = 'DELETE FROM `pictures` WHERE `id` = ?';
    $PDO = connectDBMS();
    $PDO->query($query1);
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$_POST['pictureID']]);
}
catch (PDOexception $e) {
    error_log($e);
    $json = ['updateUserGalleryRemFail' => 1];
    echo json_encode($json);
    exit;
}

$json = ['deletedPicture' => 1];
echo json_encode($json);
exit;
?>

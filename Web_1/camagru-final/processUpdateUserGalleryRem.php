<?php
session_start();
require_once ('inc/errors.php');
require_once ('inc/connect.php');
require_once ('inc/initialize.php');
require_once ('inc/usercheck.php');

if (isset($_POST['pictureID']) == false)
    exit;

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

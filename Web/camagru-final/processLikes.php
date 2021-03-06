<?php
session_start();
require_once ('inc/errors.php');
require_once ('inc/connect.php');
require_once ('inc/initialize.php');
require_once ('inc/usercheck.php');

if (isset($_SESSION['username']) == false || isset($_SESSION['password']) == false ||
isset($_SESSION['email']) == false || isset($_SESSION['notification']) == false)
    exit;

if (isset($_POST['addLikeToPic']) == false || isset($_POST['pictureID']) == false)
    exit;

// Getting DB username because emoji's force case insensitivity on DB. Volvo plez fix.

try {
    $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
    $query2 = 'SELECT `username` FROM `users` WHERE `username` = ?';
    $PDO = connectDBMS();
    $PDO->query($query1);
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$_SESSION['username']]);
    $rowArr = $stmt->fetch(PDO::FETCH_ASSOC);
}
catch (PDOexception $e) {
    error_log($e);
    exit;
}

$pictureID = $_POST['pictureID'];
$username = $rowArr['username'];

try {
    $query2 = 'SELECT * FROM `pictures` WHERE `id` = ?';
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$pictureID]);
    $table = $stmt->fetchAll(PDO::FETCH_ASSOC);

}
catch (PDOexception $e) {
    error_log($e);
    exit;
}

if ($stmt->rowCount() == 0) {
    $json = ['noPicID' => 1];
    echo json_encode($json);
    exit;
}

$likesArr = unserialize($table[0]['likes']);

if (in_array($username, $likesArr) == true) {
    $json = ['updateLikes' => 0];
    echo json_encode($json);
    exit;
}

$likesArr[] = $username;
$serializedLikesArr = serialize($likesArr);

try {
    $query2 = 'UPDATE `pictures` SET `likes` = ? WHERE `id` = ?';
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$serializedLikesArr, $pictureID]);
}
catch (PDOexception $e) {
    error_log($e);
    exit;
}

// Need to send Email notification here.

try {
    $query2 = 'SELECT `notification` FROM `users` WHERE `username` = ?';
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$table[0]['username']]);
    $rowArr = $stmt->fetch(PDO::FETCH_ASSOC);
}
catch (PDOexception $e) {
    error_log($e);
    exit;
}

if ($rowArr['notification'] == 1) {
    $to = $table[0]['email'];
    $subject = 'Camagru | Like Notification';
    $message = 'You received a like on one of your pictures!';
    mail($to, $subject, $message);
}

$json = ['updateLikes' => 1];
echo json_encode($json);
?>

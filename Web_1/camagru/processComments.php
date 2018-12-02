<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/initialize.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/usercheck.php');

if (isset($_SESSION['username']) == false || isset($_SESSION['password']) == false ||
isset($_SESSION['email']) == false || isset($_SESSION['notification']) == false)
    exit;

if (isset($_POST['commentBoxUsernameValue']) == false || isset($_POST['commentBoxValue']) == false ||
isset($_POST['pictureID']) == false)
    exit;

$pictureID = $_POST['pictureID'];
$commentBoxUsernameValue = $_POST['commentBoxUsernameValue'];
$commentBoxValue = $_POST['commentBoxValue'];

if ($commentBoxUsernameValue === '' || $commentBoxValue === '') {
    $json = ['updateComments' => 0];
    echo json_encode($json);
    exit;
}

try {
    $query1 = 'USE ' . $DB_DATABASE_NAME . ';';
    $query2 = 'SELECT * FROM `pictures` WHERE `id` = ?';
    $PDO = connectDBMS();
    $PDO->query($query1);
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$pictureID]);
    // $rowArr = $stmt->fetch(PDO::FETCH_ASSOC);
    $table = $stmt->fetchAll(PDO::FETCH_ASSOC);
}
catch (PDOexception $e) {
    error_log($e);
    exit;
}

$commentsArr = unserialize($table[0]['comments']);

$newComment = [$commentBoxUsernameValue, $commentBoxValue];
$commentsArr[] = $newComment;

$serializedCommentsArr = serialize($commentsArr);

try {
    $query2 = 'UPDATE `pictures` SET `comments` = ? WHERE `id` = ?';
    $stmt = $PDO->prepare($query2);
    $stmt->execute([$serializedCommentsArr, $pictureID]);
}
catch (PDOexception $e) {
    error_log($e);
    exit;
}

// Checking if email notifications are enabled. If so, sending email notification.

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
    $subject = 'Camagru | Comment Notification';
    $message = 'You received a comment on one of your pictures!';
    mail($to, $subject, $message);
}

$json = ['updateComments' => 1];
echo json_encode($json);

?>

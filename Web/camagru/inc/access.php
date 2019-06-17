<?php
$string = $_SERVER['HTTP_USER_AGENT'];
if (strpos($string, 'Chrome') !== false ||
strpos($string, 'Firefox') !== false || strpos($string, 'Safari') !== false) {
    header('HTTP/1.1 403 Forbidden');
    echo 'You are forbidden!';
    exit;
}
?>

<?php
if (file_exists('initialized.txt') == false) {
    require_once ('config/setup.php');
    $initFile = fopen('initialized.txt', 'w');
    fclose($initFile);
}
if (file_exists('errors.log') == false) {
    $errorLog = fopen('errors.log', 'w');
    fclose($errorLog);
}
?>

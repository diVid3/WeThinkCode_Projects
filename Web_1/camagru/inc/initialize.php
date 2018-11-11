<?php
if (file_exists($_SERVER['DOCUMENT_ROOT'] . '/initialized.txt') == false) {
    require_once ($_SERVER['DOCUMENT_ROOT'] . '/config/setup.php');
    $initFile = fopen($_SERVER['DOCUMENT_ROOT'] . '/initialized.txt', 'w');
    fclose($initFile);
}
if (file_exists($_SERVER['DOCUMENT_ROOT'] . '/errors.log') == false) {
    $errorLog = fopen($_SERVER['DOCUMENT_ROOT'] . '/errors.log', 'w');
    fclose($errorLog);
}
?>

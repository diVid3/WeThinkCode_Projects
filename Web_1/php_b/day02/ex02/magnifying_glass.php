#!/usr/bin/php
<?php

if ($argc != 2)
    exit(0);
function modString($match_arr) {
    print_r($match_arr);
    $subStrUp = strtoupper($match_arr[1]);
    $modLine = str_replace($match_arr[1], $subStrUp, $match_arr[0]);
    return ($modLine);
}
$fd = fopen($argv[1], "r");
$lineOrig = 1;
while ($lineOrig)
{
    $lineOrig = fgets($fd);
    $lineModTitle = preg_replace_callback('/<a.*?title="(.*?)">/', 'modString', $lineOrig);
    $lineModRef = preg_replace_callback('/<a href=.*?>(.*?)</', 'modString', $lineModTitle);
    echo $lineModRef;
}

?>

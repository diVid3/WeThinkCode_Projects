#!/usr/bin/php
<?php

if ($argc == 1)
    exit(0);
$arr = array_filter(explode(" ", $argv[1]));
$cntr = 0;
while (++$cntr < count($arr))
    $str = $str."$arr[$cntr] ";
$str = $str."$arr[0] ";
$str = trim($str);
echo "$str";
echo "\n";

?>
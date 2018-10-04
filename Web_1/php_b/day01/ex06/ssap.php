#!/usr/bin/php
<?php

if ($argc == 1)
    exit(0);
$arr_final = array();
$arr_temp = array();
foreach ($argv as $val)
{
    if ($val === $argv[0])
        continue;
    $arr_temp = $str = array_filter(explode(" ", $val));
    foreach ($arr_temp as $val)
        $arr_final[] = $val;
}
sort($arr_final);
foreach ($arr_final as $val)
    echo "$val\n";

?>
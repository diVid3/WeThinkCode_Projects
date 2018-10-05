#!/usr/bin/php
<?php

date_default_timezone_set("Europe/Paris");
$day_arr = [
    NULL,
    "lundi",
    "mardi",
    "mercredi",
    "jeudi",
    "vendredi",
    "samedi",
    "dimamche",
];

$month_arr = [
    NULL,
    "janvier",
    "février",
    "mars",
    "avril",
    "mai",
    "juin",
    "juillet",
    "aout",
    "septembre",
    "octobre",
    "novembre",
    "décembre",
];

if (preg_match('/^([a-zA-Z]+) ([0-9]{1,2}) ([a-zA-Z]+) ([0-9]{4}) ([0-1][0-9]|[2][0-3]):([0-5][0-9]):([0-5][0-9])$/', $argv[1], $match_arr))
{
    $day_found = array_search(strtolower($match_arr[1]), $day_arr);
    $month_found = array_search(strtolower($match_arr[3]), $month_arr);
    if ($day_found == false || $month_found == false || $match_arr[4] < 1970)
        exit("Wrong Format.\n");
    $time_sec = mktime($match_arr[5], $match_arr[6], $match_arr[7], $month_found, $match_arr[2], $match_arr[4]);
        exit($time_sec."\n");
}
exit("Wrong Format.\n");

?>

#!/usr/bin/php
<?php

function ft_is_sort($arr)
{
    $arr_cpy = array();
    foreach ($arr as $val)
        $arr_cpy[] = $val;
    sort($arr);
    $cntr = 0;
    $cntr_cpy = 0;
    while ($cntr < count($arr))
    {
        if ($arr[$cntr] !== $arr_cpy[$cntr_cpy])
            return (false);
        ++$cntr;
        ++$cntr_cpy;
    }
    return (true);
}

?>
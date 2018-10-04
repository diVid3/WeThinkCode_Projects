#!/usr/bin/php
<?php
    while (1)
    {
        echo "Enter a number: ";
        if (($num = fgets(STDIN)) == NULL)
        {
            echo "\n";
            break;
        }
        $num = trim($num);
        if (is_numeric($num) == false)
            echo "'$num' is not a number";
        else if ($num % 2 == 0)
            echo "The number $num is even";
        else
            echo "The number $num is odd";
        echo "\n";
    }
?>

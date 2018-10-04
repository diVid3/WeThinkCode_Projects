#!/usr/bin/php
<?php

foreach ($argv as $val)
    if ($val !== $argv[0])
        echo "$val\n";

?>
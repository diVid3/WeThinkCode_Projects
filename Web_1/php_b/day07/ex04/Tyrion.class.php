<?php
class Tyrion {
    public function sleepWith($var) {
        if (is_a($var, 'Jaime'))
            echo "Not even if I'm drunk !" . PHP_EOL;
        else if (is_a($var, 'Sansa'))
            echo "Let's do this." . PHP_EOL;
        else if (is_a($var, 'Cersei'))
            echo "Not even if I'm drunk !" . PHP_EOL;
    }
}
?>
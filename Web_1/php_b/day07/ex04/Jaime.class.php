<?php
class Jaime {
    public function sleepWith($var) {
        if (is_a($var, 'Tyrion'))
            echo "Not even if I'm drunk !" . PHP_EOL;
        else if (is_a($var, 'Sansa'))
            echo "Let's do this." . PHP_EOL;
        else if (is_a($var, 'Cersei'))
            echo "With pleasure, but only in a tower in Winterfell, then." . PHP_EOL;
    }
}
?>
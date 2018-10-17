<?php
class NightsWatch {
    static $arr = array();
    public function recruit($obj) {
        $this->$arr[] = $obj;
    }
    public function fight() {
        foreach ($this->$arr as $obj)
            if (method_exists($obj, "fight"))
                $obj->fight();
    }
}
?>
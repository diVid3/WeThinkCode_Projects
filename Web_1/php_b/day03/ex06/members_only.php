<?php
if ($_SERVER["PHP_AUTH_USER"] != "zaz" || $_SERVER["PHP_AUTH_PW"] != "jaimelespetitsponeys") {
    header("HTTP/1.0 401 Unauthorized");
    echo "<html><body>That area is accessible for members only</body></html>\n";
}
else {
    $image = file_get_contents("../img/42.png");
    $image_enc = base64_encode($image);
    echo "<html><body>\n";
    echo "Hello Zaz<br />\n";
    echo "<img src='data:image/png;base64,$image_enc'>\n";
    echo "</body></html>\n";
}
?>
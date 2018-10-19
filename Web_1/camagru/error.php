<?php
    session_start();
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Error</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="main.css" />
    <script src="main.js"></script>
</head>
<body style="background-color:crimson; color:black;">
    <?php
    echo ($_SESSION['errorMsg']);
    echo '<br/>';
    $e = unserialize($_SESSION['errorObj']);
    $e->getMessage();
    echo '<br/>';
    ?>
</body>
</html>
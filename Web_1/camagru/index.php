<?php
session_start();
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/errors.php');
include_once ($_SERVER['DOCUMENT_ROOT'] . '/inc/connect.php');

if (file_exists('errors.log') == false) {
    $errorLog = fopen('errors.log', 'w');
    fclose($errorLog);
}
if (file_exists('initialized.txt') == false) {
    include_once ($_SERVER['DOCUMENT_ROOT'] . '/config/setup.php');
    $initFile = fopen('initialized.txt', 'w');
    fclose($initFile);
}
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Camagru</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/main.css"/>
</head>
<body>
    <header class="header">
        <div class="header-box" onclick="location.href='index.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='index.php'><p>Camagru</p></a>
            </div>
        </div>
        <div class="header-box" onclick="location.href='take_photo.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='take_photo.php'><p>Take a pic</p></a>
            </div>
        </div>
        <div class="header-box" onclick="location.href='gallery.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='gallery.php'><p>Gallery</p></a>
            </div>
        </div>
        <div class="header-box" onclick="location.href='sign_up.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='sign_up.php'><p>Sign up</p></a>
            </div>
        </div>
        <div class="header-box" onclick="location.href='login.php';" style="cursor: pointer;">
            <div style="text-align:center;">
                <a href='login.php'><p>Log in</p></a>
            </div>
        </div>
    </header>
    <div class="push-content">
    </div>
    <div class="content">
        <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Animi vero quam, nobis eaque quaerat perspiciatis doloremque corporis tempora repellendus. Itaque voluptatem esse placeat at iste vel, doloremque ut reprehenderit enim blanditiis accusantium consectetur animi atque accusamus, illo, sapiente dicta fugiat vero! Dignissimos veritatis earum odio laboriosam iure ab. Fugiat praesentium iure at similique consequuntur! Atque unde quidem impedit quis vel maxime aliquam nam quibusdam dolore rerum id voluptates eius natus architecto, nemo reprehenderit tempora et repellendus deleniti itaque neque alias. Dolorem quisquam ut iure et id voluptate laboriosam consectetur labore doloribus maxime! Expedita rerum ex ipsa eum, sed doloremque temporibus hic officia. Odio rem voluptate dolor quasi vero, doloribus inventore tenetur iusto adipisci non tempora cumque rerum quibusdam harum asperiores saepe. Voluptatum, id voluptas eos omnis, dicta repellat amet iste soluta animi modi, molestiae magni. Officiis, quod nobis vitae omnis eaque excepturi repellat quaerat distinctio labore tempora accusantium similique repudiandae sunt vel beatae minus, facilis culpa deserunt eligendi? Optio ab officiis distinctio recusandae quod, laborum eveniet aliquid placeat voluptatem quisquam rem ipsa ad minima non porro numquam beatae quasi, fugiat maiores laudantium ipsam debitis! Architecto ex molestias aperiam quo doloremque corrupti, fuga veniam quas delectus, porro minima debitis quasi voluptatibus, esse voluptas dolores odit laboriosam! Pariatur quibusdam vero animi non sint fugiat nulla, unde debitis enim sit aut rerum ipsa optio eaque modi eveniet explicabo autem odit quisquam voluptatem quidem perferendis architecto nihil. Dolor earum repellat blanditiis eos facere eligendi deserunt similique quisquam voluptate, odit reiciendis, iste commodi ducimus esse modi. Asperiores incidunt blanditiis accusantium nesciunt minus deleniti repudiandae doloremque dignissimos id sit ipsum ea, earum neque! Saepe neque dolore asperiores in nobis perferendis ea maiores, minus repellendus nulla rerum? Quaerat labore eligendi aspernatur reprehenderit perferendis, nostrum placeat error pariatur incidunt cumque? Numquam quaerat iste possimus. Officia, nulla! Quis recusandae unde porro saepe dicta delectus pariatur qui maiores eaque eveniet sequi nihil ab asperiores nostrum accusantium, reiciendis harum commodi laborum! Quis molestiae magnam facilis perspiciatis? Quasi rerum, nesciunt magnam quibusdam, eveniet atque vitae porro nulla incidunt dignissimos aperiam animi aliquam consectetur. Fugit perspiciatis facilis impedit sit consequatur molestias doloribus totam eius iure molestiae, ullam nobis minima cum ex sint natus? Adipisci aliquam ad tempore earum asperiores omnis in autem quos necessitatibus dolorem. Nihil laboriosam minima magni omnis, eum molestias cupiditate sint distinctio qui quae, assumenda natus nisi culpa hic! Alias animi quibusdam sint reiciendis ab molestiae totam quod dolore inventore voluptates deleniti repudiandae repellat error a earum nobis illo, harum maiores, dolorum dolorem commodi assumenda maxime voluptatum suscipit. Vero labore iste eaque praesentium, incidunt aperiam pariatur quos voluptas assumenda maiores necessitatibus laudantium commodi hic in sit laboriosam quas ducimus distinctio quidem quia eius accusamus totam inventore. Veniam repellat praesentium aliquam atque nisi esse, possimus non reprehenderit, eaque unde libero dolor! Vero, quo praesentium quod corrupti incidunt ex earum reiciendis amet nobis error officiis molestiae dignissimos labore blanditiis! Quidem, minus ex. Porro voluptatum ut fuga. Officia nisi ex velit odio, modi consectetur possimus animi atque asperiores accusamus? Voluptatem, vitae error. Iusto.</p>
    </div>
    <footer class="footer">
        <div class="footer-box">
            <div style="text-align:center;">
                <p>Copyright &copy diVid3 2018</p>
            </div>
        </div>
    </footer>
</body>
</html>
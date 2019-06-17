// Remember that this is relative to the file the browser is viewing.
function catPathToString(string) {
    var the_arr = window.location.href.split('/');
    the_arr.pop();
    return(the_arr.join('/') + '/' + string);
}

function commentPicture(element) {
    var string = element.id;
    var arr = string.split('galleryPic');
    var pictureID = arr[1];
    window.location.assign(catPathToString('comment.php?pictureID=' + pictureID));
}

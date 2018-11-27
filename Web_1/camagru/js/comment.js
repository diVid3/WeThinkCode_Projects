function addLikeToPic(element, pictureID) {
    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'processLikes.php', true);
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    xhr.onload = function() {
        var returnArr = JSON.parse(this.responseText);
        if (returnArr['updateLikes'] == 1)
            increaseLikes();
    }
    xhr.send('addLikeToPic=true&pictureID=' + pictureID);
}

function increaseLikes() {
    var currentLikes = document.getElementById('picNumLikes').innerHTML;
    currentLikes++;
    document.getElementById('picNumLikes').innerHTML = currentLikes;
}

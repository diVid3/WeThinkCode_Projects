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

function addCommentToPic(event, element, username, pictureID) {
    event.preventDefault();
    var commentBoxValue = document.getElementById('commentBox').value;
    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'processComments.php', true);
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    xhr.onload = function() {
        var returnArr = JSON.parse(this.responseText);
        if (returnArr['updateComments'] == 1) {
            increaseComments(username, commentBoxValue);
        }
    }
    xhr.send('commentBoxUsernameValue=' + username + '&' + 'commentBoxValue=' + commentBoxValue + '&' + 'pictureID=' + pictureID);
    document.getElementById('commentBox').value = '';
}

function increaseComments(username, commentBoxValue) {
    var commentTable = document.getElementById('commentTable');
    var newtableRow = document.createElement('tr');
    var newUsernameTableData = document.createElement('td');
    var newUsernameParagraph = document.createElement('p');
    var newCommentTableData = document.createElement('td');
    var newCommentParagraph = document.createElement('p');

    newUsernameParagraph.innerHTML = username;
    newCommentParagraph.innerHTML = commentBoxValue;

    newUsernameTableData.appendChild(newUsernameParagraph);
    newCommentTableData.appendChild(newCommentParagraph);
    newtableRow.appendChild(newUsernameTableData);
    newtableRow.appendChild(newCommentTableData);
    commentTable.appendChild(newtableRow);   
}

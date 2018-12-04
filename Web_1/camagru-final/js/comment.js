// Modal logic.

var formModal = document.getElementById('formModal');
var modalCloseButton = document.getElementById('okButton');
var modalRow = document.getElementById('modalRow');
modalCloseButton.addEventListener('click', closeModal);
window.addEventListener('click', clickOutsideModal);

// Modal functions.

function closeModal() {
    formModal.style.display = 'none';
    document.getElementById('modalHeader').innerHTML = 'Picture doesn\'t exist';
    document.getElementById('modalText').innerHTML = 'The related picture does not exist.';
    window.location = catPathToString('gallery.php');
}
function clickOutsideModal(e) {
    if (e.target == formModal) {
        formModal.style.display = 'none';
        document.getElementById('modalHeader').innerHTML = 'Picture doesn\'t exist';
        document.getElementById('modalText').innerHTML = 'The related picture does not exist.';
        window.location = catPathToString('gallery.php');
    }
    if (e.target == modalRow) {
        formModal.style.display = 'none';
        document.getElementById('modalHeader').innerHTML = 'Picture doesn\'t exist';
        document.getElementById('modalText').innerHTML = 'The related picture does not exist.';
        window.location = catPathToString('gallery.php');
    }
}

// Other generic functions.

function addLikeToPic(element, pictureID) {
    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'processLikes.php', true);
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    xhr.onload = function() {
        var returnArr = JSON.parse(this.responseText);
        if (returnArr['updateLikes'] == 1)
            increaseLikes();
        if (returnArr['noPicID'] == 1) {
            document.getElementById('modalHeader').innerHTML = 'Picture doesn\'t exist';
            document.getElementById('modalText').innerHTML = 'The related picture does not exist.';
            formModal.style.display = 'flex';
        }
    }
    xhr.send('addLikeToPic=true&pictureID=' + pictureID);
}

function increaseLikes() {
    var currentLikes = document.getElementById('picNumLikes').innerHTML;
    currentLikes++;
    document.getElementById('picNumLikes').innerHTML = currentLikes;
}

// username should come from db. Not clientside.
function addCommentToPic(event, pictureID) {
    event.preventDefault();
    var commentBoxValue = document.getElementById('commentBox').value;
    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'processComments.php', true);
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    xhr.onload = function() {
        var returnArr = JSON.parse(this.responseText);
        if (returnArr['updateComments'] == 1)
            increaseComments(returnArr['username'], commentBoxValue);
        if (returnArr['noPicID'] == 1) {
            document.getElementById('modalHeader').innerHTML = 'Picture doesn\'t exist';
            document.getElementById('modalText').innerHTML = 'The related picture does not exist.';
            formModal.style.display = 'flex';
        }
    }
    xhr.send('commentBoxValue=' + commentBoxValue + '&' + 'pictureID=' + pictureID);
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
    newCommentParagraph.innerHTML = escapeHTML(commentBoxValue);

    newUsernameTableData.appendChild(newUsernameParagraph);
    newCommentTableData.appendChild(newCommentParagraph);
    newtableRow.appendChild(newUsernameTableData);
    newtableRow.appendChild(newCommentTableData);
    commentTable.appendChild(newtableRow);   
}

// Remember that this is relative to the file the browser is viewing.
function catPathToString(string) {
    var the_arr = window.location.href.split('/');
    the_arr.pop();
    return(the_arr.join('/') + '/' + string);
}

// JS function to escape special chars.

function escapeHTML(string) {
    return string
    .replace(/&/g, "&amp;")
    .replace(/</g, "&lt;")
    .replace(/>/g, "&gt;")
    .replace(/"/g, "&quot;")
    .replace(/'/g, "&#039;");
}

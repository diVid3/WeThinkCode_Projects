// General globals.
var width = 500;
var height = 0;
var streaming = false;

var video = document.getElementById('video');
var canvas = document.getElementById('canvas');
var picture = document.getElementById('picture');
var takePicButton = document.getElementById('takePicButton');
var saveButton = document.getElementById('saveButton');
var stickerSelect = document.getElementById('stickers');
var sticker1 = document.getElementById('sticker1');
var sticker2 = document.getElementById('sticker2');
var sticker3 = document.getElementById('sticker3');
var clearButton = document.getElementById('clearButton');
var uploadButton = document.getElementById('uploadButton');

var takePicButtonClicks = 0;

var stickerChangeCount = 0;
var stickerChangeImageId = 0;

// Sticker paths. 2, 4, 6, 8 correspond with stickerChangeImageId for canvas.
var sticker2Path;
var sticker4Path;
var sticker6Path;
var sticker8Path;

// Variables for image merging.
var stickerEncoded;
var formData;

// Variable to keep track of upload state change.
var uploadChange = 0;

// Modal hooks and logic.
var formModal = document.getElementById('formModal');
var modalCloseButton = document.getElementById('okButton');
var modalRow = document.getElementById('modalRow');
modalCloseButton.addEventListener('click', closeModal);
window.addEventListener('click', clickOutsideModal);
function closeModal() {
    formModal.style.display = 'none';
    document.getElementById('modalHeader').innerHTML = 'Get a pic first';
    document.getElementById('modalText').innerHTML = 'You need to either take a pic first or upload a png image before attempting to save it.';
}
function clickOutsideModal(e) {
    if (e.target == formModal) {
        formModal.style.display = 'none';
        document.getElementById('modalHeader').innerHTML = 'Get a pic first';
        document.getElementById('modalText').innerHTML = 'You need to either take a pic first or upload a png image before attempting to save it.';
    }
    if (e.target == modalRow) {
        formModal.style.display = 'none';
        document.getElementById('modalHeader').innerHTML = 'Get a pic first';
        document.getElementById('modalText').innerHTML = 'You need to either take a pic first or upload a png image before attempting to save it.';
    }
}

// Set canvas display to none initially.
document.getElementById('canvasDiv').style.display = "none";

// Start webcam.
navigator.mediaDevices.getUserMedia({video: true, audio: false})
.then(function(stream) {
        video.srcObject = stream;
        video.play();
})
.catch(function(e) {
        error_log(e);
});

// Set video and canvas dimensions.
video.addEventListener('canplay', function() {
    if (streaming == false) {
        height = video.videoHeight / (video.videoWidth / width);
        video.setAttribute('width', width);
        video.setAttribute('height', height);
        canvas.setAttribute('width', width);
        canvas.setAttribute('height', height);
        streaming = true;
    }
}, false);

// Take picture on click event.
takePicButton.addEventListener('click', function(e) {
    var context = canvas.getContext('2d');
    if (width && height) {
        canvas.width = width;
        canvas.height = height;
        context.drawImage(video, 0, 0, width, height);
        takePicButtonClicks++;
        document.getElementById('videoDiv').style.display = "none";
        document.getElementById('canvasDiv').style.display = "flex";
    }
    e.preventDefault();
});

// Button calls script to merge and save merged picture to database.
saveButton.addEventListener('click', function(e) {
    if (takePicButtonClicks == 0 && uploadChange == 0)
        formModal.style.display = 'flex';
    else if (takePicButtonClicks >= 0 && uploadChange == 1) {
        formData = new FormData();
        formData.append('formData', 'true');
        if (document.getElementById('sticker2') !== null)
            formData.append('sticker2', sticker2Path);
        else
            formData.append('sticker2', 'img/none.png');
        if (document.getElementById('sticker4') !== null)
            formData.append('sticker4', sticker4Path);
        if (document.getElementById('sticker6') !== null)
            formData.append('sticker6', sticker6Path);
        if (document.getElementById('sticker8') !== null)
            formData.append('sticker8', sticker8Path);
        formData.append('uploadPicture', uploadButton.files[0]);
        var xhr = new XMLHttpRequest();
        xhr.open('POST', 'processSavePicture.php', true);
        var returnArr;
        xhr.onload = function() {
            returnArr = JSON.parse(this.responseText);
            if (returnArr['creationSuccess'] == 1) {
                document.getElementById('modalHeader').innerHTML = 'Notice';
                document.getElementById('modalText').innerHTML = 'Picture successfully created.';
                formModal.style.display = 'flex';
            }
            if (returnArr['creationError'] == 1) {
                document.getElementById('modalHeader').innerHTML = 'Notice';
                document.getElementById('modalText').innerHTML = 'Failed to create picture.';
                formModal.style.display = 'flex';
            }
            if (returnArr['uploadError'] == 1) {
                document.getElementById('modalHeader').innerHTML = 'Notice';
                document.getElementById('modalText').innerHTML = returnArr['uploadErrorMsg'];
                formModal.style.display = 'flex';
            }
            if (returnArr['doneSavingPic'] == 1)
                updateUserGallery();
        }
        xhr.send(formData);
        clearPicture();
    }
    else if (takePicButtonClicks > 0 && uploadChange == 0) {
        var keyVal1 = 'imgURL=' + canvas.toDataURL('image/png');
        if (document.getElementById('sticker2') !== null)
            var keyVal2 = 'sticker2=' + sticker2Path;
        if (document.getElementById('sticker4') !== null)
            var keyVal3 = 'sticker4=' + sticker4Path;
        if (document.getElementById('sticker6') !== null)
            var keyVal4 = 'sticker6=' + sticker6Path;
        if (document.getElementById('sticker8') !== null)
            var keyVal5 = 'sticker8=' + sticker8Path;
        var xhr = new XMLHttpRequest();
        xhr.open('POST', 'processSavePicture.php', true);
        xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
        var returnArr;
        xhr.onload = function() {
            returnArr = JSON.parse(this.responseText);
            if (returnArr['creationSuccess'] == 1) {
                document.getElementById('modalHeader').innerHTML = 'Notice';
                document.getElementById('modalText').innerHTML = 'Picture successfully created.';
                formModal.style.display = 'flex';
            }
            if (returnArr['creationError'] == 1) {
                document.getElementById('modalHeader').innerHTML = 'Notice';
                document.getElementById('modalText').innerHTML = 'Failed to create picture.';
                formModal.style.display = 'flex';
            }
            if (returnArr['doneSavingPic'] == 1)
                updateUserGallery();
        }
        var stringToSend = keyVal1 + '&' + 'sticker2=img/none.png';
        if (document.getElementById('sticker2') !== null)
            stringToSend = keyVal1 + '&' + keyVal2;
        if (document.getElementById('sticker4') !== null)
            stringToSend = keyVal1 + '&' + keyVal2 + '&' + keyVal3;
        if (document.getElementById('sticker6') !== null)
            stringToSend = keyVal1 + '&' + keyVal2 + '&' + keyVal3 + '&' + keyVal4;
        if (document.getElementById('sticker8') !== null)
            stringToSend = keyVal1 + '&' + keyVal2 + '&' + keyVal3 + '&' + keyVal4 + '&' + keyVal5;
        xhr.send(stringToSend);
        clearPicture();
    }
    e.preventDefault();
});

// Change stickers upon selection. Need to create and add img elements when change happens.
stickerSelect.addEventListener('change', function(e) {
    stickerChangeCount++;
    if (stickerChangeCount > 4) {
        if (e.target.value == 'img/none.png')
            clearPicture(0);
        return;
    }
    // Adding sticker to video.
    stickerChangeImageId++;
    let newStickerVideo = document.createElement('img');
    newStickerVideo.setAttribute('id', 'sticker' + stickerChangeImageId);
    newStickerVideo.setAttribute('style', 'position:absolute;width:78.25%;height:87.46%;left:10.85%;');
    newStickerVideo.src = e.target.value;
    document.getElementById('videoDiv').appendChild(newStickerVideo);
    // Adding sticker to canvas.
    stickerChangeImageId++;
    let newStickerCanvas = document.createElement('img');
    newStickerCanvas.setAttribute('id', 'sticker' + stickerChangeImageId);
    newStickerCanvas.setAttribute('style', 'position:absolute;width:100%;height:87.46%;left:0%;');
    newStickerCanvas.src = e.target.value;
    document.getElementById('canvasDiv').appendChild(newStickerCanvas);
    if (stickerChangeCount == 1)
        sticker2Path = e.target.value;
    if (stickerChangeCount == 2)
        sticker4Path = e.target.value;
    if (stickerChangeCount == 3)
        sticker6Path = e.target.value;
    if (stickerChangeCount == 4)
        sticker8Path = e.target.value;
    if (e.target.value == 'img/none.png')
        clearPicture(0);
    e.preventDefault();
});

// Upload logic.
uploadButton.onchange = function() {
    uploadChange = 1;
}

// Clears the taken picture. If mode is 0, it will not reset the video/canvas elements.
function clearPicture(mode) {
    takePicButtonClicks = 0;
    uploadChange = 0;
    uploadButton.value = '';
    for (var cntr = 1; cntr <= 8; cntr++) {
        let stickerTag = document.getElementById('sticker' + cntr);
        if (stickerTag !== null)
            stickerTag.remove();
    }
    stickerChangeCount = 0;
    stickerChangeImageId = 0;
    sticker2Path = undefined;
    sticker4Path = undefined;
    sticker6Path = undefined;
    sticker8Path = undefined;
    if (mode == 0)
        return;
    document.getElementById('videoDiv').style.display = "flex";
    document.getElementById('canvasDiv').style.display = "none";
}

clearButton.addEventListener('click', clearPicture);

// Function to update DOM when picture was saved to DB.
function updateUserGallery() {
    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'processUpdateUserGallery.php', true);
    xhr.onload = function() {
        var returnArr = JSON.parse(this.responseText);
        if (returnArr['updateUserGalleryFail'] == 1) {
            document.getElementById('modalHeader').innerHTML = 'Notice';
            document.getElementById('modalText').innerHTML = 'Async update to user gallery failed.';
            formModal.style.display = 'flex';
        }
        if (returnArr['gotNewestPic'] == 1) {
            let newUserPicture = document.createElement('img');
            newUserPicture.setAttribute('src', returnArr['encodedPicture']);
            newUserPicture.setAttribute('class', 'userPicture');
            newUserPicture.setAttribute('id', 'userPic' + returnArr['pictureID']);
            newUserPicture.setAttribute('onclick', 'delUserPic(this)');
            document.getElementById('userPictureGallery1').appendChild(newUserPicture);
        }
    }
    xhr.send();
}

// Function to delete user picture from DOM and DB. Activates on click.
function delUserPic(element) {
    var string = element.id;
    var arr = string.split('userPic');
    var pictureID = arr[1];
    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'processUpdateUserGalleryRem.php', true);
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    xhr.onload = function() {
        var returnArr = JSON.parse(this.responseText);
        if (returnArr['updateUserGalleryRemFail'] == 1) {
            document.getElementById('modalHeader').innerHTML = 'Notice';
            document.getElementById('modalText').innerHTML = 'Async update to user gallery failed.';
            formModal.style.display = 'flex';
        }
        if (returnArr['deletedPicture'] == 1)
            element.parentNode.removeChild(element);
    }
    xhr.send('pictureID=' + pictureID);
}

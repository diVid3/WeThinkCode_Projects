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

sticker1.src = 'img/none.png';
sticker2.src = 'img/none.png';
sticker3.src = 'img/none.png';

// Variables for image merging.
var imgURL;
var stickerPath = 'img/none.png';
var stickerEncoded;
var formData;

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

// Need AJAX to request processSavePicture.php.
saveButton.addEventListener('click', function(e) {
    if (takePicButtonClicks == 0 && typeof uploadButton.files[0] == 'undefined')
        formModal.style.display = 'flex';
    else if (takePicButtonClicks >= 0 && typeof uploadButton.files[0] != 'undefined') {
        formData = new FormData();
        formData.append('formData', 'true');
        formData.append('stickerPath', stickerPath);
        formData.append('uploadPicture', uploadButton.files[0]);
        var xhr = new XMLHttpRequest();
        xhr.open('POST', 'processSavePicture.php', true);
        xhr.onload = function() {
            var returnArr = JSON.parse(this.responseText);
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
        }
        xhr.send(formData);
    }
    else if (takePicButtonClicks > 0 && typeof uploadButton.files[0] == 'undefined') {
        var imgURL = canvas.toDataURL('image/png');
        var keyVal1 = 'imgURL=' + imgURL;
        var keyVal2 = 'stickerPath=' + stickerPath;
        var xhr = new XMLHttpRequest();
        xhr.open('POST', 'processSavePicture.php', true);
        xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
        xhr.onload = function() {
            var returnArr = JSON.parse(this.responseText);
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
        }
        xhr.send(keyVal1 + '&' + keyVal2);
    }
});

// Change stickers upon selection.
stickerSelect.addEventListener('change', function(e) {
    sticker1.src = e.target.value;
    sticker2.src = e.target.value;
    sticker3.src = e.target.value;
    stickerPath = e.target.value;
    e.preventDefault();
});

// Upload logic.
uploadButton.addEventListener('change', function(e) {
    e.preventDefault();
});

// Clears the taken picture.
clearButton.addEventListener('click', function(e) {
    takePicButtonClicks = 0;
    uploadButton.files[0] = 'undefined';
    sticker1.src = 'img/none.png';
    sticker2.src = 'img/none.png';
    document.getElementById('videoDiv').style.display = "flex";
    document.getElementById('canvasDiv').style.display = "none";
});

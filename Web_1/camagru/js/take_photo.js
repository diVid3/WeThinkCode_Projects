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
var clearButton = document.getElementById('clearButton');
var uploadButton = document.getElementById('uploadButton');

var takePicButtonClicks = 0;
// Need to add var for uploadClicks.
var uploadClicks = 0;

// Variables for image merging.
var imgEncoded;
var stickerPath = 'img/none.png';
var stickerEncoded;

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

// Need AJAX to request processSavePicture.php. Need priority logic when pic taken + uploaded.
saveButton.addEventListener('click', function(e) {
    if (takePicButtonClicks == 0 && uploadClicks == 0) {
        // Need error logic for modal in case no img to merge.
        return;
    }
    var imgURL = canvas.toDataURL('image/png');
    imgEncoded = imgURL.split(',')[1];
    var keyVal1 = 'imgEncoded=' + imgEncoded;
    var keyVal2 = 'stickerPath=' + stickerPath;
    var xhr = new XMLHttpRequest();
    xhr.open('POST', 'processSavePicture.php');
    xhr.send(keyVal1 + '&' + keyVal2);
})

// Change stickers upon selection.
stickerSelect.addEventListener('change', function(e) {
    sticker1.src = e.target.value;
    sticker2.src = e.target.value;
    stickerPath = e.target.value;
    console.log(e.target.value);
    e.preventDefault();
})

// Logic for selecting image to upload. FileReader class is used here.
uploadButton.addEventListener('change', function(e) {
    uploadClicks++;
    console.log(uploadButton.files[0]);
    console.log(uploadClicks);
    e.preventDefault();
})

// Clears the taken picture.
clearButton.addEventListener('click', function(e) {
    document.getElementById('videoDiv').style.display = "flex";
    document.getElementById('canvasDiv').style.display = "none";
    e.preventDefault();
})

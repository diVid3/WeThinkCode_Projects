var width = 500;
var height = 0;
var streaming = false;

var video = document.getElementById('video');
var canvas = document.getElementById('canvas');
var picture = document.getElementById('picture');
var takePicButton = document.getElementById('takePicButton');
var saveButton = document.getElementById('saveButton');

var takePicButtonClicks = 0;

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
    }
    e.preventDefault();
});

// Need AJAX to request processSavePicture.php.
saveButton.addEventListener('click', function(e) {
    if (takePicButtonClicks == 0)
        return;
    var imgURL = canvas.toDataURL('image/png');
    var img = imgURL.split(',')[1];
    console.log(img);
})



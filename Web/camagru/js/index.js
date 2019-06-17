// This function is used to get the $_GET parameters on window load.
window.onload = function() {
    var formModal = document.getElementById('formModal');
    var modalCloseButton = document.getElementById('okButton');
    var modalRow = document.getElementById('modalRow');
    modalCloseButton.addEventListener('click', closeModal);
    window.addEventListener('click', clickOutsideModal);

    function closeModal() {
        formModal.style.display = 'none';
        document.getElementById('modalHeader').innerHTML = 'Verification failure';
        if (signinState != null) {
            window.location.assign(catPathToString('index.php'));
        }
    }
    function clickOutsideModal(e) {
        if (e.target == formModal) {
            formModal.style.display = 'none';
            document.getElementById('modalHeader').innerHTML = 'Verification failure';
        }
        if (e.target == modalRow) {
            formModal.style.display = 'none';
            document.getElementById('modalHeader').innerHTML = 'Verification failure';
        }
    }

    // This function gets the $_GET parameters.
    function parseGetParameters(parameter) {
        var fullURL = window.location.search.substring(1);
        var parametersArray = fullURL.split('&');
        for (var i = 0; i < parametersArray.length; i++) {
            var currentParameter = parametersArray[i].split('=');
            if (currentParameter[0] == parameter)
                return currentParameter[1];
        }
    }

    var verifyState = parseGetParameters('verify');
    var resetPassState = parseGetParameters('resetPass');
    var signinState = parseGetParameters('signin');

    if (verifyState == 'success') {
        document.getElementById('modalHeader').innerHTML = 'Verification success';
        document.getElementById('modalText').innerHTML = 'You have successfully verified your email address. You may sign in.';
        formModal.style.display = 'flex';
    }
    if (verifyState == 'fail') {
        document.getElementById('modalHeader').innerHTML = 'Verification failure';
        document.getElementById('modalText').innerHTML = 'Invalid verification code.';
        formModal.style.display = 'flex';
    }

    if (resetPassState == 'fail') {
        document.getElementById('modalHeader').innerHTML = 'Reset password failure';
        document.getElementById('modalText').innerHTML = 'Invalid password reset code.';
        formModal.style.display = 'flex';
    }

    if (signinState == 'success') {
        var signinUsername = parseGetParameters('username');
        document.getElementById('modalHeader').innerHTML = 'Successfully signed in';
        document.getElementById('modalText').innerHTML = 'Welcome ' + signinUsername + '.';
        formModal.style.display = 'flex';
    }
}

// Remember that this is relative to the file the browser is viewing.
function catPathToString(string) {
    var the_arr = window.location.href.split('/');
    the_arr.pop();
    return(the_arr.join('/') + '/' + string);
}

// console.log(catPathToString('derp.php'));

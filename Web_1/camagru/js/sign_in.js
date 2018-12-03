document.getElementById('signinForm').addEventListener('submit', postSignInForm);

// Need a much cleaner way of splitting these.
function postSignInForm(e) {
    e.preventDefault();

    var signinFormUsername = document.getElementById('signinFormUsername').value;
    var signinFormPassword = document.getElementById('signinFormPassword').value;

    var keyVal1 = "signinFormUsername=" + signinFormUsername;
    var keyVal2 = "signinFormPassword=" + signinFormPassword;

    var xhr = new XMLHttpRequest();

    xhr.open('POST', 'processSigninForm.php', true);
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    // Need to add exception checks here.
    xhr.onload = function() {
        var returnArr = JSON.parse(this.responseText);
        var formModal = document.getElementById('formModal');
        var modalCloseButton = document.getElementById('okButton');
        var modalRow = document.getElementById('modalRow');
        modalCloseButton.addEventListener('click', closeModal);
        window.addEventListener('click', clickOutsideModal);

        function closeModal() {
            formModal.style.display = 'none';
            document.getElementById('modalHeader').innerHTML = 'Double-check form';

        }
        function clickOutsideModal(e) {
            if (e.target == formModal) {
                formModal.style.display = 'none';
                document.getElementById('modalHeader').innerHTML = 'Double-check form';
            }
            if (e.target == modalRow) {
                formModal.style.display = 'none';
                document.getElementById('modalHeader').innerHTML = 'Double-check form';
            }
        }
        openModal(returnArr, formModal);
    }
    xhr.send(keyVal1 + "&" + keyVal2);
}

// This function will open a modal based upon specific conditions.
function openModal(returnArr, formModal) {

    // Logic - Modal - Username.

    if (returnArr['usernameInvalid'] == 1) {
        document.getElementById('modalHeader').innerHTML = 'Double-check form';
        document.getElementById('modalText').innerHTML = 'Username invalid.';
        formModal.style.display = 'flex';
    }

    // Logic - Modal - Passwords.

    if (returnArr['passwordInvalid'] == 1) {
        document.getElementById('modalHeader').innerHTML = 'Double-check form';
        document.getElementById('modalText').innerHTML = 'Password invalid.';
        formModal.style.display = 'flex';
    }

    // Logic - Modal - Account verification.

    if (returnArr['accountNotVerified'] == 1) {
        document.getElementById('modalHeader').innerHTML = 'Verify account';
        document.getElementById('modalText').innerHTML = 'Your account needs to be verified before you can sign in.';
        formModal.style.display = 'flex';
    }

    // Logic - Modal - Sign in.

    if (returnArr['successfulSignin'] == 1) {
        var username = returnArr['username'];
        window.location = catPathToString('index.php?signin=success&username=') + username;
    }
}

// Remember that this is relative to the file the browser is viewing.
function catPathToString(string) {
    var the_arr = window.location.href.split('/');
    the_arr.pop();
    return(the_arr.join('/') + '/' + string);
}

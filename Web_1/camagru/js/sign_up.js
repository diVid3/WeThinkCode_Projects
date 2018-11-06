document.getElementById('signupForm').addEventListener('submit', postSignupForm);

// Need a much cleaner way of splitting these.
function postSignupForm(e) {
    e.preventDefault();

    var signupFormUsername = document.getElementById('signupFormUsername').value;
    var signupFormPassword = document.getElementById('signupFormPassword').value;
    var signupFormConfirmPassword = document.getElementById('signupFormConfirmPassword').value;
    var signupFormEmail = document.getElementById('signupFormEmail').value;

    var keyVal1 = "signupFormUsername=" + signupFormUsername;
    var keyVal2 = "signupFormPassword=" + signupFormPassword;
    var keyVal3 = "signupFormConfirmPassword=" + signupFormConfirmPassword;
    var keyVal4 = "signupFormEmail=" + signupFormEmail;

    var xhr = new XMLHttpRequest();

    xhr.open('POST', 'processSignupForm.php', true);
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
    // Need to add exception checks here.
    xhr.onload = function() {
        var returnArr = JSON.parse(this.responseText);
        // console.log(returnArr);
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
    xhr.send(keyVal1 + "&" + keyVal2 + "&" + keyVal3 + "&" + keyVal4);
}

// This function will open a modal based upon specific conditions.
function openModal(returnArr, formModal) {

    // Logic - Modal - Username.

    if (returnArr['usernameTooLong'] == 1) {
        document.getElementById('modalText').innerHTML = 'Username too long, maximum 32 characters.';
        formModal.style.display = 'flex';
    }
    if (returnArr['usernameTooShort'] == 1) {
        document.getElementById('modalText').innerHTML = 'Username too short, minimum 4 characters.';
        formModal.style.display = 'flex';
    }
    if (returnArr['usernameSpecCharFound'] == 1) {
        document.getElementById('modalText').innerHTML = 'Username contains special characters.';
        formModal.style.display = 'flex';
    }
    if (returnArr['usernameMultipleWords'] == 1) {
        document.getElementById('modalText').innerHTML = 'Username contains multiple words.';
        formModal.style.display = 'flex';
    }
    if (returnArr['usernameTaken'] == 1) {
        document.getElementById('modalText').innerHTML = 'Username taken, try another username.';
        formModal.style.display = 'flex';
    }

    // Logic - Modal - Passwords.

    // if (returnArr['passwordTooLong'] == 1) {
    //     document.getElementById('modalText').innerHTML = 'Password too long, maximum 32 characters.';
    //     formModal.style.display = 'flex';
    // }
    if (returnArr['passwordTooShort'] == 1) {
        document.getElementById('modalText').innerHTML = 'Password too short, minimum 7 characters.';
        formModal.style.display = 'flex';
    }
    // if (returnArr['passwordNotLegalCharFound'] == 1) {
    //     document.getElementById('modalText').innerHTML = 'Password contains illegal characters.';
    //     formModal.style.display = 'flex';
    // }
    if (returnArr['passwordMatch'] == 0) {
        document.getElementById('modalText').innerHTML = 'Passwords do not match.';
        formModal.style.display = 'flex';
    }

    // Logic - Modal - Email.
    if (returnArr['emailTooLong'] == 1) {
        document.getElementById('modalText').innerHTML = 'Email address too long, maximum 32 characters.';
        formModal.style.display = 'flex';
    }
    if (returnArr['emailNotValid'] == 1) {
        document.getElementById('modalText').innerHTML = 'Email address is not valid';
        formModal.style.display = 'flex';
    }
    if (returnArr['emailTaken'] == 1) {
        document.getElementById('modalText').innerHTML = 'Email address taken, try another email address.';
        formModal.style.display = 'flex';
    }

    // Logic - Modal - Account created.

    if (returnArr['accountCreated'] == 1) {
        document.getElementById('modalHeader').innerHTML = 'Account created';
        document.getElementById('modalText').innerHTML = 'To verify your account, follow the instructions in the message sent your email address.';
        formModal.style.display = 'flex';
    }
}

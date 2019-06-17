document.getElementById('resetPassForm').addEventListener('submit', processPassReset);

function processPassReset(e) {
    e.preventDefault();

    var resetPassFormUsername = document.getElementById('resetPassFormUsername').value;
    var resetPassFormPassword = document.getElementById('resetPassFormPassword').value;
    var resetPassFormConfirmPassword = document.getElementById('resetPassFormConfirmPassword').value;
    var resetPassFormToken = document.getElementById('resetPassFormToken').value;

    var keyVal1 = "resetPassFormUsername=" + resetPassFormUsername;
    var keyVal2 = "resetPassFormPassword=" + resetPassFormPassword;
    var keyVal3 = "resetPassFormConfirmPassword=" + resetPassFormConfirmPassword;
    var keyVal4 = "resetPassFormToken=" + resetPassFormToken;

    var xhr = new XMLHttpRequest();

    xhr.open('POST', 'processPassReset.php', true);
    xhr.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
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
    xhr.send(keyVal1 + "&" + keyVal2 + "&" + keyVal3 + "&" + keyVal4);
}

// This function will open a modal based upon specific conditions.
function openModal(returnArr, formModal) {

    // Logic - Modal - Username.

    if (returnArr['usernameSpecCharFound'] == 1) {
        document.getElementById('modalHeader').innerHTML = 'Double-check form';
        document.getElementById('modalText').innerHTML = 'Username contains special characters.';
        formModal.style.display = 'flex';
    }
    if (returnArr['usernameNotRegistered'] == 1) {
        document.getElementById('modalHeader').innerHTML = 'Double-check form';
        document.getElementById('modalText').innerHTML = 'Username is invalid.';
        formModal.style.display = 'flex';
    }

    // Logic - Modal - Passwords.

    if (returnArr['passwordTooShort'] == 1) {
        document.getElementById('modalHeader').innerHTML = 'Double-check form';
        document.getElementById('modalText').innerHTML = 'Password too short, minimum 7 characters.';
        formModal.style.display = 'flex';
    }
    if (returnArr['passwordNoMix'] == 1) {
        document.getElementById('modalHeader').innerHTML = 'Double-check form';
        document.getElementById('modalText').innerHTML = 'Password(s) not mixed case.';
        formModal.style.display = 'flex';
    }
    if (returnArr['passwordMatch'] == 0) {
        document.getElementById('modalHeader').innerHTML = 'Double-check form';
        document.getElementById('modalText').innerHTML = 'Passwords do not match.';
        formModal.style.display = 'flex';
    }

    // Logic - Modal - Token.

    if (returnArr['tokenInvalid'] == 1) {
        document.getElementById('modalHeader').innerHTML = 'Double-check form';
        document.getElementById('modalText').innerHTML = 'The token you entered is invalid';
        formModal.style.display = 'flex';
    }

    // Logic - Modal - Password reset successful.

    if (returnArr['passResetSuccessful'] == 1) {
        document.getElementById('modalHeader').innerHTML = 'Password reset successful';
        document.getElementById('modalText').innerHTML = 'Your password has been reset successfully. You may now sign in.';
        formModal.style.display = 'flex';
    }
}

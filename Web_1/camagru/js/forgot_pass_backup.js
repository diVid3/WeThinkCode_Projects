document.getElementById('forgotPasswordForm').addEventListener('submit', forgotPassword);

function forgotPassword(e) {
    e.preventDefault();

    var forgotPasswordFormEmail = document.getElementById('forgotPasswordFormEmail').value;

    var keyVal1 = "forgotPasswordFormEmail=" + forgotPasswordFormEmail;

    var xhr = new XMLHttpRequest();

    xhr.open('POST', 'processForgotPassword.php', true);
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
            document.getElementById('modalHeader').innerHTML = 'Password reset email sent';

        }
        function clickOutsideModal(e) {
            if (e.target == formModal) {
                formModal.style.display = 'none';
                document.getElementById('modalHeader').innerHTML = 'Password reset email sent';
            }
            if (e.target == modalRow) {
                formModal.style.display = 'none';
                document.getElementById('modalHeader').innerHTML = 'Password reset email sent';
            }
        }
        openModal(returnArr, formModal);
    }
    xhr.send(keyVal1);
}

function openModal(returnArr, formModal) {
    if (returnArr['emailTooLong'] == 1) {
        document.getElementById('modalText').innerHTML = 'The email address too long, maximum 32 characters.';
        formModal.style.display = 'flex';
    }
    if (returnArr['emailNotValid'] == 1) {
        document.getElementById('modalText').innerHTML = 'The email address is not valid';
        formModal.style.display = 'flex';
    }
    if (returnArr['emailNotRegistered'] == 1) {
        document.getElementById('modalText').innerHTML = 'The email address you\'ve entered has not been registered';
        formModal.style.display = 'flex';
    }
    if (returnArr['forgotPasswordEmailSent'] == 1) {
        document.getElementById('modalHeader').innerHTML = 'Password reset email sent';
        document.getElementById('modalText').innerHTML = 'We\'ve sent you an email to reset your password, please follow the instructions carefully.';
        formModal.style.display = 'flex';
    }
}
document.getElementById('forgotPasswordForm').addEventListener('submit', forgotPassword);

function forgotPassword(e) {
    e.preventDefault();

    var forgotPasswordFormUsername = document.getElementById('forgotPasswordFormUsername').value;

    var keyVal1 = "forgotPasswordFormUsername=" + forgotPasswordFormUsername;

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

// Need to change this modal logic for username.

function openModal(returnArr, formModal) {
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
    if (returnArr['forgotPasswordEmailSent'] == 1) {
        document.getElementById('modalHeader').innerHTML = 'Password reset email sent';
        document.getElementById('modalText').innerHTML = 'We\'ve sent you an email to reset your password, please follow the instructions carefully.';
        formModal.style.display = 'flex';
    }
}
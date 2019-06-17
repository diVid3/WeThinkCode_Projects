document.getElementById('editProfileForm').addEventListener('submit', postEditProfileForm);

// Need a much cleaner way of splitting these.
function postEditProfileForm(e) {
    e.preventDefault();

    var editProfileFormUsername = document.getElementById('editProfileFormUsername').value;
    var editProfileFormPassword = document.getElementById('editProfileFormPassword').value;
    var editProfileFormConfirmPassword = document.getElementById('editProfileFormConfirmPassword').value;
    var editProfileFormEmail = document.getElementById('editProfileFormEmail').value;
    var editProfileFormNotification = document.getElementById('editProfileFormNotification').checked;

    var keyVal1 = "editProfileFormUsername=" + editProfileFormUsername;
    var keyVal2 = "editProfileFormPassword=" + editProfileFormPassword;
    var keyVal3 = "editProfileFormConfirmPassword=" + editProfileFormConfirmPassword;
    var keyVal4 = "editProfileFormEmail=" + editProfileFormEmail;
    if (editProfileFormNotification == true)
        var keyVal5 = "editProfileFormNotification=true";
    else
        var keyVal5 = "editProfileFormNotification=false";

    var xhr = new XMLHttpRequest();

    xhr.open('POST', 'processEditProfile.php', true);
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
    xhr.send(keyVal1 + "&" + keyVal2 + "&" + keyVal3 + "&" + keyVal4 + "&" + keyVal5);
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

    if (returnArr['passwordTooShort'] == 1) {
        document.getElementById('modalText').innerHTML = 'Password too short, minimum 7 characters.';
        formModal.style.display = 'flex';
    }
    if (returnArr['passwordNoMix'] == 1) {
        document.getElementById('modalText').innerHTML = 'Password(s) not mixed case.';
        formModal.style.display = 'flex';
    }
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

    // Logic - Modal - Profile edited.

    if (returnArr['editedProfile'] == 1) {
        document.getElementById('modalHeader').innerHTML = 'Edited profile';
        document.getElementById('modalText').innerHTML = 'You have successfully edited your profile, make sure to keep your details safe.';
        formModal.style.display = 'flex';
    }
}

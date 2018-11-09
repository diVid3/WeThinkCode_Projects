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
        // document.getElementById('nav4href').href = "edit_profile.php";
        // document.getElementById('nav4text').setAttribute('onclick', "location.href='edit_profile.php';");
        // document.getElementById('nav4text').innerHTML = "Edit profile";
        // document.getElementById('nav5href').href = "sign_out.php";
        // document.getElementById('nav5text').setAttribute('onclick', "location.href='sign_out.php';");
        // document.getElementById('nav5text').innerHTML = "Sign out";
        // document.getElementById('modalHeader').innerHTML = 'Successfully signed in';
        // document.getElementById('modalText').innerHTML = 'Welcome ' + returnArr['username'] + '.';
        // formModal.style.display = 'flex';
        var username = returnArr['username'];
        window.location = "http://127.0.0.1:8080/index.php?signin=success&username=" + username;
    }
}

document.getElementById('signupForm').addEventListener('submit', postSignupForm);

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
    xhr.onload = function() {
        console.log(this.responseText);
    }
    xhr.send(keyVal1 + "&" + keyVal2 + "&" + keyVal3 + "&" + keyVal4);
}
var formModal = document.getElementById('formModal');
var modalCloseButton = document.getElementById('okButton');
var modalRow = document.getElementById('modalRow');

modalCloseButton.addEventListener('click', closeModal);
window.addEventListener('click', clickOutsideModal);

function closeModal() {
    formModal.style.display = 'none';
    window.location = catPathToString('sign_in.php');
}

function clickOutsideModal(e) {
    if (e.target == formModal) {
        formModal.style.display = 'none';
    }
    if (e.target == modalRow) {
        formModal.style.display = 'none';
    }
    window.location = catPathToString('sign_in.php');
}

// Remember that this is relative to the file the browser is viewing.
function catPathToString(string) {
    var the_arr = window.location.href.split('/');
    the_arr.pop();
    return(the_arr.join('/') + '/' + string);
}

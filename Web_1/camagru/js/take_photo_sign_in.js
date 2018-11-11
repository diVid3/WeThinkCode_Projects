var formModal = document.getElementById('formModal');
var modalCloseButton = document.getElementById('okButton');
var modalRow = document.getElementById('modalRow');

modalCloseButton.addEventListener('click', closeModal);
window.addEventListener('click', clickOutsideModal);

function closeModal() {
    formModal.style.display = 'none';
    window.location = "http://127.0.0.1:8080/sign_in.php";
}

function clickOutsideModal(e) {
    if (e.target == formModal) {
        formModal.style.display = 'none';
    }
    if (e.target == modalRow) {
        formModal.style.display = 'none';
    }
    window.location = "http://127.0.0.1:8080/sign_in.php";
}

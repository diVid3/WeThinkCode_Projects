var formModal = document.getElementById('formModal');
var modalButton = document.getElementById('modalButton');
var modalCloseButton = document.getElementById('okButton');
var modalRow = document.getElementById('modalRow');
modalButton.addEventListener('click', openModal);
modalCloseButton.addEventListener('click', closeModal);
window.addEventListener('click', clickOutsideModal);

function openModal() {
    formModal.style.display = 'flex';
}

function closeModal() {
    formModal.style.display = 'none';
}

function clickOutsideModal(e) {
    if (e.target == formModal) {
        formModal.style.display = 'none';
    }
    if (e.target == modalRow) {
        formModal.style.display = 'none';
    }
}

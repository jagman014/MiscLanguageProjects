const button = document.getElementById('button');

const colours = ['red', 'orange', 'yellow', 'green', 'blue', 'rebbecapurple', 'violet'];

function change() {
    document.body.style.background = colours[Math.floor(7 * Math.random())];
}

button.addEventListener('click', change);

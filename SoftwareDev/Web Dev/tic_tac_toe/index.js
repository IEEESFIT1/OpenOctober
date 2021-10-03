// variables
const playerXsybmol = 1;
const playerOsybmol = 0;
let win_flag = false;
let tied_flag = false;
let winner_name = "none";
let history = [-1, -1, -1, -1, -1, -1, -1, -1, -1]
document.addEventListener('DOMContentLoaded', function() {
    const squares = document.querySelectorAll('.grid div');
    let playerDispaly = document.getElementById('player');

    squares.forEach(function (square) {
        square.addEventListener('click', clickOutcome);
    });

    function clickOutcome(event) {
        const mysquares = Array.from(squares);
        const index = mysquares.indexOf(event.target);
        if ((win_flag == false) && (tied_flag == false)) {
            if (history[index] == -1) {
                if(playerDispaly.innerHTML == 'playerX') {
                    squares[index].classList.add('playerX');
                    playerDispaly.innerHTML = 'playerO';
                    history[index] = playerXsybmol;
                    checkWinner(playerXsybmol);
                }
                else {
                    squares[index].classList.add('playerO');
                    playerDispaly.innerHTML = 'playerX';
                    history[index] = playerOsybmol;
                    checkWinner(playerOsybmol);
                }
            }
            else {
                alert('The box is already filled.')
            }
            setTimeout(result, 0);
        }
        else {
            if(confirm(`${winner_name} won the game. Press ok to play again.`)) {
                window.location.reload();
            }
        }

    }

    function checkWinner(symbol) {
        if (((history[0] == symbol) && (history[1] == symbol) && (history[2] == symbol)) ||
        ((history[3] == symbol) && (history[4] == symbol) && (history[5] == symbol)) ||
        ((history[6] == symbol) && (history[7] == symbol) && (history[8] == symbol)) ||
        ((history[0] == symbol) && (history[3] == symbol) && (history[6] == symbol)) ||
        ((history[1] == symbol) && (history[4] == symbol) && (history[7] == symbol)) ||
        ((history[2] == symbol) && (history[5] == symbol) && (history[8] == symbol)) ||
        ((history[0] == symbol) && (history[4] == symbol) && (history[8] == symbol)) ||
        ((history[2] == symbol) && (history[4] == symbol) && (history[6] == symbol))) {
            if ((history[0] == symbol) && (history[1] == symbol) && (history[2] == symbol)) {
                squares[0].classList.add('horizontal');
                squares[1].classList.add('horizontal');
                squares[2].classList.add('horizontal');
            }
            else if ((history[3] == symbol) && (history[4] == symbol) && (history[5] == symbol)) {
                squares[3].classList.add('horizontal');
                squares[4].classList.add('horizontal');
                squares[5].classList.add('horizontal');
            }
            else if ((history[6] == symbol) && (history[7] == symbol) && (history[8] == symbol)) {
                squares[6].classList.add('horizontal');
                squares[7].classList.add('horizontal');
                squares[8].classList.add('horizontal');
            }

            else if ((history[0] == symbol) && (history[3] == symbol) && (history[6] == symbol)) {
                squares[0].classList.add('vertical');
                squares[3].classList.add('vertical');
                squares[6].classList.add('vertical');
            }
            else if ((history[1] == symbol) && (history[4] == symbol) && (history[7] == symbol)) {
                squares[1].classList.add('vertical');
                squares[4].classList.add('vertical');
                squares[7].classList.add('vertical');
            }
            else if ((history[2] == symbol) && (history[5] == symbol) && (history[8] == symbol)) {
                squares[2].classList.add('vertical');
                squares[5].classList.add('vertical');
                squares[8].classList.add('vertical');
            }
            else if ((history[0] == symbol) && (history[4] == symbol) && (history[8] == symbol)) {
                squares[0].classList.add('right_diagonal');
                squares[4].classList.add('right_diagonal');
                squares[8].classList.add('right_diagonal');
            }
            else if ((history[2] == symbol) && (history[4] == symbol) && (history[6] == symbol)) {
                squares[2].classList.add('left_diagonal');
                squares[4].classList.add('left_diagonal');
                squares[6].classList.add('left_diagonal');
            }
            setWinner(symbol);
        }
        else if ((history[0] != -1) && (history[1] != -1) && (history[2] != -1) && (history[3] != -1) && (history[4] != -1) && (history[5] != -1) && (history[6] != -1) && (history[7] != -1) && (history[8] != -1)) {
            tied_flag = true;
            winner_name = 'Nobody';
            document.getElementById('result').innerHTML = 'Nobody won the game';
        }
        else { }
    }

    function setWinner(symbol) {
        if (symbol == playerXsybmol) {
            winner_name = 'playerX';
            document.getElementById('result').innerHTML = `${winner_name} won the game.`;
        }
        else {
            winner_name = 'playerO';
            document.getElementById('result').innerHTML = `${winner_name} won the game.`;
        }
        win_flag = true;
    }

    function result () {
        if (win_flag) {
            if(confirm(`${winner_name} won the game. Press ok to play again.`)) {
                window.location.reload();
            }
        }
        if (tied_flag) {
            if(confirm(`${winner_name} won the game. Press ok to play again.`)) {
                window.location.reload();
            }
        }
    }
});
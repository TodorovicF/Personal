#include "TicTacToe.h"
#include <string>
#include <cmath>


//------------------------------------------------------------------------------
// initGame
// 
void TicTacToe::initGame() {
	cout << "WELCOME TO TICTACTOE!" << endl;

	cout << "Please enter Player One's name: ";
	cin >> PlayerOne;

	cout << "Please enter Player Two's name: ";
	cin >> PlayerTwo;

	if (PlayerOne.compare(PlayerTwo) != 0) {
		p1 = PlayerOne[0];
		p2 = PlayerTwo[0];
	}
	else {
		p1 = 'X';
		PlayerOne = PlayerOne + '1';
		p2 = 'O';
		PlayerTwo = PlayerTwo + '2';
	}

	cout << endl << endl;
}

//------------------------------------------------------------------------------
// displayBoard
// 
void TicTacToe::displayBoard() {
	int Size = tttBoard.getSize();
	int second = Size/3;
	int third = Size/3*2;

	for (int i = 0; i < Size; i++) {
		if (i == second || i == third) {
			cout << endl;
		}
		if (!getUsed(i)) {
			cout << "[" << i << "]";
		}
		else {
			cout << "[" << tttBoard.returnPlayer(i) << "]";
		}
	}
	cout << endl;
}

//------------------------------------------------------------------------------
// play
// 
void TicTacToe::play() {

	while(true) {
		displayBoard();
		if (checkWinner(p1) || checkWinner(p2)) {
			break;
		}
		movePrompt(p1);
		displayBoard();
		if (checkWinner(p1) || checkWinner(p2)) {
			break;
		}
		movePrompt(p2);
	}
	if (playAgain()) {
		clearGame();
		initGame();
		play();
	}
	else {
		exitMessage();
		saveToFile();
	}
}

//------------------------------------------------------------------------------
// playAgain
// 
bool TicTacToe::playAgain() {
	char input;
	cout << "Would you like to play again? ";

	while (true) {
		cin >> input;

		if (toupper(input) == 'Y') {
			return true;
		}
		else if (toupper(input) == 'N') {
			return false;
		}
		else {
			cout << "Invalid choice, please choose 'Y' or 'N'" << endl;
		}
	}
}

//------------------------------------------------------------------------------
// exitMessage
// 
void TicTacToe::exitMessage() {
	cout << "Thank you " << PlayerOne << " and " << PlayerTwo << " for playing!"
		 << endl << "See you next time!" << endl;
}

//------------------------------------------------------------------------------
// movePrompt
// 
void TicTacToe::movePrompt(char player) {
	int loc = 0;
	
	if (player == p1) {
		cout << PlayerOne << ", please make your move: ";
	}
	else {
		cout << PlayerTwo << ", please make your move: ";
	}

	// CHECK FOR VALID INPUT

	bool valid = false;
	while(!valid) {
		cin >> loc; // promt for location to set tile
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid integer between 0 and " << size 
				 <<  ": ";
		}
		else valid = true;
	}

	if (loc >= 0 && loc <= size) {
		if (!getUsed(loc)) {
			move(player, loc);
		}
		else {
			cout << "That location is already used!" << endl;
			movePrompt(player);
		}
	}
	else {
		cout << "Location not in range, please play again" << endl;
		movePrompt(player);
	}
}

//------------------------------------------------------------------------------
// move
// 
void TicTacToe::move(char player, int loc) {
	tttBoard.placeChip(player, loc);
}

//------------------------------------------------------------------------------
// getUsed
// 
bool TicTacToe::getUsed(int location) {
	if (tttBoard.isUsed(location)) {
		return true;
	}
	else return false;
}

//------------------------------------------------------------------------------
// getPlayer
// 
char TicTacToe::getPlayer(int location) {
	return getPlayerHelper(location);
}

//------------------------------------------------------------------------------
// getPlayerHelper
// 
char TicTacToe::getPlayerHelper(int location) {
	return tttBoard.returnAtLocation(location)->current;
}

//------------------------------------------------------------------------------
// checkWinner
// 
bool TicTacToe::checkWinner(char player) {

/*
Possible win situations

[X][X][X]
[ ][ ][ ]
[ ][ ][ ]

[ ][ ][ ]
[X][X][X]
[ ][ ][ ]

[ ][ ][ ]
[ ][ ][ ]
[X][X][X]

[X][ ][ ]
[ ][X][ ]
[ ][ ][X]

[ ][ ][X]
[ ][X][ ]
[X][ ][ ]

[X][ ][ ]
[X][ ][ ]
[X][ ][ ]

[ ][X][ ]
[ ][X][ ]
[ ][X][ ]

[ ][ ][X]
[ ][ ][X]
[ ][ ][X]

for loop 

*/
	if (getPlayer(0) == player && getPlayer(1) == player && getPlayer(2) == player) {
		cout << "Congratulations! " << player << " is the winner!" << endl;
		return true;
	}
	if (getPlayer(3) == player && getPlayer(4) == player && getPlayer(5) == player) {
		cout << "Congratulations! " << player << " is the winner!" << endl;
		return true;
	}
	if (getPlayer(6) == player && getPlayer(7) == player && getPlayer(8) == player) {
		cout << "Congratulations! " << player << " is the winner!" << endl;
		return true;
	}
	if (getPlayer(0) == player && getPlayer(3) == player && getPlayer(6) == player) {
		cout << "Congratulations! " << player << " is the winner!" << endl;
		return true;
	}
	if (getPlayer(1) == player && getPlayer(4) == player && getPlayer(7) == player) {
		cout << "Congratulations! " << player << " is the winner!" << endl;
		return true;
	}
	if (getPlayer(2) == player && getPlayer(5) == player && getPlayer(8) == player) {
		cout << "Congratulations! " << player << " is the winner!" << endl;
		return true;
	}
	if (getPlayer(0) == player && getPlayer(4) == player && getPlayer(8) == player) {
		cout << "Congratulations! " << player << " is the winner!" << endl;
		return true;
	}
	if (getPlayer(2) == player && getPlayer(4) == player && getPlayer(6) == player) {
		cout << "Congratulations! " << player << " is the winner!" << endl;
		return true;
	}
	if (allUsed()) {
		cout << "STALEMATE! The Game Is A Draw, No One Wins!" << endl;
		return true;
	}
	return false;
}

bool TicTacToe::allUsed() {
	for (int i = 0; i < size; i++) {
		if (!getUsed(i)) {
			return false;
		}
	}
	return true;
}

//------------------------------------------------------------------------------
// clearBoard
// 
void TicTacToe::clearGame() {
	tttBoard.clearBoard();
}

//------------------------------------------------------------------------------
// saveToFile
// 
void TicTacToe::saveToFile() {

}

#include "Board.h"

using namespace std;

class TicTacToe {
	static const int size = 9;
public:
	// Constructor
	TicTacToe() : tttBoard(size) { initGame(); }

	// Initialize and display the board
	void initGame();
	void displayBoard();
	
	// Play the game
	void play();
	bool playAgain();
	bool checkWinner(char);
	void exitMessage();
	bool allUsed(); 

	// Modify the game board
	void movePrompt(char);
	void move(char, int);

	
private:
	char getPlayer(int);
	void saveToFile();
	void clearGame();
	bool getUsed(int);
	char getPlayerHelper(int);

	Board tttBoard;  // tiles to store game info
	
	// Game Stats
	string PlayerOne;
	string PlayerTwo;
	char p1;
	char p2;
};

#include <iostream>

using namespace std;

class Board {
public:
	struct tiles {
		char current;
		bool used;
		int loc;
		tiles* next;
		tiles* prev;
	};

	Board();
	Board(int);
	void clearBoard();

	bool placeChip(char, int);
	

	bool isUsed(int);
	char returnPlayer(int);
	int getSize();
	tiles* returnAtLocation(int); // return tile at location

	void testOutput(int);

private:
	bool isUsedHelper(int);
	void testOutputHelper(int);
	bool placeChipHelper(char, int);
	bool setTile(tiles*, char);
	void clearBoardHelper();

	int getSizeHelper();
	char returnPlayerHelper(int);
	
	// Board and Stats
	tiles* board;  // Pointer to the game board
	int Size;	   // Size of the board
};

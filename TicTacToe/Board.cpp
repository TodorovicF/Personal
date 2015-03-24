#include "Board.h"

//------------------------------------------------------------------------------
// Default Constructor
// 
Board::Board() {
	board = nullptr;
}

//------------------------------------------------------------------------------
// Constructor
// 
Board::Board(int numTiles) {

	if (numTiles > 0) {
		// Create first tile
		tiles* firstTile = new tiles;
		board = firstTile;
		tiles* ptr = board;

		// Initialize parameters
		ptr->next = nullptr;
		ptr->prev = nullptr;
		ptr->used = false;
		ptr->current = '#';
		ptr->loc = 0;

		// create pointer for next prev
		tiles* prevPtr = board;

		// Create rest of tiles
		for (int i = 0; i < numTiles; i++) {
			tiles* createTile = new tiles;

			ptr->next = createTile;
			ptr->prev = prevPtr;
			ptr->used = false;
			ptr->current = '0';
			ptr->loc = i;

			prevPtr = ptr;
			ptr = ptr->next;
		}
		Size = numTiles;
	}
	else cout << "Please enter a value greater than 0" << endl;
}

//------------------------------------------------------------------------------
// testOutput
// 
void Board::testOutput(int size) {
	if (size > 0) {
		testOutputHelper(size);
	}
	else cout << "Size must be greater than 0" << endl;
}

//------------------------------------------------------------------------------
// testOutputHelper
// 
void Board::testOutputHelper(int size) {
	tiles* ptr = board;
	
	for (int i = 0; i < size; i++) {
		if (ptr != nullptr) {
			cout << "Used at location " << ptr->loc << " = " << ptr->used << ", current player = " << ptr->current << endl;
			ptr = ptr->next;
		}
	}
}

//------------------------------------------------------------------------------
// placeChip
// used to modify the board by adding a value to a specified location
bool Board::placeChip(char player, int location) {
	if (placeChipHelper(player, location))
	return true;
	else return false;
}

//------------------------------------------------------------------------------
// placeChipHelper
// 
bool Board::placeChipHelper(char player, int location) {
	if (setTile(returnAtLocation(location), player))
	return true;
	else {
		cout << "ERROR in placeChipHelper" << endl;
		return false;
	}
}

bool Board::setTile(tiles* ptr, char player) {
	ptr->current = player;
	ptr->used = true;
	return true;
}

//------------------------------------------------------------------------------
// returnPlayer
// 
char Board::returnPlayer(int location) {
	return returnPlayerHelper(location);
}

//------------------------------------------------------------------------------
// returnPlayer
// return current owner of tile
char Board::returnPlayerHelper(int location) {
	return returnAtLocation(location)->current;
}

//------------------------------------------------------------------------------
// returnAtLocation
// 
Board::tiles* Board::returnAtLocation(int location) {
	tiles* ptr = board;
	if (ptr != nullptr) {
		for (int i = 0; i < Size; i++) {
			if (i == location) {
				return ptr;
			}
			ptr = ptr->next;
		}
	}
}

//------------------------------------------------------------------------------
// getSize
// 
int Board::getSize() {
	return getSizeHelper();
}

//------------------------------------------------------------------------------
// getSizeHelper
// 
int Board::getSizeHelper() {
	return Size;
}

//------------------------------------------------------------------------------
// isUsed
// 
bool Board::isUsed(int loc) {
	return returnAtLocation(loc)->used;
}

void Board::clearBoard() {
	clearBoardHelper();
}

void Board::clearBoardHelper() {
	for (int i = 0; i < Size; i++) {
		tiles* ptr = returnAtLocation(i);
		for (int i = 0; i < Size; i++) {
			ptr->used = false;
			ptr->current = '0';
		}
	}
}

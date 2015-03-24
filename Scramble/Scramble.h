#include <iostream>
#include <istream>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <fstream>
#include <sstream>
#include "ExceptionsList.h"

using namespace std;

static int seed = INT_MIN;

class Scramble {
public:
	Scramble() : scrambleExceptions("exceptions.txt") {
	};
	void start();
	void processUserInput(char input);

	bool learnNames(string originalFileName);
	bool isValidInput(string input);
	void processScramble(string scrambledFileName);
	string scrambleWord(string originalWord);
	string scrambleShortWord(string shortWord);
	string extractFromFile(ifstream& originalFileName);
	void addToText(string wordToAdd, ofstream& scrambledFile);

private:
	ExceptionsList scrambleExceptions;
	void extractLineFromFile(string scrambledFileName, ifstream& originalFile);
	void extractWordFromLine(string extractedLine, ofstream& scrambledFile);
	void checkIfException(string extractedWord, ofstream& scrambledFile);
	void analyzeOpenedFile(ifstream& fileToAnalyze);
	void extractWordsAndAnalyze(string extractedLine);
	void checkIfLetter(string extractedWord, bool& isLetter);
	void checkIfCapitalLetter(string extractedWord, bool isLetter);
};

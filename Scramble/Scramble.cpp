#include "Scramble.h"

void Scramble::start() {
	string userInput = "0";
	
	while (true) {
		cout << " What operation would you like to perform?" << endl;
		cout << "1: Scramble a Text file." << endl;
		cout << "2: Add a word to the list of exceptions. (exceptions are words that will not be scrambled)" << endl;
		cout << "3: Remove a word from the list of exceptions." << endl;
		cout << "4: Display the list of exceptions." << endl;
		cout << "5: Learn names used in the text file." << endl;
		cout << "0: Exit the program." << endl << endl;
		cout << "What would you like to do: ";
		cin >> userInput;

		if (isValidInput(userInput)) {
			processUserInput(userInput[0]);
			break;
		}
		else {
			cout << endl << "------------------------------------------------" << endl;
			cout << "Input must be a single number, please try again." << endl;
			cout << "------------------------------------------------" << endl << endl;
		}
	}
}

bool Scramble::isValidInput(string input) {
	int inputLength = input.length();

	if (inputLength > 1 || inputLength == 0)
		return false;
	return true;
}

void Scramble::processUserInput(char input) {
	string forExceptions;
	string textFileName;

	if (input == '0');
	else if (input == '1') {
		cout << "Please enter the full name of the text file to Scramble: ";
		cin >> textFileName;
		processScramble(textFileName);
		start();
	}
	else if (input == '2') {
		cout << "Please enter the word to add to the list of exceptions: ";
		cin >> forExceptions;
		scrambleExceptions.addException(forExceptions);
		start();
	}
	else if (input == '3') {
		cout << "Please enter the word to remove from the list of exceptions: ";
		cin >> forExceptions;
		scrambleExceptions.removeException(forExceptions);
		start();
	}
	else if (input == '4') {
		scrambleExceptions.displayList();
		start();
	}
	else if (input == '5') {
		cout << "Please enter the full name of the text file to extract names from: ";
		cin >> textFileName;
		learnNames(textFileName);
		start();
	}
	else {
		cout << endl << "---------------------------------" << endl;
		cout << "'" << input << "' is invalid, please try again." << endl;
		cout << "---------------------------------" << endl << endl;
		start();
	}
}

string Scramble::scrambleShortWord(string shortWord) {
	string scrambledWord = shortWord;
	int length = shortWord.length();

	char toMove = scrambledWord[1];
	scrambledWord[1] = scrambledWord[length - 2];
	scrambledWord[length - 2] = toMove;

	return scrambledWord;
}

void Scramble::processScramble(string originalFileName) {
	string scrambledFileName = originalFileName;
	int beforeDot = scrambledFileName.rfind('.');
	ifstream originalFile;
	
	scrambledFileName.insert(beforeDot, "-SCRAMBLED");
	originalFile.open(originalFileName);

	if (originalFile.is_open()) {
		extractLineFromFile(scrambledFileName, originalFile);
	}
	else cout << "Text file could not be opened" << endl;
}

void Scramble::extractLineFromFile(string scrambledFileName, ifstream& originalFile) {
	string extractedLine;
	
	ofstream scrambledFile(scrambledFileName);
	while (getline(originalFile, extractedLine)) {
		extractWordFromLine(extractedLine, scrambledFile);
	}
	originalFile.close();
	scrambledFile.close();
}

void Scramble::extractWordFromLine(string extractedLine, ofstream& scrambledFile) {
	string extractedWord;
	istringstream streamFromLine(extractedLine);
	
	while (streamFromLine >> extractedWord) {
		checkIfException(extractedWord, scrambledFile);
	}
	scrambledFile << "\n";
}

void Scramble::checkIfException(string extractedWord, ofstream& scrambledFile) {
	string scrambledWord;

	if (!scrambleExceptions.isException(extractedWord)) {
		scrambledWord = scrambleWord(extractedWord);
		addToText(scrambledWord, scrambledFile);
	}
	else addToText(extractedWord, scrambledFile);
}

string Scramble::scrambleWord(string originalWord) {
	if (originalWord.length() < 4) return originalWord;
	if (scrambleExceptions.isException(originalWord)) return originalWord;
	if (originalWord.length() == 4)  {
		return scrambleShortWord(originalWord);
	}

	string scrambledWord = originalWord;
	int originalWord_Length = originalWord.length();
	int randomLetterArray_Length = originalWord_Length - 2;
	int* randomLetterArray = new int[randomLetterArray_Length];
	bool isWordLarge = false;

	for (int i = 0; i < randomLetterArray_Length; i++) {
		randomLetterArray[i] = i + 1;
	}

	srand(seed++);

	for (int i = 1; i < originalWord_Length - 1; i++) {
		int randomLetterPosition = rand() % (randomLetterArray_Length--);
		scrambledWord[i] = originalWord[randomLetterArray[randomLetterPosition]];

		for (int j = 0; j < randomLetterArray_Length; j++) {
			if (j >= randomLetterPosition)
				randomLetterArray[j] = randomLetterArray[j + 1];
		}

		if (randomLetterArray_Length == 0 && isWordLarge == true) {
			scrambledWord[i] = originalWord[randomLetterArray[0]];
			break;
		}

		isWordLarge = true;
	}
	delete randomLetterArray;
	scrambledWord[originalWord_Length] = originalWord[originalWord_Length];

	return scrambledWord;
}

void Scramble::addToText(string wordToAdd, ofstream& scrambledFile) {
	scrambledFile << wordToAdd << " ";
}

bool Scramble::learnNames(string fileName) {
	ifstream fileToAnalyze;
	
	fileToAnalyze.open(fileName);
	if (fileToAnalyze.is_open()) {
		analyzeOpenedFile(fileToAnalyze);
	}
	else cout << "Text file could not be opened" << endl;

	return false;
}

void Scramble::analyzeOpenedFile(ifstream& fileToAnalyze) {
	string extractedLine;

	while (getline(fileToAnalyze, extractedLine)) {
		extractWordsAndAnalyze(extractedLine);
	}
	fileToAnalyze.close();
}

void Scramble::extractWordsAndAnalyze(string extractedLine) {
	
	string extractedWord;
	bool isLetter = true;

	istringstream streamFromLine(extractedLine);
	while (streamFromLine >> extractedWord) {
		checkIfLetter(extractedWord, isLetter);
		checkIfCapitalLetter(extractedWord, isLetter);
	}
}

void Scramble::checkIfLetter(string extractedWord, bool& isLetter) {
	if (extractedWord[extractedWord.length()] == '.'
		|| extractedWord[extractedWord.length()] == '?'
		|| extractedWord[extractedWord.length()] == '!') {
		isLetter = false;
	}
}

void Scramble::checkIfCapitalLetter(string extractedWord, bool isLetter) {
	if (isupper(extractedWord[0])) {
		if (isLetter)
			scrambleExceptions.addException(extractedWord);
	}
}
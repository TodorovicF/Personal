#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "BinaryTree.h"

using namespace std;

class ExceptionsList {
public:
	ExceptionsList(string exceptionsFileName);
	bool addException(string exceptionToAdd);
	bool removeException(string exceptionToRemove);
	bool isException( string exception );
	void displayList();

private:
	bool addToInstance(string exceptionToAdd);
	bool addToFile(string exceptionToAdd);
	bool removeFromInstance(string exceptionToRemove);
	bool removeFromFile();
	void buildExceptionsFromFile(string exceptionsFileName);
	int exceptionFoundAt(string exception);
	bool rebuildExceptionsFile();

	string fileHeader = "[Add Exceptions that Scramble will ignore]";
	string fileName;
	vector<string> exceptionsGeneral;
	vector<string> exceptionsTextSpecific;
};

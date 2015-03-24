#include "ExceptionsList.h"

ExceptionsList::ExceptionsList(string exceptionsFileName) {
	fileName = exceptionsFileName;
	buildExceptionsFromFile(exceptionsFileName);
}

bool ExceptionsList::addException(string exceptionToAdd) {
	if (exceptionFoundAt(exceptionToAdd) < 0) {
		addToFile(exceptionToAdd);
		addToInstance(exceptionToAdd);
		return true;
	}
	return false;
}

bool ExceptionsList::removeException(string exceptionToRemove) {
	int exceptionLength = exceptionToRemove.length();
	if (removeFromInstance(exceptionToRemove)){
		removeFromFile();
		return true;
	}
	return false;
}

bool ExceptionsList::isException(string exception) {
	if (exceptionFoundAt(exception) >= 0)
		return true;
	return false;
}

void ExceptionsList::displayList() {
	int listSize = exceptionsGeneral.size();
	for (int i = 0; i < listSize; i++) {
		cout << exceptionsGeneral[i] << endl;
	}
}

//------------------------------------------------------------------------------
// Privates
//------------------------------------------------------------------------------

void ExceptionsList::buildExceptionsFromFile(string exceptionsFileName) {
	string exceptionToInsert;
	ifstream exceptionsFile;
	bool isTitle = true;

	exceptionsFile.open(exceptionsFileName);

	if (exceptionsFile.is_open()) {
		while (getline(exceptionsFile, exceptionToInsert)) {
			if (!isTitle && exceptionToInsert != "") {
				addToInstance(exceptionToInsert);
			}
			else isTitle = false;
		}
		exceptionsFile.close();
	}
}

bool ExceptionsList::addToInstance(string exceptionToAdd) {
	exceptionsGeneral.push_back(exceptionToAdd);
	return true;
}

bool ExceptionsList::addToFile(string exceptionToAdd) {
	string exception = exceptionToAdd;
	ofstream exceptionsFile;

	exceptionsFile.open(fileName, ios::app);
	if (exceptionsFile.is_open()) {
		exceptionsFile << "\n" << exceptionToAdd;
		exceptionsFile.close();
		return true;
	}
	return false;
}

bool ExceptionsList::removeFromInstance(string exceptionToRemove) {
	int index = 0;
	if ((index = exceptionFoundAt(exceptionToRemove)) >= 0) {
		exceptionsGeneral.erase(exceptionsGeneral.begin() + index);
		return true;
	}
	return false;
}

bool ExceptionsList::removeFromFile() {
	if (rebuildExceptionsFile())
		return true;
	return false;
}

bool ExceptionsList::rebuildExceptionsFile() {
	if (remove(fileName.c_str()) == 0) {
		ofstream newFile(fileName, ios::app);
		if (newFile.is_open()) {
			newFile << fileHeader << endl;
			for (int i = 0; i < exceptionsGeneral.size(); i++) {
				newFile << exceptionsGeneral[i] << endl;
			}
			newFile.close();
			return true;
		}
	}
	return false;
}

int ExceptionsList::exceptionFoundAt(string exception) {
	for (unsigned int index = 0; index < exceptionsGeneral.size(); index++) {
		if (exceptionsGeneral.at(index) == exception) {
			return index;
		}
	}
	return -1;
}

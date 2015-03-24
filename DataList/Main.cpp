
#include "DataList.h"

bool isWithinString(string wordA, string wordB) {
	int aLength = wordA.length();
	int bLength = wordB.length();
	int count = 0;
	bool found = false;
	int j = 0;

	for (int i = 0; i < bLength; i++) {
		for (j; j < aLength; j++) {
			if (wordA[i] == wordB[j]) {
				count++;
				found = true;
				break;
			}
			else {
				count = 0;
				found = false;
				break;
			}
		}
		if (found)
			j++;
		else j = 0;
	}
	if (count == bLength) {
		return true;
	}

	return false;
}


int main() {
	//DataList newList("myData.txt");
	string wordA = "computer";
	string wordB = "put";
	string wordA2 = "computer";
	string wordB2 = "cat";

	int num = 5;

	cout << &num << endl;

	cout << isWithinString(wordA, wordB) << endl;
	cout << isWithinString(wordA2, wordB2) << endl;

	//cout << newList << endl;
}

#include "RandomBag.h"
#include <iostream>

int main() {
	
	int inserts = 1000;
	int takeOneTest = 100;
	int sizeTest = 20;
	int isEmptyTest = 50;

	bool addItemTEST = true;
	bool takeOneTEST = true;
	bool sizeTEST = true;
	bool isEmptyTEST = true;

	// TEST addItem
	if (addItemTEST) {
		RandomBag<int> testBag1;
		for (int i = 0; i < inserts; i++) {
			testBag1.addItem(i);
		}
	}

	// TEST takeOne
	if (addItemTEST) {
		RandomBag<int> testBag2;
		for (int i = 0; i < inserts; i++) {
			testBag2.addItem(i);
		}
		for (int i = 1; i < takeOneTest; i++) {
			if (i % 3 > 0) {
				cout << testBag2.takeOne() << ", ";
			}
			else
				cout << testBag2.takeOne() << endl;
		}
	}

	// TEST size
	if (addItemTEST) {
		RandomBag<int> testBag3;
		for (int i = 0; i < sizeTest; i++) {
			testBag3.addItem(i);
			cout << testBag3.size() << endl;
		}
		for (int i = 0; i < sizeTest; i++) {
			testBag3.takeOne();
			cout << testBag3.size() << endl;
		}
	}

	// TEST isEmpty
	if (addItemTEST) {
		RandomBag<int> testBag4;
		if (testBag4.isEmpty()) {
			cout << "isEmpty test1 PASSED" << endl;
		}
		else cout << "isEmpty test1 FAILED" << endl;
		testBag4.addItem(5);
		if (testBag4.isEmpty()) {
			cout << "isEmpty test2 FAILED" << endl;
		}
		else cout << "isEmpty test2 PASSED" << endl;
		for (int i = 0; i < isEmptyTest; i++) {
			testBag4.addItem(i);
			cout << testBag4.size() << endl;
		}
		if (testBag4.isEmpty()) {
			cout << "isEmpty test3 FAILED" << endl;
		}
		else cout << "isEmpty test3 PASSED" << endl;
		for (int i = 0; i < isEmptyTest + 1; i++) {
			testBag4.takeOne();
		}
		if (testBag4.isEmpty()) {
			cout << "isEmpty test4 PASSED" << endl;
		}
		else cout << "isEmpty test4 FAILED" << endl;
	}
};

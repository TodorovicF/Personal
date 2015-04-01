#include "LinkedList.h"

int main() {
	int tests = 50;
	bool insert = true;
	bool remove = true;
	bool search = true;
	bool size = true;
	bool reverse = true;
	bool output = true;


	// TEST insert
	if (insert) {
		LinkedList myList;
		for (int i = 0; i < tests; i++) {
			myList.insert(i);
		}
	}
	if (remove) {
		// TEST remove
		LinkedList myList2;
		for (int i = 0; i < tests; i++) {
			myList2.insert(i);
		}
		for (int i = 0; i < tests; i++) {
			if (myList2.remove(i + 5)) {
				cout << "Successfully removed " << i + 5 << endl;
			}
			else cout << "Removal of " << i + 5 << " failed" << endl;
			if (myList2.remove(i)) {
				cout << "Successfully removed " << i << endl;
			}
			else cout << "Removal of " << i << " failed" << endl;
		}
	}
	// TEST search
	if (search) {
		LinkedList myList3;
		for (int i = 0; i < tests; i++) {
			myList3.insert(i);
		}
		for (int i = 0; i < tests; i++) {
			if (myList3.searchList(i + 10))
				cout << "Search for " << i + 10 << " succeded" << endl;
			else cout << "Search for " << i + 10 << " failed" << endl;
			if (myList3.searchList(-i))
				cout << "Search for " << -i << " succeded" << endl;
			else cout << "Search for " << -i << " failed" << endl;
			if (myList3.searchList(i))
				cout << "Search for " << i << " succeded" << endl;
			else cout << "Search for " << i << " failed" << endl;
		}
	}

	// TEST size
	if (size) {
		LinkedList myList4;
		for (int i = 0; i < tests; i++) {
			myList4.insert(i);
			cout << "Size of list is: " << myList4.getSize() << endl;
			myList4.insert(i + 7);
			cout << "Size of list is: " << myList4.getSize() << endl;
		}
		for (int i = 0; i < tests; i++) {
			myList4.remove(i);
			cout << "Size of list after removal: " << myList4.getSize() << endl;
			myList4.remove(i + 7);
			cout << "Size of list after removal: " << myList4.getSize() << endl;
		}
	}

	// TEST reverseList
	if (reverse) {
		LinkedList myList5;
		for (int i = 0; i < tests; i++) {
			myList5.insert(i);
		}
		myList5.reverseList();
	}

	// TEST outputList
	if (output) {
		LinkedList myList6;
		for (int i = 0; i < tests; i++) {
			myList6.insert(i);
		}
		myList6.outputList();
		myList6.reverseList();
		myList6.outputList();
		myList6.reverseList();
		myList6.outputList();
	}
}

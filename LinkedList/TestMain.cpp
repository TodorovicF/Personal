#include "LinkedList.h"

int main() {
	int links = 50000;
	
	if (true) {
		LinkedList<int> list1(links);

		for (int i = 0; i < links; i++) {
			int num = i;
			list1.insert(num);
		}
		// TEST searchList
		int toSearch = 1231254;
		if (list1.searchList(toSearch)) {
			cout << "searchList success" << endl;
		}
		else cout << "searchList NULL" << endl;

		// TEST remove
		int toRemove = 230000;
		if (list1.remove(toRemove)) {
			cout << "remove Success" << endl;
		}
		else cout << "remove failed" << endl;
	}
	cout << "list1 killed" << endl;
	
	if (true) {
		LinkedList<string> list2(links);

		for (int i = 0; i < links; i++) {
			int num = i;
			list2.insert("hello");
		}
	}
	cout << "list2 killed" << endl;

	if (true) {
		LinkedList<bool> list3(links);

		for (int i = 0; i < links; i++) {
			int num = i;
			list3.insert(false);
		}
		cout << "list3 killed" << endl;
	}

	if (true) {
		LinkedList<long> list4(links);

		for (int i = 0; i < links; i++) {
			int num = i;
			list4.insert(500000000);
		}
		cout << "list4 killed" << endl;
	}

	if (true) {
		LinkedList<char> list5(links);

		for (int i = 0; i < links; i++) {
			int num = i;
			list5.insert('z');
		}
		cout << "list5 killed" << endl;
	}
}
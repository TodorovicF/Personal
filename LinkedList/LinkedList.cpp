#include "LinkedList.h"

//------------------------------------------------------------------
// Default Constructor
LinkedList::LinkedList() {
	start = nullptr;
	size = 0;
}

//------------------------------------------------------------------
// destroyList
void LinkedList::destroyList(Node* node) {
	if (node != nullptr) {
		destroyList(node->next);
	}
	delete node;
	node = nullptr;
}

//------------------------------------------------------------------
// insert
void LinkedList::insert(int toInsert) {
	Node* current = start;
	if (current != nullptr) {
		while (current->next != nullptr) {
			current = current->next;
		}
	}
	Node* newData = new Node(toInsert);
	if (size > 0)
		current->next = newData;
	else start = newData;
	size++;
}

//------------------------------------------------------------------
// remove
bool LinkedList::remove(int toRemove) {
	if (size > 0) {
		Node* current = start;
		if (start->data == toRemove) {
			current = start->next;
			delete start;
			start = nullptr;
			start = current;
			size--;
			return true;
		}
		else {
			Node* previous = start;
			while (current != nullptr) {
				if (current->data == toRemove) {
					previous->next = current->next;
					delete current;
					current = nullptr;
					size--;
					return true;
				}
				else {
					previous = current;
					current = current->next;
				}
			}
		}
	}
	return false;
}
//------------------------------------------------------------------
// searchList
bool LinkedList::searchList(int toGet) {
	Node* current = start;
	while (current != nullptr) {
		if (current->data == toGet) return true;
		current = current->next;
	}
	return false;
}
//------------------------------------------------------------------
// searchList
int LinkedList::getSize() {
	return size;
}
//------------------------------------------------------------------
// reverseList
void LinkedList::reverseList() {
	if (size > 0) {
		Node* current = start;
		Node* previous = nullptr;
		while (start->next != nullptr) {
			start = start->next;
		}
		reverseListHelper(current, previous);
	}
}

void LinkedList::reverseListHelper(Node* current, Node* previous) {
	Node* temp = previous;
	Node* temp2 = current;
	if (current->next != nullptr) {
		previous = current;
		current = current->next;
		reverseListHelper(current, previous);
	}
	temp2->next = temp;
}

void LinkedList::outputList() {
	Node* current = start;
	if (size > 1) {
		do {
			cout << current->data << ", ";
			current = current->next;
		} while (current != nullptr);
		cout << endl;
	}
	else if (size > 0) cout << current->data << endl;
}

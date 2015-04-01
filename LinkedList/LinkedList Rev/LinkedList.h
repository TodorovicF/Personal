#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

//------------------------------------------------------------------
//  Class: LinkedList
//  Description: A simple nexted list template
//  Assumptions: 
//    - inthe data of the nexted list may be of any data type
//    - Has member functions "insert" and "remove"
//------------------------------------------------------------------

class LinkedList {
private:
	Node* start;
	int size;

	void destroyList(Node* toRemove);
	void reverseListHelper(Node* current, Node* previous);

public:
	LinkedList();
	~LinkedList() { destroyList(start); };

	void insert(int toInsert);
	bool remove(int toRemove);
	bool searchList(int toFind);
	int getSize();

	void reverseList();
	void outputList();

	// Relational Operators
	/*friend bool operator < (const Node& left, const Node& right) {
		return left.data < right.data;
	}
	friend bool operator >(const Node& left, const Node& right) {
		return left.data > right.data;
	}
	friend bool operator == (const Node& left, const Node& right) {
		return left.data == right.data;
	}
	friend bool operator != (const Node& left, const Node& right) {
		return left.data != right.data;
	}*/

	// Arithmetic Operators
	/*friend int operator + (const Node& right) {
		return this->data + right.data;
	}
	friend int operator - (const Node& right) {
		return this->data - right.data;
	}
	friend int operator * (const Node& right) {
		return this->data * right.data;
	}*/
};

#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------------------
//  Class: LinkedList
//  Description: A simple linked list template
//  Assumptions: 
//    - The data of the linked list may be of any data type
//    - Has member functions "insert" and "remove"
//------------------------------------------------------------------

template <class T>
class LinkedList {
private:
	struct Node {
		T data;
		Node* next;
	};
	
	void destroyList(Node*);
	Node* link;
	Node* current;

public:
	LinkedList(int);
	~LinkedList() { destroyList(this->link); };

	bool insert(T);
	bool remove(T);
	T* searchList(T);

	friend bool operator < (const Node& left, const Node& right) {
		return left.data < right.data;
	}
	friend bool operator > (const Node& left, const Node& right) {
		return left.data > right.data;
	}
	friend bool operator == (const Node& left, const Node& right) {
		return left.data == right.data;
	}
	friend bool operator != (const Node& left, const Node& right) {
		return left.data != right.data;
	}

	friend T operator + (const Node& right) {
		return this.data + right.data;
	}
	friend T operator - (const Node& right) {
		return this.data - right.data;
	}
	friend T operator * (const Node& right) {
		return this.data * right.data;
	}

};

//------------------------------------------------------------------
// Default Constructor
template<class T>
LinkedList<T>::LinkedList(int num) {
	if (num > 0) {
		Node* currPtr;
		Node* nextPtr;
		currPtr = new Node;
		link = currPtr;
		for (int i = 0; i < num-1; i++) {
			nextPtr = new Node;       // create new node
			nextPtr->next = NULL;  // set next to NULL
			currPtr->next = nextPtr;  // add new node to current
			currPtr = nextPtr;        // increment current
		}
	}
	else if (num == 0) {
		link = NULL;
	}
	current = link;
}

//------------------------------------------------------------------
// destroyList
template<class T>
void LinkedList<T>::destroyList(Node* node) {
	while(node) {
		Node* old = node;
		node = node->next;
		delete old;
	}
}

//------------------------------------------------------------------
// insert
template<class T>
bool LinkedList<T>::insert(T toIn) {
	current->data = toIn;
	if (current->next != NULL) {
		current = current->next;
	}
	return true;
}

//------------------------------------------------------------------
// remove
template<class T>
bool LinkedList<T>::remove(T toOut) {
	Node* curr;
	Node* prev;
	curr = link;
	while(curr) {
		if (curr->data == toOut) {
			prev->next = curr->next;
			delete curr;
			curr = NULL;
			return true;
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
	return false;
}

//------------------------------------------------------------------
// searchList
template<class T>
T* LinkedList<T>::searchList(T toGet) {
	Node* temp;
	temp = link;

	while (temp) {
		if (temp->data == toGet) {
			return &temp->data;
		}
		else {
			temp = temp->next;
		}
	}
	return NULL;
}

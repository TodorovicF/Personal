using namespace std;

template <class Type>
class BinaryTree {
private:
	struct Node {
		Type data;
		Node* left;
		Node* right;

		Node (Type dataIn) {
			data = dataIn;
			left = NULL;
			right = NULL;
		}
	};
	Node* start;
	int nodeCount;
	int height;

	bool insert(Node*& treeIterator, Type data);
	bool remove(Node*& treeIterator, Type data);
	int countNodes(Node*& current);
	int getHeight(Node*& current, int* currentMax);
	void deleteTree(Node*& current);

public:
	BinaryTree();
	~BinaryTree();
	int getTreeInfo();
	bool insertData(Type data);
	bool removeData(Type data);
	bool containsData(Type data);
};

template <class Type>
BinaryTree<Type>::BinaryTree() {
	start = nullptr;
	nodeCount = 0;
	height = 0;
}

template <class Type>
BinaryTree<Type>::~BinaryTree() {
	Node* current = start;
	deleteTree(current);
}

template <class Type>
int BinaryTree<Type>::countNodes(Node*& current) {
	if (current != nullptr) nodeCount++;

	if (current->left != nullptr) {
		countNodes(current->left);
	}
	if (current->right != nullptr) {
		countNodes(current->right);
	}
	return nodeCount;
}

template <class Type>
int BinaryTree<Type>::getHeight(Node*& current, int* currentMax) {
	if (current != nullptr)
}

template <class Type>
int BinaryTree<Type>::getTreeInfo() {
	Node* temp = start;
	nodeCount = 0;
	height = 0;
	int currentMax = 0;

	countNodes(temp);
	temp = start;
	getHeight(temp, currentMax);
	return 0;
}

template <class Type>
bool BinaryTree<Type>::insert(Node*& treeIterator, Type dataToAdd) {
	if (treeIterator == nullptr) {
		Node* stuff = new Node(dataToAdd);
		treeIterator = stuff;
		
		return true;
	}
	else if (dataToAdd < treeIterator->data) {
		insert(treeIterator->left, dataToAdd);
	}
	else {
		insert(treeIterator->right, dataToAdd);
	}
	return false;
}

template <class Type>
bool BinaryTree<Type>::insertData(Type dataToInsert) {
	Node* treeIterator = start;
	insert(treeIterator, dataToInsert);
	return true;
}

template <class Type>
bool BinaryTree<Type>::remove(Node*& treeIterator, Type dataToDelete) {
	if (treeIterator == nullptr) {
		return false;
	}
	else if (dataToDelete == treeIterator->data) {
		delete treeIterator;
		treeIterator = nullptr;
	}
	else if (dataToDelete < treeIterator->data) {
		remove(treeIterator->left, dataToDelete);
	}
	else if (dataToDelete > treeIterator->data) {
		remove(treeITerator->right, dataToDelete);
	}
	return false;
}

template <class Type>
void BinaryTree<Type>::deleteTree(Node*& current) {
	if (current != nullptr) {
		deleteTree(current->left);
		deleteTree(current->right);
		delete current;
		current = nullptr;
	}
}

template <class Type>
bool BinaryTree<Type>::removeData(Type dataToRemove) {
	Node* treeIterator;
	remove(treeIterator, dataToRemove);
	return true;
}

template <class Type>
bool BinaryTree<Type>::containsData(Type data) {

	return false;
}

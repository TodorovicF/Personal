#include <stdlib.h>

using namespace std;

/*****************************************************************************
Class RandomBag:
A Bag implementation in which items added can only be retrieved at random:
	- addItem: insert an object into the bag.
	- takeOne: remove and return a single object from the bag.
	- size: returns the current number of items in the bag.
	- isEmpty: true if bag contains no items, otherwise false.
******************************************************************************/

template<class T>
class RandomBag {
public:
	RandomBag();
	~RandomBag();

	void addItem(T itemToAdd);
	T takeOne();
	int size();
	bool isEmpty();

private:
	void expandBagByOne();

	T* bag;
	int sizeOfBag;
	int seed;
};

//------------------------------------------------------------------------------
// Constructor
template<class T>
RandomBag<T>::RandomBag() {
	bag = NULL;
	sizeOfBag = 0;
	seed = 1;
}

//------------------------------------------------------------------------------
// Destructor
template<class T>
RandomBag<T>::~RandomBag() {
	delete[] bag;
}

//------------------------------------------------------------------------------
// addItem
// Add a single object to the bag. Dynamically increases the bags size.
template<class T>
void RandomBag<T>::addItem(T itemToAdd) {
	expandBagByOne();
	bag[sizeOfBag - 1] = itemToAdd;
}

//------------------------------------------------------------------------------
// expandBagByOne
// Increase the bag's size by one.
template<class T>
void RandomBag<T>::expandBagByOne() {
	// setup new, larger bag
	int oldSize = sizeOfBag;
	sizeOfBag++;
	T* largerBag = new T[sizeOfBag];
	

	// move items from old bag to larger bag
	if (bag != NULL) {
		for (int i = 0; i < oldSize; i++) {
			T oldItem = bag[i];
			largerBag[i] = oldItem;
		}
	}

	// destroy old bag and replace with larger bag
	delete[] bag;
	bag = largerBag;
}

//------------------------------------------------------------------------------
// takeOne
// Remove an object from the bag. Decreases the size of the bag by one.
template<class T>
T RandomBag<T>::takeOne() {
	if (!isEmpty()) {
		// generate a new random number for the index
		seed *= 3;
		srand(seed);
		int index = rand() % sizeOfBag + 0;

		T itemToTake;
		T* smallerBag = new T[sizeOfBag - 1];
		
		// resize bag
		for (int i = 0; i < sizeOfBag; i++) {
			if (i < index)
				smallerBag[i] = bag[i];
			else if (i > index)
				smallerBag[i-1] = bag[i];
		}
		// grab item
		itemToTake = bag[index];
		
		// destroy old bag
		delete[] bag;
		bag = smallerBag;
		sizeOfBag--;

		return itemToTake;
	}
	else return NULL;
}

//------------------------------------------------------------------------------
// isEmpty
template<class T>
bool RandomBag<T>::isEmpty() {
	if (sizeOfBag > 0) return false;
	return true;
}

//------------------------------------------------------------------------------
// size
template<class T>
int RandomBag<T>::size() {
	return sizeOfBag;
}

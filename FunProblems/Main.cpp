#include "Problems.h"

int main() {
	Problems set;
	bool smallestDivisibleInRange = false;
	bool reverseString = true;

	// smallestDivisibleInRange
	if (smallestDivisibleInRange) {
		cout << set.smallestDivisibleInRange(1, 20) << endl;
		cout << set.smallestDivisibleInRange(1, 15) << endl;
		cout << set.smallestDivisibleInRange(1, 10) << endl;
		cout << set.smallestDivisibleInRange(1, 5) << endl;
		cout << set.smallestDivisibleInRange(5, 5) << endl;
		cout << set.smallestDivisibleInRange(10, 5) << endl;
		cout << set.smallestDivisibleInRange(0, 5) << endl;
		cout << set.smallestDivisibleInRange(-10, 5) << endl;
		cout << set.smallestDivisibleInRange(1, 25) << endl;
	}

	// reverseString
	if (reverseString) {
		cout << set.reverseString("Hello") << endl;
		cout << set.reverseString("Rhynoceros") << endl;
		cout << set.reverseString("Goodbye") << endl;
		cout << set.reverseString("Hi") << endl;
		cout << set.reverseString("I") << endl;
		cout << set.reverseString("") << endl;
	}
}

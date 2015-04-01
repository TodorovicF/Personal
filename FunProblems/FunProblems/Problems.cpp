#include "Problems.h"

//------------------------------------------------------------------------------
// smallestDivisibleInRange
// Assumptions:
//  - only positive numbers
//  - incorrect range returns -1
//  - equal range returns 1
//  - number not found returns 0
int Problems::smallestDivisibleInRange(int from, int to) {
	if (from <= 0) return -1;
	if (from > to) return -1;
	if (from < 0 || to < 0) return -1;
	if (from == to) return 1;
	bool done = false;
	int num = to-1;

	while (num <= INT_MAX) {
		num++;
		for (int i = 1; i <= to; i++) {
			if (num % i == 0) {
				done = true;
			}
			else {
				done = false;
				break;
			}
		}
		if (done) return num;
	}
	return 0;
}

string Problems::reverseString(string toReverse) {
	if (toReverse.length() <= 1) return toReverse;

	int strLength = toReverse.length();
	int reversals = strLength / 2;

	for (int i = 0; i < reversals; i++) {
		char temp = toReverse[i];
		toReverse[i] = toReverse[--strLength];
		toReverse[strLength] = temp;
	}
	return toReverse;
}

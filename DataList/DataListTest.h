#include "DataList.h"

class DataListTest {
private:
	const string attr = "attr";
	const string val = "val";
	const int numTimes = 100;
	bool testResult;

public:
	DataListTest();
	bool testAddField();
	bool testUpdateField();
	bool testRemoveField();
	bool testGetValue();
	bool testOutputOperator();
};

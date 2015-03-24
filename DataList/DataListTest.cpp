#include "DataListTest.h"

DataListTest::DataListTest() {
	testResult = true;
}

bool DataListTest::testAddField() {
	DataList testList;
	testResult = true;

	for (int i = 0; i < numTimes; i++) {
		testList.addField(attr + to_string(i), val + to_string(i));
	}

	for (int i = 0; i < numTimes; i++) {
		if (!testList.fieldExists(attr + to_string(i)))
			testResult = false;
	}
	return testResult;
}

bool DataListTest::testRemoveField() {
	DataList testList;
	testResult = true;

	for (int i = 0; i < numTimes; i++) {
		testList.addField(attr + to_string(i), val + to_string(i));
	}

	for (int i = 0; i < numTimes; i++) {
		testList.removeField(attr + to_string(i));
		if (testList.fieldExists(attr + to_string(i)))
			testResult = false;
	}
	return testResult;
}

bool DataListTest::testUpdateField() {
	DataList testList;
	testResult = true;

	for (int i = 0; i < numTimes; i++) {
		testList.addField(attr + to_string(i), val + to_string(i));
	}

	for (int i = 0; i < numTimes; i++) {
		testList.updateField(attr + to_string(i), val + to_string(i + 1));

	}
	return testResult;
}

bool DataListTest::testGetValue() {
	DataList testList;
	testResult = true;

	return testResult;
}

bool DataListTest::testOutputOperator() {
	DataList testList;
	testResult = true;

	return testResult;
}

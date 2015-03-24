#include "FieldTest.h"

FieldTest::FieldTest() {

}

bool FieldTest::testConstructor(string att, string val) {
	Field testField(att, val);

	if (testField.getAttribute() == att)
		if (testField.getValue() == val)
			return true;
	return false;
}

bool FieldTest::testIsField(string att, string val) {
	Field testField(att, val);

	if (testField.isField(att))
		return true;
	return false;
}

bool FieldTest::testOutputOperator(string att, string val) {
	Field testField(att, val);
	string expected = "Attribute: " + att + ", Value: " + val;
	stringstream test;
	
	test << testField;

	if (test.str() == expected)
		return true;
	return false;
}

void FieldTest::results(bool t1, bool t2, bool t3) {
	if (t1) {
		cout << "Constructor Test Passed" << endl;
	}
	else {
		cout << "Constructor Test Failed" << endl;
	}
	if (t2) {
		cout << "isField Test Passed" << endl;
	}
	else {
		cout << "isField Test Failed" << endl;
	}
	if (t3) {
		cout << "Output Operator Test Passed" << endl;
	}
	else {
		cout << "Output Operator Test Failed" << endl;
	}
}

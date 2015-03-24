/*
Filip Todorovic
Class Field: meant to be used as a node for the DataList class to store
lists of Attribute/Value pairs loaded from text files.
*/
#include <string>
#include <array>
#include <iostream>
#pragma once
using namespace std;

/*
Class Field:
	A class to be used as a data node within a data structure. It holds
	two strings, an attribute name and its value. Created to be used
	to store information about a system.
	Example Use:
		Attribute: color Value: black
		Attribute: height Value: 100ft
		...
	Functions:
		- Default Constructor: initialize attribute and value to "".
		- addAttribute: insert an attribute name, with no value.
		- addValue: add a value ONLY if attribute has been set.
		- isField: compares the parameter string to 'attribute'.
		- getAttribute: returns the string 'attribute'.
		- getValue: returns the string 'value'.
		- operator<<: output the atttribute and value to the console.
*/

class Field {
private:
	string attribute;
	string value;
public:
	Field();
	Field(string attr, string val);
	void addAttribute(string attr);
	bool addValue(string val);
	bool isField(string attr);
	string getAttribute();
	string getValue();
	friend ostream& operator<<(std::ostream& stream, const Field& obj);
};

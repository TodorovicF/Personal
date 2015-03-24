/*
Filip Todorovic
Class DataList: meant to hold information about a system in the form of
	'attribute'/'value' pairs.
Next Steps: 
	- Allow for saving list to file
	- Allow for categories or groups of attribute/value pairs:
		- example: User: James
				       Age: 28
					   Height: 6ft
					   Weight: 175lbs
				   User: Jones
					   Age: 32
					   Height: 5ft 9in
					   Weight: 196lbs
*/
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Field.h"

using namespace std;
/*
Class DataList:
	A Class to hold information loaded from a file or added manually as Field 
	nodes with "Attribute"/"Value" pairs. A Vector 'list' holds the Field nodes 
	and a filename string is stored to load and save to file.
	Assumptions:
		- files loaded must be of extension .txt.
		- file contents must begin and end with an attribute name followed by a 
		  ':' delimiter, a space and a value.
		- 'attribute' and 'value' strings may contain multiple words separated 
		  by spaces.
	Functions:
		- Default Constructor: initiates the fileName to "".
		- Constructor: build the list with a text file of name 'file'.
		- setFileName: sets a name for the fileName member variable.
		- addField: add a field of attribute 'attr' and value 'val' to the list.
		- updateField: update the value of a specified attribute.
		- removeField: remove a field by attribute 'attr'.
		- fieldExists: search if a field of attribute 'attr' exists.
		- getValue: return the string of 'value' for an attribute 'attr'.
		- operator<<: output the list to console.
*/
class DataList {
private:
	vector<Field> list;
	string fileName;

	Field* getField(string attr);
	void insertFieldFromString(string singleField);

public:
	DataList();
	DataList(string file);
	void setFileName(string file);
	bool addField(string attr, string val);
	bool updateField(string attr, string val);
	bool removeField(string attr);
	bool fieldExists(string attr);
	string getValue(string attr);
	friend ostream& operator<<(ostream& stream, const DataList& listToPrint);
};

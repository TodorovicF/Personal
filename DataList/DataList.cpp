#include "DataList.h"

DataList::DataList() {
	fileName = "";
}

DataList::DataList(string file) {
	fileName = file;
	string singleField;
	ifstream fileStream;

	fileStream.open(fileName);
	if (fileStream.is_open()) {
		while (getline(fileStream, singleField)) {
			if (!singleField.empty())
				insertFieldFromString(singleField);
		}
	}
	fileStream.close();
}

void DataList::setFileName(string file) {
	fileName = file;
}

bool DataList::addField(string attr, string val) {
	if (!fieldExists(attr)) {
		list.push_back(Field(attr, val));
		return true;
	}
	else return false;
}

bool DataList::updateField(string attr, string val) {
	Field* toUpdate = getField(attr);
	if (toUpdate != nullptr) {
		(*toUpdate).addValue(val);
		return true;
	}
	return false;
}

bool DataList::removeField(string attr) {
	int listSize = list.size();

	for (int i = 0; i < listSize; i++) {
		if (list[i].isField(attr)) {
			list.erase(list.begin() + i);
			return true;
		}
	}
	return false;
}

string DataList::getValue(string attr) {
	return (*getField(attr)).getValue();
}

bool DataList::fieldExists(string attr) {
	int listSize = list.size();

	for (int i = 0; i < listSize; i++) {
		if (list[i].isField(attr)) {
			return true;
		}
	}
	return false;
}

Field* DataList::getField(string attr) {
	int listSize = list.size();

	for (int i = 0; i < listSize; i++) {
		if (list[i].isField(attr)) {
			return &list[i];
		}
	}
	return nullptr;
}

void DataList::insertFieldFromString(string singleField) {
	istringstream stream(singleField);
	string attr = "";
	string val = "";
	char delimeter = ':';

	getline(stream, attr, delimeter);
	getline(stream, val);

	addField(attr, val);
}

ostream& operator<<(ostream& stream, const DataList& listToPrint) {
	int listSize = listToPrint.list.size();

	for (int i = 0; i < listSize; i++) {
		stream << listToPrint.list[i] << endl;
	}
	return stream;
}


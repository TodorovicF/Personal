#include "Field.h"

Field::Field() {
	attribute = "";
	value = "";
}

Field::Field(string attr, string val) {
	attribute = attr;
	value = val;
}

void Field::addAttribute(string attr) {
	attribute = attr;
}

bool Field::addValue(string val) {
	if (attribute != "") {
		value = val;
		return true;
	}
	return false;
}

bool Field::isField(string attr) {
	if (attribute == attr)
		return true;
	return false;
}

string Field::getAttribute() {
	return attribute;
}

string Field::getValue() {
	return value;
}

ostream& operator<<(ostream& stream, const Field& field) {
	stream << field.attribute << ": " << field.value;
	return stream;
}

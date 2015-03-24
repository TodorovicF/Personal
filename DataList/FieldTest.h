#include "Field.h"
#include <sstream>
using namespace std;

class FieldTest {
public:
	FieldTest();
	bool testConstructor(string att, string val);
	bool testIsField(string att, string val);
	bool testOutputOperator(string att, string val);
	void results(bool t1, bool t2, bool t3);
};

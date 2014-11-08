#ifndef HEADER_OBJECT_HPP
#define HEADER_OBJECT_HPP

#include <string>
using namespace std;

class Shape {
public:
	virtual string toString() {
		return "Default shape";
	}

	virtual ~Shape() {};

};


#endif
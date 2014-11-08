#ifndef HEADER_RECTANGLE_HPP
#define HEADER_RECTANGLE_HPP

using namespace std;

#include "Shape.h"

class Rectangle : public Shape {
public:

	Rectangle(float side1, float side2) : side1_(side1), side2_(side2) {};

	virtual string toString() {
		return "Rectangle [" + to_string(side1_) + "," +  to_string(side2_) + "]";
	}

private:
	float side1_;
	float side2_;
};

#endif
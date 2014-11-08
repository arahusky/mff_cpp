#ifndef HEADER_TRIANGLE_HPP
#define HEADER_TRIANGLE_HPP

using namespace std;

#include "Shape.h"

class Triangle : public Shape {
public:

	Triangle(float side1, float side2, float side3) : side1_(side1), side2_(side2), side3_(side3) {};

	virtual string toString() {
		return "Triangle [" + to_string(side1_) + "," +  to_string(side2_) + "," + to_string(side3_) + "]";
	}

private:
	float side1_;
	float side2_;
	float side3_;
};

#endif
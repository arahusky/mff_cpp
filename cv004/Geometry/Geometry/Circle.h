#ifndef HEADER_CIRCLE_HPP
#define HEADER_CIRCLE_HPP

#include "Shape.h"

class Circle : public Shape {
public:

	Circle(float radius) : radius_(radius) {};

	virtual string toString() {
		return "Circle with radius " + std::to_string(radius_);
	}

private:
	float radius_;
};

#endif
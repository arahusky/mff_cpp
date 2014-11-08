#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>

static char delimiter = ';';

std::ostream& operator<<(std::ostream& o, Shape* s){
	return o << s->toString();
}

float parseNextFloat(string & str) {
	try {
	int startPos = str.find_first_of("=");
	int endPos = str.find_first_of(delimiter);

	string stringFloat = str.substr(startPos + 1, endPos - startPos - 1);
	float f = stof(stringFloat);

	str = str.substr(endPos + 1);
	return f; }
	catch (invalid_argument ) {
		cout << "You passed an invalid number. Marked as maxFloat" << endl;
		return numeric_limits<float>::quiet_NaN(); 
	}
}

int main(int argc, char** argv){

	if (argc != 2) {
		cout << "Wrong number of parameters!" << endl;
		cout << argc;
		return 1;
	}


	vector<unique_ptr<Shape>> list;
	string fileName = argv[1];
	ifstream myfile(fileName);

	if (!myfile.is_open()) {
		cout << "File can not be opened!";
		return 1;
	}

	cout << "Opening file" << endl;

	string line;
	while (getline(myfile, line)) {
		if (line.length() == 0) {
			cout << "Malformed line found. Closing.";
			return 1;
		}

		switch (line[0])
		{
		case 'T': 
			{
				float side1 = parseNextFloat(line);
				float side2 = parseNextFloat(line);
				float side3 = parseNextFloat(line);
				list.push_back(unique_ptr<Shape>(new Triangle(side1, side2, side3)));
			}	
			break;
		case 'K':
			{
				float radius = parseNextFloat(line);
				list.push_back(unique_ptr<Shape>(new Circle(radius))); 
			}
			break;
		case 'O': 
			{
				float side1 = parseNextFloat(line);
				float side2 = parseNextFloat(line);
				list.push_back(unique_ptr<Shape>(new Rectangle(side1,side2)));
			}
			break;
		default:
			cout << "Malformed line found (no such shape). Closing.";
			return 1;
		}
	}

	cout << "Closing file" << endl;
	myfile.close();

	cout << "Listing records ... " << endl;
	for (const auto & o : list){
		cout << o.get() << endl;
	}

	getchar();

	return 0;
}

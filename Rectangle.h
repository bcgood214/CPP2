#pragma once
#include <string>
#include "Shape.h"
using std::string;

class Rectangle: public Shape
{
public:
	Rectangle(string name, int x, int y, int width, int height);
	Rectangle();
	~Rectangle();
	virtual void draw();
};


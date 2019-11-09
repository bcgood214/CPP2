#pragma once
#include <string>
#include "Shape.h"
using std::string;

class Oval: public Shape
{
public:
	Oval(string name, int x, int y, int width, int height);
	Oval();
	~Oval();
	virtual void draw();
};


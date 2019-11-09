#pragma once
#include <string>
using std::string;

class Shape
{
protected:
	string name;
	int x, y, width, height;
	float r, g, b;
public:
	Shape(string name, int x, int y, int width, int height);
	Shape();
	~Shape();
	virtual void draw();
	string getName();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	bool pointInShape(int pointX, int pointY);
	void changeColor();
};


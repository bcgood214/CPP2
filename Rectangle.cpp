#include "Rectangle.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"


Rectangle::Rectangle()
{
	name = "Rectangle";
	x = 0;
	y = 0;
	width = 10;
	height = 10;
}

Rectangle::~Rectangle()
{
}

Rectangle::Rectangle(string name, int x, int y, int width, int height) :
	Shape(name, x, y, width, height)
{
}

void Rectangle::draw()
{
	glColor3f(this->r, this->g, this->b); // Change to blue
	glBegin(GL_QUADS);  // Use GL_LINE_LOOP for hollow
	glVertex2f(x, y); // x1,y1
	glVertex2f(x + width, y); // x2, y1
	glVertex2f(x + width, y + height); // x2, y2
	glVertex2f(x, y + height); // x1, y2
	glEnd();
}

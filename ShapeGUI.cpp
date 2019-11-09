// CSCE A211
// Graphics Framework by Matthew Devins
// This code uses OpenGL and demonstrates drawing some text and some
// simple shapes, pixels, and color changes.
//
// To the reader: You only need to focus on the code in the "display" function
// for now.

#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"

#include <stdio.h>
#include <string>
#include <math.h>

// **** Includes for our shape classes
#include "Oval.h"
#include "Rectangle.h"
#include "Shape.h"

using std::string;

void init();
void display();
void handleButton(int button, int state, int x, int y);
void printText(int x, int y, string str);

void* font = GLUT_BITMAP_TIMES_ROMAN_24;//GLUT_STROKE_ROMAN;
const int WIDTH = 720;
const int HEIGHT = 480;

static int screenx = 0;
static int screeny = 0;

// ***** The architecture of openGL is such that it is easiest for us to make
// ***** global variables for the objects we want to draw.  In this case we have an array
// ***** or three ovals and three rectangles.
Shape* shapes[6];


int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Just A Window");

	init();
	glutDisplayFunc(display);
	glutMouseFunc(handleButton);

	glutMainLoop();

	return 0;
}

void init()
{

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(screenx, screenx + WIDTH, screeny + HEIGHT, screeny);


	// **** This is where we create the ovals and rectangles that will be
	// **** drawn in the display function
	// Create three ovals
	shapes[0] = new Oval("Oval 1", 10, 10, 100, 100);
	shapes[1] = new Oval("Oval 2", 200, 10, 150, 50);
	shapes[2] = new Oval("Oval 3", 10, 200, 200, 100);

	// Create three rectangles
	shapes[3] = new Rectangle("Rect 1", 400, 50, 100, 75);
	shapes[4] = new Rectangle("Rect 2", 200, 300, 75, 100);
	shapes[5] = new Rectangle("Rect 3", 10, 320, 120, 40);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// This loops through and draws all the ovals and rectangles
	for (int i = 0; i < 6; i++)
	{
		shapes[i]->draw();
	}

	glutSwapBuffers();
	glFlush();

	return;
}


void handleButton(int button, int state, int x, int y)
{
	static int index = -1;

	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			// If the mouse is clicked, go through our ovals and rectangles
			// and see if the click was inside one of the shapes.  If so, display the name.
			for (int i = 0; i < 6; i++)
			{
				if (shapes[i]->pointInShape(x, y))
				{
					glClear(GL_COLOR_BUFFER_BIT);
					shapes[i]->changeColor();
					shapes[i]->draw();
					glColor3f(1, 1, 1);
					printText(x + 30, y + 30, "You clicked " + shapes[i]->getName());
					glutSwapBuffers();
					glFlush();
				}
			}

		}
		if (state == GLUT_UP)
		{
			display();
		}

	}
}


// This function prints a string of text on the screen at coordinate x,y
void printText(int x, int y, string str)
{
	int i, length;

	glRasterPos2f(x, y);
	length = str.length();
	for (i = 0; i < length; i++)
	{
		glutBitmapCharacter(font, str[i]);
	}
}

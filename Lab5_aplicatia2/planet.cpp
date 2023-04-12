/*
 *  Programul arata cum se compun transformarile de rotatie si de translatie pentru desenarea obiectelor rotite sau translatate.
 *  Interactiune: left, right, up, down
 */
#include "glos.h"

#include "gl.h"
#include "glu.h"
#include "glaux.h"

static int year = 0, day = 0;

void CALLBACK dayAdd()
{
	day = (day + 10) % 360;
}

void CALLBACK daySubtract()
{
	day = (day - 10) % 360;
}

void CALLBACK yearAdd()
{
	year = (year + 5) % 360;
}

void CALLBACK yearSubtract()
{
	year = (year - 5) % 360;
}

void CALLBACK display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);

	glColor3f(1.0, 1.0, 1.0);

	// Soarele
	glColor3f(1.0, 1.0, 0.0); // galben
	auxWireSphere(1.0);

	// Pamantul	
	glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 1.0); // albastru
	auxWireSphere(0.2);

	glFlush();
}

void myInit() {
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
	auxInitPosition(0, 0, 800, 600);
	auxInitWindow("Transformari compuse");
	myInit();
	auxKeyFunc(AUX_LEFT, yearSubtract);
	auxKeyFunc(AUX_RIGHT, yearAdd);
	auxKeyFunc(AUX_UP, dayAdd);
	auxKeyFunc(AUX_DOWN, daySubtract);
	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return 0;
}

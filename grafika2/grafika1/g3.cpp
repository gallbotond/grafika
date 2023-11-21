// Pontok.cpp : Defines the entry point for the application.
//

#include "framework.h"
//#include "lab4.h"
#include <stdlib.h>
#include "glut.h"
#include <math.h>
#include "Resource.h"

//static GLfloat spin = 0.0;

GLdouble posX, posY, posZ, omega1, omega2, x2, y2;


int GoTo(double x, double y)
{
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);
	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	GLdouble l1 = 20.0;
	GLdouble l2 = 20.0;

	omega2 = acos((posX * posX + posY * posY - l1 * l1 - l2 * l2) / (2 * l1 * l2));
	omega1 = atan2((posY * (l1 + l2 * cos(omega2)) - posX * l2 * sin(omega2)), (posX * (l1 + l2 * cos(omega2)) + posY * l2 * sin(omega2)));
	if (!isnan(omega1) && !isnan(omega2)) {
		x2 = l1 * cos(omega1);
		y2 = l2 * sin(omega1);
		posX = l2 * cos(omega1 + omega2) + x2;
		posY = l2 * sin(omega1 + omega2) + y2;
		return 1;
	}
	return 0;
}
void MouseMove(int x, int y)
{
	if (GoTo(x, y) == 1)
		glutPostRedisplay();
}
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);         // a törl?szín a fekete 
	glShadeModel(GL_FLAT);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);             //töröljük a képerny?t
	glPushMatrix();
	glEnable(GL_POINT_SMOOTH);

	glPointSize(15);

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(x2, y2);
	glVertex2i(0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(posX, posY);
	glVertex2i(x2, y2);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(posX, posY);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(0, 0);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(x2, y2);
	glEnd();

	glPopMatrix();                                         // puffer-csere
	glutSwapBuffers();
	glFlush();                                             // rajzolj!
}

void keyboard(unsigned char key, int x, int y)              // billent?kezelés 
{
	switch (key)
	{
	case 27:                                                // ha escape-et nyomtam 
		exit(0);                                           // lépjen ki a programból 
		break;
	}
}


void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-50, 50, -50 * (GLfloat)h / (GLfloat)w,
			50 * (GLfloat)h / (GLfloat)w, -1.0, 1.0);
	else
		glOrtho(-50 * (GLfloat)w / (GLfloat)h,
			50 * (GLfloat)w / (GLfloat)h, -50, 50, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int APIENTRY wWinMain(IN HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, IN LPWSTR    lpCmdLine, IN int       nCmdShow)

{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // az ablak kétszeresen pufferelt,és RGB módú 
	glutInitWindowSize(700, 600);                // az ablak 700x600-as 
	glutInitWindowPosition(100, 100);            // az ablak bal fels? sarkának koordinátája 
	glutCreateWindow("Pontok");                  // neve Pontok 
	init();                                      // inicializálás 
	glutDisplayFunc(display);                    // a képerny? események kezelése 
	glutKeyboardFunc(keyboard);                  // billenty?zet események kezelése 
	glutReshapeFunc(reshape);					  // újrarajzolás nagyításkor, kicsinyítéskor
	//glutMouseFunc(mouse);						  // egérkezelés
	glutPassiveMotionFunc(MouseMove);
	glutMainLoop();                              // belépés az esemény hurokba... 
	return 0;
}
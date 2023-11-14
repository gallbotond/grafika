// grafika1.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "grafika1.h"




/*
   Rajzoljunk:
	  -egy piros pontot a (10, 15),
	  -egy zöld pontot az (50, 10) és
	  -egy kék pontot a (-30, -10) koordinátákra!

   A színtér forogjon!

   (Az ablak legyen 700*600-as méretû.)
*/


#include <stdlib.h>
#include "glut.h"


static GLfloat spin = 0.0;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);         // a törlõszín a fekete 
	glShadeModel(GL_FLAT);
}

void display(void)

{

	int ss = 100;
	for (size_t k = 0; k < ss; k++)
	{
		glClear(GL_COLOR_BUFFER_BIT);             //töröljük a képernyõt
		glPushMatrix();
		glEnable(GL_POINT_SMOOTH);
		glRotatef(spin, 0.0, 0.0, 1.0);
		glPointSize(15);                       // piros szín 
		glVertex2i(10, 15);
		k *= 3;
		int kk = ss - k;
		kk *= 3;
		int s = 3 * ss;

		glBegin(GL_POINTS);                                    // pontokat fogunk specifikálni 
		glColor3f(1.0, 0.0, 0.0);
		// egy pont a (s, 15) koordinátába 
		for (size_t i = 0; i < s; i += 3)
		{
			for (size_t j = 0; j < s; j += 3)
			{
				glVertex2i(i, j);
			}
		}
		// pontokat fogunk specifikálni 
		glBegin(GL_POINTS);                                    // pontokat fogunk specifikálni 
		glColor3f(0.0, 1.0, 0.0);
		for (size_t i = 0; i < s; i += 3)
		{
			for (size_t j = 0; j < s; j += 3)
			{
				if (i == k)
					glVertex2i(i, j);
			}
		}

		// pontokat fogunk specifikálni 
		glBegin(GL_POINTS);                                    // pontokat fogunk specifikálni 
		glColor3f(0.0, 0.0, 1.0);
		for (size_t i = 0; i < s; i += 3)
		{
			for (size_t j = 0; j < s; j += 3)
			{
				if (i == k)
					glVertex2i(j, i);
			}
		}

		//Sleep(10);

		glColor3f(0.0, 1.0, 0.0);                         // zöld szín 
		glVertex2i(50, 10);                               // még egy pont 
		glColor3f(0.0, 0.0, 1.0);                         // kék szín 
		glVertex2i(-30, -10);                             // és még egy pont 
		glEnd();
		glPopMatrix();                                         // puffer-csere
		glutSwapBuffers();
		glFlush();
	}
	// rajzolj!
}

void keyboard(unsigned char key, int x, int y)              // billentûkezelés 
{
	switch (key)
	{
	case 27:                                                // ha escape-et nyomtam 
		exit(0);                                           // lépjen ki a programból 
		break;
	}
}

void spinDisplay(void)
{
	spin = spin + .5;
	if (spin > 360)
		spin = spin - 360;
	glutPostRedisplay();                                     // újrarajzolás
}

void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay);
		if (state == GLUT_UP)
			glutIdleFunc(NULL);
		break;
	default:
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


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // az ablak kétszeresen pufferelt,és RGB módú 
	glutInitWindowSize(700, 600);                // az ablak 700x600-as 
	glutInitWindowPosition(100, 100);            // az ablak bal felsõ sarkának koordinátája 
	glutCreateWindow("Pontok");                  // neve Pontok 
	init();                                      // inicializálás 
	glutDisplayFunc(display);                    // a képernyõ események kezelése 
	glutKeyboardFunc(keyboard);                  // billentyûzet események kezelése 
	glutReshapeFunc(reshape);					  // újrarajzolás nagyításkor, kicsinyítéskor
	//glutMouseFunc(mouse);	

	glutIdleFunc(spinDisplay);// egérkezelés
	glutMainLoop();                              // belépés az esemény hurokba... 
	return 0;
}





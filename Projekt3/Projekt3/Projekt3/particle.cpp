#include <time.h>
#include <cmath>
#include <windows.h>
#include "glut.h"

float hatar = 1;
float X = 0, Y = 0;
const int MAX_RESZECSKEK = 13000;
const int MIN_RESZECSKEK = 100;
int AktReszecske = 1;
float pozX[MAX_RESZECSKEK], pozY[MAX_RESZECSKEK];

void ReszecskeMozgatas(int reszecskek)
{
	srand(time(NULL));
	float ujX;
	Sleep(10);
	glColor3d(3, 1, 0);
	float hatar2 = 5;
	for (int i = 0; i < reszecskek; ++i)
	{
		// Tuz reszecskek

		ujX = rand() % 3 + 1;
		int temp1 = rand() % 10 + 1;
		int temp2 = rand() % 30 + 1;
		//legszelso
		if (ujX == 1 && pozX[i] < 0.3 && pozY[i] < hatar) {
			pozX[i] += temp2 * .0001;
			pozY[i] += temp1 * 0.0002 + (pow(pozX[i], 3) * 0.5 + pow(pozX[i], 3) * 20);
		}
		else if (ujX == 3 && pozX[i] < 0.2 && i < 50) {
			pozX[i] += temp2 * .0001;
			pozY[i] += temp1 * 0.002 + (pow(pozX[i], 3) * 0.5 + pow(pozX[i], 2) * 10);
		}
		else if (ujX == 2 && pozX[i] < 0.3 && pozY[i] < hatar) {
			pozX[i] += temp2 * .0001;
			pozY[i] += temp1 * 0.002 + (pow(pozX[i], 3) * 0.5 + pow(pozX[i], 3) * 10);
		}
		else if (ujX == 4 && pozX[i] < 0.2 && pozY[i] < hatar) {
			pozX[i] += temp2 * .0001;
			pozY[i] += temp1 * 0.002 + (pow(pozX[i], 4) * 0.5 + pow(pozX[i], 2) * 6);
		}
		else {
			pozY[i] = 0;
			pozX[i] = 0;
		}
		if (pozY[i] > hatar2) {
			pozY[i] = 0;
			pozX[i] = 0;
		}
	}
}

void Reshape(int height, int width)
{
	glViewport(0, 0, width, height);
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (float)height / (float)width, 1, 100);
	glMatrixMode(GL_MODELVIEW);
}

void Draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glColor3f(2.64, 0.16, 0.16);
	glTranslated(0, -0.9, 0);
	glBegin(GL_QUADS);
	glVertex3f(-.01, -0.2, -2);
	glVertex3f(.01, -0.2, -2);
	glVertex3f(.03, 0, -2);
	glVertex3f(-.03, 0, -2);
	glEnd();
	glPopMatrix();
	float R, G, B;
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < MAX_RESZECSKEK; ++i)
	{
		R = 1;
		G = rand() % 75 + 80;
		B = 0;
		glColor3d(R, 100 / 255 + (G / 255), B);
		glVertex3f(X - .009, Y - .009, -2);
		glVertex3f(X + .009, Y - .009, -2);
		glVertex3f(X + .009, Y + .009, -2);
		X = pozX[i];
		Y = -0.9 + pozY[i];

		// Tukrozes a fakja masik oldalahoz
		glVertex3f(-X - .009, Y - .009, -2);
		glVertex3f(-X + .009, Y - .009, -2);
		glVertex3f(-X + .009, Y + .009, -2);
	}
	glEnd();
	glPopMatrix();
	Sleep(.5);
	ReszecskeMozgatas(AktReszecske);
	if (AktReszecske != MAX_RESZECSKEK) ++AktReszecske;
	glutPostRedisplay();
	glutSwapBuffers();
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	}
}

void init()
{
	const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
	const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat high_shininess[] = { 100.0f };
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tuz reszecskekkel");
	init();
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Draw);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	return 0;
}
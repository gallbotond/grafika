// Open3D.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include "glut.h"
#include <math.h>
#include <string.h>
#include<time.h>

float xRot = 0.0f;
float yRot = 0.0f;
float yRot2 = 0.0f;
float r = 5.0f;
GLboolean bSwtich = 0;

bool animate = false;
float szog = 0.0;
int elojel = 1;

float szogJobbLab;
int elojelJobbLab = -1;

float szogNyakFej;
int elojelNyakFej = -1;

float szogKarBal;
int elojelKarBal = -1;

float szogKarJobb;
int elojelKarJobb = -1;

float szogMozog;
int elojelMozog = 1;

float szogForog = 0;

float scale = 1;

void BitmapText(GLfloat x, GLfloat y, const char* string)
{
	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
}

void StrokeText(char* string)
{
	int len, i;
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, string[i]);
	}
}

void TimerBalLab(int value)
{
	szog += elojel * 0.5;
	if (szog > 30) elojel = -elojel;
	if (szog < -30) elojel = -elojel;
	if (animate) glutTimerFunc(30, TimerBalLab, value);
	glutPostRedisplay();
}

void TimerJobbLab(int value)
{
	szogJobbLab += elojelJobbLab * 0.5;
	if (szogJobbLab > 30) elojelJobbLab = -elojelJobbLab;
	if (szogJobbLab < -30) elojelJobbLab = -elojelJobbLab;
	if (animate) glutTimerFunc(30, TimerBalLab, value);
	glutPostRedisplay();
}

void TimerNyakFej(int value)
{
	szogNyakFej += elojelNyakFej * 0.5;
	if (szogNyakFej > 30) elojelNyakFej = -elojelNyakFej;
	if (szogNyakFej < -30) elojelNyakFej = -elojelNyakFej;
	if (animate) glutTimerFunc(30, TimerBalLab, value);
	glutPostRedisplay();
}

void TimerKarBal(int value)
{
	szogKarBal += elojelKarBal * 0.5 / 1.3;
	if (szogKarBal > 10) elojelKarBal = -elojelKarBal;
	if (szogKarBal < -10) elojelKarBal = -elojelKarBal;
	if (animate) glutTimerFunc(30, TimerBalLab, value);
	glutPostRedisplay();
}

void TimerForgas(int value)
{
	szogForog += 1;
	if (animate) glutTimerFunc(30, TimerForgas, value);
	glutPostRedisplay();
}

void TimerKarJobb(int value)
{
	szogKarJobb += elojelKarJobb * 0.5 / 1.3;
	if (szogKarJobb > 10) elojelKarJobb = -elojelKarJobb;
	if (szogKarJobb < -10) elojelKarJobb = -elojelKarJobb;
	if (animate) glutTimerFunc(30, TimerBalLab, value);
	glutPostRedisplay();
}

void TimerMozog(int value)
{
	szogMozog += elojelMozog * 0.1;
	//if (szogKarJobb > 10) elojelKarJobb = -elojelKarJobb;
	//if (szogKarJobb < -10) elojelKarJobb = -elojelKarJobb;
	if (animate) glutTimerFunc(30, TimerBalLab, value);
	glutPostRedisplay();
}

void SpecialKeysA(int key, int x, int y)
{
	if (key == GLUT_KEY_F1)
	{
		animate = !animate;
		if (animate) glutTimerFunc(30, TimerBalLab, 0);
	}
	glutPostRedisplay();
}

void glutAlakzatok()
{
	//int Xmozdul = 0;
	//int Ymozdul = 0;

	//glTranslatef(-10, 0, 0);

	//glScalef(0.2, 0.2, 0.2);
	//glTranslatef(Xmozdul, Ymozdul, 0);
	//TimerMozog(0);
	//glTranslatef(szogMozog, 10 * sin(szogMozog * 3.14 / 100), 0);
	//glTranslatef(szogMozog, 0, 0);

	/*if (szogMozog > 40 && szogMozog < 74) {
		TimerForgas(0);
		glRotatef(szogForog, 0, 1, 0);
		if (szogMozog <= 57) {
			scale += 0.02;
		}
		else {
			scale -= 0.02;
		}
		glScalef(scale, scale, scale);
	}*/


	//fej
	glPushMatrix();
	//anim
	glTranslatef(0, 1, 0);
	//TimerNyakFej(0);
	//glTranslatef(0, szogNyakFej / 150, 0);
	//----------
	glColor3f(0, 0, 1);
	glutSolidSphere(2, 360, 360);
	//glTranslatef(-2, -3, 0);
	//glScalef(0.01, 0.01, 1);
	//glDisable(GL_LIGHTING);
	//glEnable(GL_LIGHTING);
	glPopMatrix();


	//nyak
	/*glTranslatef(0, -1.2, 0);
	glPushMatrix();
	//anim
	glTranslatef(0, -0.3, 0);
	//TimerNyakFej(0);
	glTranslatef(0, szogNyakFej / 150, 0);
	//------------------
	glColor3f(0, 0, 1);
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.5f, 0.5f, 1.1f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();*/

	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();

	//torzs
	glPushMatrix();
	glColor3f(1, 0, 1);
	glScalef(0.1, 0.1, 0.15);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glBegin(GL_QUADS);

	//felso
	glColor3f(1, 0, 1);
	glVertex3f(15,-10,-5);
	glVertex3f(-15, -10, -5);
	glVertex3f(-15, -10, 5);
	glVertex3f(15, -10, 5);

	// also fele
	glColor3f(1, 0, 1);
	glVertex3f(15, -50, 5);
	glVertex3f(-15, -50, 5);
	glVertex3f(-15, -50, -5);
	glVertex3f(15, -50, -5);

	// szemben 
	glColor3f(1, 0, 1);
	glVertex3f(15, -10, 5);
	glVertex3f(-15, -10, 5);
	glVertex3f(-15, -50, 5);
	glVertex3f(15, -50, 5);

	// hatso 
	glColor3f(1, 0, 1);
	glVertex3f(15, -10, -5);
	glVertex3f(-15, -10, -5);
	glVertex3f(-15, -50, -5);
	glVertex3f(15, -50, -5);

	// bal
	glColor3f(1, 0, 1);
	glVertex3f(-15, -10, 5);
	glVertex3f(-15, -10, -5);
	glVertex3f(-15, -50, -5);
	glVertex3f(-15, -50, 5);

	// jobb 
	glColor3f(1, 0, 1);
	glVertex3f(15, -10, -5);
	glVertex3f(15, -10, 5);
	glVertex3f(15, -50, 5);
	glVertex3f(15, -50, -5);
	glEnd();

	glPopMatrix();

	//bal lab felso

	glTranslatef(-1, -4.8, 0);
	glPushMatrix();
	//anim
	TimerBalLab(0);
	glRotatef(szog, 1, 0, 0);
	//----------------------------
	glColor3f(1, 0.5, 0.2);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.5f, 0.5f, 1.9f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//bal lab also
	glTranslatef(0, -1.8, 0);
	glPushMatrix();
	//anim
	TimerBalLab(0);
	glTranslatef(0, 1.8, 0);
	glRotatef(szog, 1, 0, 0);
	//----------------------------
	glTranslatef(0, -1.8, 0);
	glColor3f(1, 1, 0);
	glRotatef(110, 1, 0, 0);     // lehet allitani hogy az also lab milyen szogben legyen
	gluCylinder(quadratic, 0.5f, 0.25f, 1.8f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glTranslatef(0, 1.8, 0);   // felso labresz tavolsaga a testtol

	//jobb lab felso
	glTranslatef(2, 0.2, 0);
	glPushMatrix();
	//anim
	TimerJobbLab(0);
	glRotatef(szogJobbLab, 1, 0, 0);
	//----------------------------
	glColor3f(1, 0.5, 0.2);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 0.5f, 0.5f, 1.9f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//jobb lab also
	glTranslatef(0, -1.8, 0);
	glPushMatrix();
	//anim
	TimerJobbLab(0);
	glTranslatef(0, 1.8, 0);
	glRotatef(szogJobbLab, 1, 0, 0);
	//----------------------------
	glTranslatef(0, -1.7, 0);
	glColor3f(1, 1, 0);
	glRotatef(110, 1, 0, 0);
	gluCylinder(quadratic, 0.5f, 0.25f, 1.8f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glTranslatef(0, 1.3, 0);

	//bal kez
	glTranslatef(-2, 3.7, 0);
	glPushMatrix();
	//anim
	TimerKarBal(0);
	glRotatef(szogKarBal, 0, 1, 0);
	//--------------------
	glColor3f(1, 1, 1);
	glRotatef(90, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
	gluCylinder(quadratic, 0.25f, 0.25f, 4.0f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();




	//jobb kez
	glTranslatef(2, 0, 0);
	glPushMatrix();
	//anim
	TimerKarJobb(0);
	glRotatef(szogKarJobb, 0, 1, 0);
	//-------------------
	glColor3f(1, 1, 1);
	glRotatef(90, 1, 0, 0);
	glRotatef(30, 0, 1, 0);
	gluCylinder(quadratic, 0.25f, 0.25f, 4.0f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//jobb alkar
	/*glTranslatef(1.3, -2.3, -0.1);
	glPushMatrix();
	//anim
	TimerKarJobb(0);
	
	glRotatef(szogKarJobb, 1, 0, 0);
	//-------------------
	glColor3f(1, 0, 0);
	glRotatef(45, 1, 0, 0);
	//glRotatef(30, 1, 0, 0);
	gluCylinder(quadratic, 0.3f, 0.3f, 1.5f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	*/

	/*glTranslatef(-szogMozog, -10 * sin(szogMozog * 3.14 / 100), 0);
	glTranslatef(-Xmozdul, -Ymozdul, 0);

	glTranslatef(0, -9, 0);
	glColor3f(0, 1, 0);
	glBegin(GL_LINE_STRIP);
	for (float i = -50; i < 200; i += 0.2) {
		glVertex2f(i, 10 * sin(i * 3.14 / 100));
	}*/
	glEnd();

}

void keringoFeny()
{
	GLfloat	 lightPos[] = { -6.f, 0.0f, 0.0f, 1.0f };
	glPushMatrix();
	glRotatef(yRot2, 0, 1, 0);
	glTranslatef(-6, 0, 0);
	glDisable(GL_LIGHTING);
	glColor3f(0.7, 0.7, 0.7);
	glutSolidSphere(0.2, 10, 10);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glPopMatrix();
}

/*
 *	ablakfrissiteskor hivodik
 *  ujrarajzolja az ablakot
 */
void RenderScene(void)
{
	// torli a szin es melyseg buffert 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();// elmenti az aktualis transzformacios matrixot a matrix verembe
	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);
	//BitmapText(-3, 6, "Glut alakzatok");
	glEnable(GL_LIGHTING);
	glRotatef(yRot, 0, 1, 0); // y tengely koruli forgatas yRot fokkal 
	glRotatef(xRot, 1, 0, 0); // x tengely koruli forgatas xRot fokkal 
	keringoFeny();
	glutAlakzatok();
	glPopMatrix();// visszatolti az aktualis transzformacios matrixot a matrix verembol
	glutSwapBuffers();// megcsereli a buffereket
}

void Timer(int value)
{
	yRot2 += 3;
	if (yRot2 > 356.0f)
		yRot2 = 0.0f;

	if (yRot2 < -1.0f)
		yRot2 = 355.0f;

	if (bSwtich) glutTimerFunc(50, Timer, 0);
	glutPostRedisplay();
}

/*
 *	billentyu leuteskor hivodik
 *  az xRot es yRot forgato valtozokat valtoztatja
 */
void SpecialKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
		xRot -= 5.0f;
	if (key == GLUT_KEY_DOWN)
		xRot += 5.0f;
	if (key == GLUT_KEY_LEFT)
		yRot -= 5.0f;
	if (key == GLUT_KEY_RIGHT)
		yRot += 5.0f;
	if (xRot > 356.0f)
		xRot = 0.0f;
	if (xRot < -1.0f)
		xRot = 355.0f;
	if (yRot > 356.0f)
		yRot = 0.0f;
	if (yRot < -1.0f)
		yRot = 355.0f;
	if (key == GLUT_KEY_F1)
	{
		bSwtich = !bSwtich;
		if (bSwtich)glutTimerFunc(50, Timer, 0);
	}
	glutPostRedisplay(); // frissiti a glut ablakot
}


void spinDisplay1(void)
{
	xRot += 5.0f;
	if (xRot > 356.0f)
		xRot = 0.0f;
	if (xRot < -1.0f)
		xRot = 355.0f;
	glutPostRedisplay();
}

void spinDisplay2(void)
{
	yRot += 5.0f;
	if (yRot > 356.0f)
		yRot = 0.0f;
	if (yRot < -1.0f)
		yRot = 355.0f;
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			spinDisplay1();
		//glutIdleFunc(spinDisplay1);
		if (state == GLUT_UP)
			glutIdleFunc(NULL);
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay2);
		if (state == GLUT_UP)
			glutIdleFunc(NULL);
		break;
	default:
		break;
	}
}

/*
 * ablakletrehozaskor es kepernyo atmeretezeskor hivodik
 */

void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat	 lightPos[] = { -50.f, 50.0f, 100.0f, 1.0f };

	// elkeruljuk a 0-val valo osztast
	if (h == 0)
		h = 1;

	// beallitja a Viewport-ot az ablak mereteire
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //atkapcsol projekcios matrix modba
	glLoadIdentity();// a transzformacios matrixot reseteli(ld. egyseg mtx)


	//beallitja az ortogonalis vetitest
	if (w <= h)
		glOrtho(-9, 9, -9 * h / w, 9 * h / w, -10.0, 10.0);
	else
		glOrtho(-9 * w / h, 9 * w / h, -9, 9, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW); // visszkapcsol model view modba
	glLoadIdentity(); // a transzformacios matrixot reseteli(ld. egyseg mtx)

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

void SetupRC()
{
	GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };

	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glEnable(GL_LIGHT0);

	glEnable(GL_DEPTH_TEST); // melyseg teszt vegzese (z-buffer)
	glShadeModel(GL_SMOOTH); // arnyekolasi mod 
	glDisable(GL_CULL_FACE);

	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);

	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// fekete (torlo) hattér szín
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv); //inicializalja a glut lib-et	
	glutInitWindowSize(300, 300); //induló ablak méret
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //beallitja az ablakot dupla bufferelesre 
															  //rgb modba es melyseg buffer hasznalatara (z-buffer)
	glutCreateWindow("3D GLUT Karakter animation"); // letrehozza az ablakot a megadott nevvel
	glutReshapeFunc(ChangeSize);  // beallitja az atmeretezo fuggvenyt
	glutSpecialFunc(SpecialKeys); // beallitja az billentyuzet kezelo fuggvenyt 
	glutDisplayFunc(RenderScene); // beallitja a jelenet rajzolo fuggvenyt
	glutMouseFunc(mouse);
	SetupRC();					  // inicializalja az openglt
	glutMainLoop(); // a glut elkezdi ismetelni a fo ciklusat
	return 0;
}
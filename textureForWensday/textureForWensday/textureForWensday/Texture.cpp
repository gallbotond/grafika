//#include "stdafx.h"
#include <stdlib.h>    

#include "glut.h"
#include <math.h>
#include "RgbImage.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>

float xRot = 0.0f;
float yRot = 0.0f;
float yRot2 = 0.0f;
float r = 5.0f;
float meret = 1.0f;

const int cnt = 19;


static GLuint textureName[cnt];

void loadTextureFromFile(const char* filename)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
		GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());
}

void drawTextureQuad(int i) {
	glBindTexture(GL_TEXTURE_2D, textureName[i]);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
	glEnd();
}

void glutAlakzatok() {
	glTranslatef(2, 0, 0);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();

	//jobb elso lab
	glTranslatef(3, 0, 0);
	glBindTexture(GL_TEXTURE_2D, textureName[8]);
	gluQuadricOrientation(quadratic, GLU_OUTSIDE);
	gluQuadricNormals(quadratic, GLU_SMOOTH);
	gluQuadricTexture(quadratic, GL_TRUE);
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 1.0f, 1.0f, 7.0f, 4, 4);
	glFlush();

	//bal elso
	glTranslatef(-10, 0, 0);
	glBindTexture(GL_TEXTURE_2D, textureName[8]);
	gluQuadricOrientation(quadratic, GLU_OUTSIDE);
	gluQuadricNormals(quadratic, GLU_SMOOTH);
	gluQuadricTexture(quadratic, GL_TRUE);
	gluCylinder(quadratic, 1.0f, 1.0f, 7.0f, 4, 4);
	glFlush();

	//bal hatso
	glTranslatef(0, -10, 0);
	glBindTexture(GL_TEXTURE_2D, textureName[8]);
	gluQuadricOrientation(quadratic, GLU_OUTSIDE);
	gluQuadricNormals(quadratic, GLU_SMOOTH);
	gluQuadricTexture(quadratic, GL_TRUE);
	gluCylinder(quadratic, 1.0f, 1.0f, 7.0f, 4, 4);
	glFlush();

	//jobb hatso
	glTranslatef(10, 0, 0);
	glBindTexture(GL_TEXTURE_2D, textureName[8]);
	gluQuadricOrientation(quadratic, GLU_OUTSIDE);
	gluQuadricNormals(quadratic, GLU_SMOOTH);
	gluQuadricTexture(quadratic, GL_TRUE);
	gluCylinder(quadratic, 1.0f, 1.0f, 7.0f, 4, 4);
	glFlush();

	//asztal teto
	glRotatef(90, 0, 1, 0);
	glTranslatef(8, 5, -5);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-8.0f, -8.0f, 8.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-8.0f, 8.0f, 8.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-8.0f, 8.0f, -8.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-8.0f, -8.0f, -8.0f);
	glEnd();
	glPopMatrix();




	//asztal keret
	glTranslatef(-4, 13, 0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[3]);
	//also oldal (Y = -5)
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-5.0f, -5.0f, 8.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-5.0f, -5.0f, -8.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-4.0f, -5.0f, -8.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-4.0f, -5.0f, 8.0f);
	glEnd();
	glPopMatrix();

	//asztal keret
	glTranslatef(0, -26, 0);
	glRotatef(180, 1, 0, 0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[3]);
	//also oldal (Y = -5)
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-5.0f, -5.0f, 8.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-5.0f, -5.0f, -8.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-4.0f, -5.0f, -8.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-4.0f, -5.0f, 8.0f);
	glEnd();
	glPopMatrix();

	//asztal keret
	glTranslatef(0, -13, 13);
	glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[3]);
	//also oldal (Y = -5)
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-5.0f, -5.0f, 8.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-5.0f, -5.0f, -8.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-4.0f, -5.0f, -8.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-4.0f, -5.0f, 8.0f);
	glEnd();
	glPopMatrix();

	//asztal keret
	glTranslatef(0, -26, 0);
	glRotatef(180, 1, 0, 0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[3]);
	//also oldal (Y = -5)
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-5.0f, -5.0f, 8.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-5.0f, -5.0f, -8.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-4.0f, -5.0f, -8.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-4.0f, -5.0f, 8.0f);
	glEnd();
	glPopMatrix();

	//fal,bal
	glTranslatef(0, -26, 0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[7]);
	//also oldal (Y = -5)
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-11.0f, -5.0f, 18.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-11.0f, -5.0f, -18.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(15.0f, -5.0f, -18.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(15.0f, -5.0f, 18.0f);
	glEnd();
	glPopMatrix();

	//kep,bal
	glTranslatef(0, 1, 0);
	//glRotatef(90,1,0,0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[9]);
	//also oldal (Y = -5)
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(2.0f, -5.0f, 3.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(2.0f, -5.0f, -2.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(8.0f, -5.0f, -2.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(8.0f, -5.0f, 3.0f);
	glEnd();
	glPopMatrix();


	//fal,jobb
	glRotatef(90, 1, 0, 0);
	glRotatef(180, 0, 0, 1);
	glTranslatef(-4, -13, -13);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[6]);
	//also oldal (Y = -5)
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-11.0f, -5.0f, 18.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-11.0f, -5.0f, -18.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(15.0f, -5.0f, -18.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(15.0f, -5.0f, 18.0f);
	glEnd();
	glPopMatrix();

	//kep jobb
	glTranslatef(0, 0.1, 0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[10]);
	//also oldal (Y = -5)
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-3.0f, -5.0f, 4.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-3.0f, -5.0f, -3.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(5.0f, -5.0f, -3.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(5.0f, -5.0f, 4.0f);
	glEnd();
	glPopMatrix();

	//padlo
	glRotatef(90, 0, 0, 1);
	glTranslatef(6, -10, 0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[5]);
	//also oldal (Y = -5)
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-11.0f, -5.0f, 18.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-11.0f, -5.0f, -18.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(25.0f, -5.0f, -18.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(25.0f, -5.0f, 18.0f);
	glEnd();
	glPopMatrix();

	//boros uveg alja
	glRotatef(90, 1, 0, 0);
	glTranslatef(10, 2, -5);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[14]);
	gluCylinder(quadratic, 0.8f, 0.8f, 3.0f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glTranslatef(0, 1.8, 0);

	//boros uveg teteje
	glTranslatef(0, -1.8, -1.2);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[15]);
	gluCylinder(quadratic, 0.2f, 0.8f, 1.2f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glTranslatef(0, 1.8, 0);

	//boros uveg legteteje
	glTranslatef(0, -1.8, -0.5);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[15]);
	gluCylinder(quadratic, 0.2f, 0.2f, 0.5f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glTranslatef(0, 1.8, 0);


	//boros pohar talpa
	glTranslatef(-4, -2, 0);
	glTranslatef(2, -4, 4.6);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[12]);
	gluCylinder(quadratic, 0.08f, 0.4f, 0.1f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//boros pohar szara
	glTranslatef(0, 0, -0.8);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[12]);
	gluCylinder(quadratic, 0.08f, 0.08f, 0.8f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//boros pohar oblos reszenek az alja
	glTranslatef(0, 0, -0.3);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[11]);
	gluCylinder(quadratic, 0.5f, 0.08f, 0.3f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//boros pohar oblos reszenek a teteje
	glTranslatef(0, 0, -0.3);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[12]);
	gluCylinder(quadratic, 0.5f, 0.5f, 0.3f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//boros pohar 2
	//boros pohar alja
	glTranslatef(-6, 9, 0);
	glTranslatef(2, -2, 1.38);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[12]);
	gluCylinder(quadratic, 0.08f, 0.4f, 0.1f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//boros pohar szara
	glTranslatef(0, 0, -0.8);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[12]);
	gluCylinder(quadratic, 0.08f, 0.08f, 0.8f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//boros pohar oblos reszenek az alja
	glTranslatef(0, 0, -0.3);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[11]);
	gluCylinder(quadratic, 0.5f, 0.08f, 0.3f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//boros pohar oblos reszenek a teteje
	glTranslatef(0, 0, -0.3);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[12]);
	gluCylinder(quadratic, 0.5f, 0.5f, 0.3f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//frapiera
	glTranslatef(8, -7, -0.4);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[16]);
	gluCylinder(quadratic, 1.3f, 0.7f, 2.0f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//tanyer
	glTranslatef(-5.5, -2, 1.8);
	glRotatef(180, 0, 1, 0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[17]);
	gluCylinder(quadratic, 1.7f, 0.001f, 0.02f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//tanyer
	glTranslatef(0, 10, 0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[17]);
	gluCylinder(quadratic, 1.7f, 0.001f, 0.02f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//vaza
	glTranslatef(0, -5, -0.02);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, textureName[18]);
	gluCylinder(quadratic, 0.3f, 0.7f, 2.5f, 100, 100);
	glScalef(0.01, 0.01, 1);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}


void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(yRot, 0, 1, 0);
	glRotatef(xRot, 1, 0, 0); // x tengely koruli forgatas xRot fokkal 
	glScalef(meret, meret, meret);
	glutAlakzatok();
	glPopMatrix();
	glutSwapBuffers();
}

void SpecialKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_F2)
		meret += 0.3f;
	if (key == GLUT_KEY_F3)
		meret -= 0.3f;
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
	glutPostRedisplay();
}


void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat	 lightPos[] = { -50.f, 50.0f, 100.0f, 1.0f };
	if (h == 0) h = 1;
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	if (w <= h)
		glOrtho(-9, 9, -9 * h / w, 9 * h / w, -10.0, 10.0);
	else
		glOrtho(-9 * w / h, 9 * w / h, -9, 9, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

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

	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glDisable(GL_CULL_FACE);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void initFour(const char* filenames[])
{
	glGenTextures(cnt, textureName);
	for (int i = 0; i < cnt; i++) {
		glBindTexture(GL_TEXTURE_2D, textureName[i]);
		loadTextureFromFile(filenames[i]);
	}
}

const char* filenameArray[cnt] = {
		"text/WoodGrain.bmp",//0
		"text/LightningTexture.bmp",//1
		"text/wood1.bmp",//2
		"text/IvyTexture.bmp",///3
		"text/RedLeavesTexture.bmp",//4
		"text/szonyeg.bmp",//5
		"text/fal.bmp",//6
		"text/fal2.bmp",//7
		"text/fa1.bmp",//8
		"text/festmeny.bmp",//9
		"text/fruits.bmp",//10
		"text/bor.bmp",//11
		"text/uveg.bmp",//12
		"text/zold_uveg.bmp",//13
		"text/boros_uveg.bmp",//14
		"text/piros_uveg.bmp",//15
		"text/frapiera.bmp",//16
		"text/tanyer.bmp",//17
		"text/vaza.bmp",//18
};


int main(int argc, char* argv[])

{
	glutInitWindowSize(300, 300);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Szoba belseje");
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeys);

	initFour(filenameArray);

	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();
	return 0;
}
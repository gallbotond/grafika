#include "framework.h"
#include <stdlib.h>
#include "glut.h"
#include <math.h>
#include "Resource.h"

float angle1 = 0.0f;
float angle2 = 0.0f;


GLdouble posX, posY, posZ, omega1, omega2, x2, y2;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the head
    glPushMatrix();
    glTranslatef(posX, posY, 0.0f);
    glutSolidSphere(0.1f, 20, 20);
    glPopMatrix();

    // Draw the body
    glBegin(GL_LINES);
    glVertex2f(posX, posY - 0.1f);
    glVertex2f(posX, posY - 0.4f);
    glEnd();

    // Draw the left arm
    glBegin(GL_LINES);
    glVertex2f(posX, posY - 0.2f);
    glVertex2f(posX - 0.2f, posY - 0.3f);
    glEnd();

    // Draw the right arm
    glBegin(GL_LINES);
    glVertex2f(posX, posY - 0.2f);
    glVertex2f(posX + 0.2f, posY - 0.3f);
    glEnd();

    // Draw the left leg
    glBegin(GL_LINES);
    glVertex2f(posX, posY - 0.4f);
    glVertex2f(posX - 0.2f, posY - 0.5f);
    glEnd();

    // Draw the right leg
    glBegin(GL_LINES);
    glVertex2f(posX, posY - 0.4f);
    glVertex2f(posX + 0.2f, posY - 0.5f);
    glEnd();

    glFlush();
}

void moveHand(float angle) {
    // Draw the left arm
    glPushMatrix();
    glTranslatef(posX, posY - 0.2f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-posX, -posY + 0.2f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(posX, posY - 0.2f);
    glVertex2f(posX - 0.2f, posY - 0.3f);
    glEnd();
    glPopMatrix();

    // Draw the right arm
    glPushMatrix();
    glTranslatef(posX, posY - 0.2f, 0.0f);
    glRotatef(-angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-posX, -posY + 0.2f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(posX, posY - 0.2f);
    glVertex2f(posX + 0.2f, posY - 0.3f);
    glEnd();
    glPopMatrix();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void update(int value) {
    angle1 += 1.0f;
    if (angle1 > 360) {
        angle1 -= 360;
    }

    angle2 += 2.0f;
    if (angle2 > 360) {
        angle2 -= 360;
    }

    moveHand(angle1);

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    glutInit(&__argc, __argv);
    glutCreateWindow("OpenGL Figure");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutTimerFunc(25, update, 0);

    glutMainLoop();
    return 0;
}

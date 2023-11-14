#include "framework.h"
#include <stdlib.h>
#include "glut.h"
#include <math.h>
#include "Resource.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

struct Vertex {
    float x, y, z;
};

struct Face {
    int v1, v2, v3;
};

std::vector<Vertex> vertices;
std::vector<Face> faces;

void readObjFile(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        char type;
        iss >> type;

        switch (type) {
        case 'v': {
            Vertex vertex;
            iss >> vertex.x >> vertex.y >> vertex.z;
            vertices.push_back(vertex);
            break;
        }
        case 'f': {
            Face face;
            iss >> face.v1 >> face.v2 >> face.v3;
            // OBJ file indices start from 1, so we decrement them
            face.v1--;
            face.v2--;
            face.v3--;
            faces.push_back(face);
            break;
        }
        default:
            break;
        }
    }

    file.close();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0); // Set the camera position

    glColor3f(1.0, 1.0, 1.0); // Set color to white

    glBegin(GL_TRIANGLES);
    for (const auto& face : faces) {
        for (int i = 0; i < 3; ++i) {
            const Vertex& vertex = vertices[face.v1 + i];
            glVertex3f(vertex.x, vertex.y, vertex.z);
        }
    }
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int APIENTRY wWinMain(IN HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, IN LPWSTR    lpCmdLine, IN int       nCmdShow)

{
    //glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OBJ File Renderer");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Replace this path with the path to your .obj file
    const char* objFilePath = "a.obj";
    readObjFile(objFilePath);

    glutMainLoop();
    return 0;
}

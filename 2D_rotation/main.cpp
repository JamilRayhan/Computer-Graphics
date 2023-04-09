#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;

// Global variables
int winWidth = 640;
int winHeight = 480;

// Draw a line using OpenGL
void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// Rotate a point (x, y) about the origin by angle theta (in radians)
void rotatePoint(float& x, float& y, float theta) {
    float x_new = x * cos(theta) - y * sin(theta);
    float y_new = x * sin(theta) + y * cos(theta);
    x = x_new;
    y = y_new;
}

// Display callback function
void display() {
    // Set the background color to white
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the color of the line to black
    glColor3f(0.0f, 0.0f, 0.0f);

    // Draw the original line
    float x1 = 100.0f, y1 = 100.0f, x2 = 300.0f, y2 = 100.0f;
    drawLine(x1, y1, x2, y2);

    // Rotate the line by 45 degrees about the origin
    float theta = 45.0f * M_PI / 180.0f;
    rotatePoint(x1, y1, theta);
    rotatePoint(x2, y2, theta);

    // Draw the rotated line
    glColor3f(1.0f, 0.0f, 0.0f);
    drawLine(x1, y1, x2, y2);

    // Flush the OpenGL buffers
    glFlush();
}

// Reshape callback function
void reshape(int w, int h) {
    // Set the viewport to cover the entire window
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);

    // Set the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);

    // Set the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    // Initialize GLUT and create the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(winWidth, winHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Rotation");

    // Set the display callback function
    glutDisplayFunc(display);

    // Set the reshape callback function
    glutReshapeFunc(reshape);

    // Enter the main loop
    glutMainLoop();

    return 0;
}

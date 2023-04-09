#include <iostream>
#include <GL/glut.h>

using namespace std;

void myInit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a rectangle
    glColor3f(1.0, 0.0, 0.0);
    glRecti(100, 100, 300, 200);

    // Perform scaling
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(2.0, 1.5, 1.0); // scale by 2 in x-axis and 1.5 in y-axis

    // Draw the scaled rectangle
    glColor3f(0.0, 1.0, 0.0);
    glRecti(100, 100, 300, 200);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Scaling");

    myInit();

    glutDisplayFunc(myDisplay);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}

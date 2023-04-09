#include <iostream>
#include <GL/glut.h>

using namespace std;

void init()
{
    // Set clear color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // Set projection mode to 2D orthographic
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void display()
{
    // Clear screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a red square
    glColor3f(1.0, 0.0, 0.0);
    glRecti(100, 100, 200, 200);

    // Translate the square to the right by 50 units
    glTranslatef(50.0, 0.0, 0.0);

    // Draw a blue square
    glColor3f(0.0, 0.0, 1.0);
    glRecti(100, 100, 200, 200);

    // Swap buffers
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Translation");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}

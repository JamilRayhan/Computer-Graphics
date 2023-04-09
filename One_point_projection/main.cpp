#include <GL/glut.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the object to be projected
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(2.0, 2.0);
    glVertex2f(-2.0, 2.0);
    glVertex2f(-2.0, -2.0);
    glVertex2f(2.0, -2.0);
    glEnd();

    // Define the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 50.0);
    glTranslatef(0.0, 0.0, -5.0);

    // Define the view matrix (one point projection)
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 0.0, 1.0, 1.0, -1.0, 0.0, 1.0, 0.0);

    // Draw the projected object
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(2.0, 2.0, -5.0);
    glVertex3f(-2.0, 2.0, -5.0);
    glVertex3f(-2.0, -2.0, -5.0);
    glVertex3f(2.0, -2.0, -5.0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("One Point Projection");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

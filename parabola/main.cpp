#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_POINTS);

    float a = 1.0, b = 2.0, c = 1.0; // Parabola equation coefficients
    float x, y;

    for (x = -5.0; x <= 5.0; x += 0.01) {
        y = a * x * x + b * x + c;
        glVertex2f(x, y);
    }

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Parabola");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

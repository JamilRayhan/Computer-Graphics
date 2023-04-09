#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble size=1;

void display(void);
void reshape(int x, int y);
void idle(void);

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(350,350);
    glutCreateWindow("3D Shear Transformation");

    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glEnable(GL_DEPTH_TEST);

    xRotated = yRotated = zRotated = 30.0;

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}

void display(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    glTranslatef(0.0,0.0,-5.0);

    glPushMatrix();
    glScalef(size,size,size);
    glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);
    glRotatef(zRotated,0.0,0.0,1.0);

    glColor3f(0.0, 0.0, 1.0);
    glutWireCube(1.0);

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glViewport(0,0,x,y);
    glMatrixMode(GL_MODELVIEW);
}

void idle(void)
{
    xRotated += 0.01;
    yRotated += 0.01;
    zRotated += 0.01;

    display();
}

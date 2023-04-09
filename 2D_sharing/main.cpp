#include <GL/glut.h>

void init() {
   glClearColor(0.0, 0.0, 0.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 0.0, 0.0); // set color to red

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   glBegin(GL_TRIANGLES);
   glVertex2f(-0.5, -0.5);
   glVertex2f(0.5, -0.5);
   glVertex2f(0.0, 0.5);
   glEnd();

   float shearX = 0.5; // set shear value for x-axis
   float shearY = 0.0; // set shear value for y-axis

   // Apply shear transformation
   GLfloat matrix[16] = {
      1.0, shearX, 0.0, 0.0,
      shearY, 1.0, 0.0, 0.0,
      0.0, 0.0, 1.0, 0.0,
      0.0, 0.0, 0.0, 1.0
   };

   glMultMatrixf(matrix);

   glColor3f(0.0, 1.0, 0.0); // set color to green

   glBegin(GL_TRIANGLES);
   glVertex2f(-0.5, -0.5);
   glVertex2f(0.5, -0.5);
   glVertex2f(0.0, 0.5);
   glEnd();

   glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutCreateWindow("2D Shear Transformation");
   init();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}

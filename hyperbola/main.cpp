#include <GL/glut.h>
#include <math.h>

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);

   // Set up the viewing transformation
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, 1.0, 1.0, 100.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

   // Set up the hyperbola parameters
   double a = 1.0;
   double b = 2.0;
   double c = sqrt(a*a + b*b);
   double x, y, z;

   // Draw the hyperbola
   glBegin(GL_LINE_STRIP);
   for (double t = -10.0; t <= 10.0; t += 0.1)
   {
      x = c * sinh(t);
      y = a * cosh(t);
      z = b * cosh(t);
      glVertex3d(x, y, z);
   }
   glEnd();

   glutSwapBuffers();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutCreateWindow("Hyperbola");
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}

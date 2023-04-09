#include <GL/glut.h>

int win_width = 600, win_height = 600;

void init() {
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, 1.0, 1.0, 20.0); // Perspective projection
   glMatrixMode(GL_MODELVIEW);
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);

   // Top view
   glViewport(0, win_height/2, win_width/2, win_height/2);
   glLoadIdentity();
   gluLookAt(0.0, 6.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
   glutWireTeapot(1.0);

   // Front view
   glViewport(0, 0, win_width/2, win_height/2);
   glLoadIdentity();
   gluLookAt(0.0, 0.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   glutWireTeapot(1.0);

   // Side view
   glViewport(win_width/2, 0, win_width/2, win_height/2);
   glLoadIdentity();
   gluLookAt(6.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   glutWireTeapot(1.0);

   glFlush();
}

void reshape(int w, int h) {
   win_width = w;
   win_height = h;
   glViewport(0, 0, w, h);
}

int main(int argc, char **argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(win_width, win_height);
   glutCreateWindow("Multiview Projection");

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);

   init();

   glutMainLoop();

   return 0;
}

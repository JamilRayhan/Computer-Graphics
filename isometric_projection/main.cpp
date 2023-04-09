#include <GL/glut.h>

// Define window size
const int width = 640;
const int height = 480;

void init() {
  // Set clear color to white
  glClearColor(1.0, 1.0, 1.0, 0.0);

  // Set projection matrix to isometric projection
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}

void display() {
  // Clear screen
  glClear(GL_COLOR_BUFFER_BIT);

  // Set modelview matrix to identity matrix
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // Set line width to 2.0
  glLineWidth(2.0);

  // Draw X, Y and Z axes
  glColor3f(1.0, 0.0, 0.0); // Red
  glBegin(GL_LINES);
  glVertex3f(-10.0, 0.0, 0.0);
  glVertex3f(10.0, 0.0, 0.0);
  glEnd();

  glColor3f(0.0, 1.0, 0.0); // Green
  glBegin(GL_LINES);
  glVertex3f(0.0, -10.0, 0.0);
  glVertex3f(0.0, 10.0, 0.0);
  glEnd();

  glColor3f(0.0, 0.0, 1.0); // Blue
  glBegin(GL_LINES);
  glVertex3f(0.0, 0.0, -10.0);
  glVertex3f(0.0, 0.0, 10.0);
  glEnd();

  // Draw a cube
  glColor3f(0.0, 0.0, 0.0); // Black
  glTranslatef(0.0, 0.0, 3.0);
  glutWireCube(2.0);

  // Swap buffers
  glutSwapBuffers();
}

int main(int argc, char** argv) {
  // Initialize GLUT
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

  // Set window size and position
  glutInitWindowSize(width, height);
  glutInitWindowPosition(100, 100);

  // Create window with the given title
  glutCreateWindow("Isometric Projection");

  // Initialize OpenGL
  init();

  // Set display function
  glutDisplayFunc(display);

  // Start the main loop
  glutMainLoop();

  return 0;
}

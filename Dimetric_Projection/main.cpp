#include <GL/glut.h>

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 1.0, 1.0); // Set color to cyan

  // Define the vertices of the cube
  GLfloat vertices[8][3] = {{-1.0,-1.0,1.0}, {-1.0,1.0,1.0},
                            {1.0,1.0,1.0}, {1.0,-1.0,1.0},
                            {-1.0,-1.0,-1.0}, {-1.0,1.0,-1.0},
                            {1.0,1.0,-1.0}, {1.0,-1.0,-1.0}};

  glBegin(GL_QUADS); // Begin drawing quads
    // Draw front face of the cube
    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[3]);

    // Draw back face of the cube
    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[7]);

    // Draw top face of the cube
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[2]);

    // Draw bottom face of the cube
    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[3]);
    glVertex3fv(vertices[7]);

    // Draw left face of the cube
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[7]);
    glVertex3fv(vertices[6]);

    // Draw right face of the cube
    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[3]);
  glEnd(); // End drawing quads

  glFlush();
}

void init() {
  glClearColor(0.0, 0.0, 0.0, 0.0); // Set clear color to black
  glMatrixMode(GL_PROJECTION); // Set projection mode
  glLoadIdentity(); // Load identity matrix
  glOrtho(-5, 5, -5, 5, -5, 5); // Set orthographic projection
  glMatrixMode(GL_MODELVIEW); // Set modelview mode
  glLoadIdentity(); // Load identity matrix
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
  glutInitWindowSize(500, 500); // Set window size
  glutInitWindowPosition(100, 100); // Set window position
  glutCreateWindow("Dimetric Projection"); // Create window
  init(); // Initialize OpenGL settings
  glutDisplayFunc(display); // Set display callback function
  glutMainLoop(); // Enter main loop
  return 0;
}

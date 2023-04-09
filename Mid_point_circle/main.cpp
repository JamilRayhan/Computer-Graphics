#include <stdio.h>
#include <GL/glut.h>

int xc, yc, r;

void plot_points(int x, int y) {
  glBegin(GL_POINTS);
  glVertex2i(xc + x, yc + y);
  glVertex2i(xc + x, yc - y);
  glVertex2i(xc + y, yc + x);
  glVertex2i(xc + y, yc - x);
  glVertex2i(xc - x, yc - y);
  glVertex2i(xc - y, yc - x);
  glVertex2i(xc - x, yc + y);
  glVertex2i(xc - y, yc + x);
  glEnd();
}

void mid_point_circle() {
  int x = 0, y = r;
  float decision_param = 5 / 4 - r;

  plot_points(x, y);

  while (y > x) {
    if (decision_param < 0) {
      x++;
      decision_param += 2 * x + 1;
    } else {
      y--;
      x++;
      decision_param += 2 * (x - y) + 1;
    }
    plot_points(x, y);
  }
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  mid_point_circle();
  glFlush();
}

void myInit() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glColor3f(1.0, 1.0, 1.0);
  gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char **argv) {
  printf("Enter the coordinates of the center:\n\n");
  printf("X-coordinate : ");
  scanf("%d", &xc);
  printf("Y-coordinate : ");
  scanf("%d", &yc);
  printf("Enter the radius of the circle : ");
  scanf("%d", &r);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Mid-Point Circle Drawing Algorithm");
  myInit();
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}

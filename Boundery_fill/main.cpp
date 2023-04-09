#include <iostream>
#include <GL/glut.h>
#include <time.h>

using namespace std;

void delay(float ms){
    clock_t goal = ms + clock();
    while(goal>clock());
}

void boundaryfill(int x, int y, float* f_color, float* b_color){
    float color[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);
    if(color[0]!=b_color[0] || color[1]!=b_color[1] || color[2]!=b_color[2]){
        if(color[0]!=f_color[0] || color[1]!=f_color[1] || color[2]!=f_color[2]){
            glColor3f(f_color[0], f_color[1], f_color[2]);
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
            glFlush();
            boundaryfill(x+1, y, f_color, b_color);
            boundaryfill(x-1, y, f_color, b_color);
            boundaryfill(x, y+1, f_color, b_color);
            boundaryfill(x, y-1, f_color, b_color);
        }
    }
}

void mouse(int btn, int state, int x, int y){
    y = 480-y;
    if(btn==GLUT_LEFT_BUTTON)
    {
        if(state==GLUT_DOWN)
        {
            float bCol[] = {1, 0, 0}; // boundary color (red)
            float color[] = {0, 0, 1}; // fill color (blue)
            boundaryfill(x, y, color, bCol);
        }
    }
}

void world(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0); // draw a red square
    glBegin(GL_LINE_LOOP);
    glVertex2i(50, 50);
    glVertex2i(190, 50);
    glVertex2i(190, 190);
    glVertex2i(50, 190);
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Boundary Filling Algorithm");
    glutDisplayFunc(world);
    glutMouseFunc(mouse);
    glClearColor(1, 1, 1, 0); // set background color to white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);
    glutMainLoop();
    return 0;
}

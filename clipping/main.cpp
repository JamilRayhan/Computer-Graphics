#include <GL/glut.h>

void display()
{
    // Define the vertices of the cube to be rendered
    GLfloat vertices[][3] = {
        {-1.0,-1.0,-1.0},
        {1.0,-1.0,-1.0},
        {1.0,1.0,-1.0},
        {-1.0,1.0,-1.0},
        {-1.0,-1.0,1.0},
        {1.0,-1.0,1.0},
        {1.0,1.0,1.0},
        {-1.0,1.0,1.0}
    };

    // Define the faces of the cube to be rendered
    GLubyte indices[] = {
        0,3,2,1,
        2,3,7,6,
        0,4,7,3,
        1,2,6,5,
        4,5,6,7,
        0,1,5,4
    };

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up the viewing frustum
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0,1.0,-1.0,1.0,1.5,20.0);

    // Set up the camera position and orientation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3.0,4.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);

    // Set the color of the cube to be rendered
    glColor3f(1.0,1.0,1.0);

    // Enable clipping
    glEnable(GL_CLIP_PLANE0);

    // Define the clipping plane
    GLdouble plane[] = {1.0,1.0,1.0,0.0};
    glClipPlane(GL_CLIP_PLANE0,plane);

    // Render the cube
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,vertices);
    glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,indices);
    glDisableClientState(GL_VERTEX_ARRAY);

    // Disable clipping
    glDisable(GL_CLIP_PLANE0);

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Clipping in OpenGL");
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

    return 0;
}

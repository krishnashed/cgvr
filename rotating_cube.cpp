#include <GL/glut.h>
/** Vertices of a coob */
float vertices[8][3] = {-1, -1, -1,
                        1, -1, -1,
                        1, 1, -1,
                        -1, 1, -1,
                        -1, 1, 1,
                        1, 1, 1,
                        1, -1, 1,
                        -1, -1, 1};
/** Colors of each vertex of a coob */
float colors[8][3] = {0, 0, 0,
                      1, 0, 0,
                      1, 1, 0,
                      0, 1, 0,
                      0, 1, 1,
                      1, 1, 1,
                      1, 0, 1,
                      0, 0, 1};
// use GLubyte *OR* unsigned char
GLubyte elementindices[] = {
    0, 1, 2, 3,
    0, 1, 6, 7,
    0, 3, 4, 7,
    2, 5, 6, 1,
    3, 4, 5, 2,
    7, 4, 5, 6};

void drawCube()
{
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, elementindices);
}

void disp()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawCube();
    glFlush();
    glutSwapBuffers();
}

void idle()
{
    // bruh just rotate
    glRotatef(.1, 1, 0, 0);
    glRotatef(.2, 0, 1, 0);
    glRotatef(.3, 0, 0, 1);
    glutPostRedisplay();
}

inline void myinit()
{
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    // perspective op
    // just pass fov, aspect ratio (just keep it 1 if square), and near and far
    gluPerspective(80, 1, .1, 15.f);
    // move the cube a bit away
    glTranslatef(0, 0, -6);
}

void res(int w, int h)
{
    glViewport(0, 0, w, h);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotating cube");
    glutDisplayFunc(disp);
    glutIdleFunc(idle);
    glutReshapeFunc(res);

    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3, GL_FLOAT, 3 * sizeof(float), vertices);
    glColorPointer(3, GL_FLOAT, 3 * sizeof(float), colors);
    myinit();
    glutMainLoop();
    return 0;
}
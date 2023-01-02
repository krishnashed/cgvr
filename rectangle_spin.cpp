#include <GL/glut.h>
#include <iostream>
uint id1, id2;

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex2i(50, 50);
    glColor3f(0, 1, 0);
    glVertex2i(50, 250);
    glColor3f(1, 0, 0);
    glVertex2i(250, 250);
    glColor3f(1, 1, 1);
    glVertex2i(250, 50);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

void idle2()
{
    glutSetWindow(id2);
    glTranslatef(150, 150, 0);
    glRotatef(.10, 0, 0, 1);
    glTranslatef(-150, -150, 0);
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);

    id1 = glutCreateWindow("1");
    glutDisplayFunc(draw);
    gluOrtho2D(0, 500, 0, 500);

    id2 = glutCreateWindow("2");
    glutDisplayFunc(draw);
    gluOrtho2D(0, 500, 0, 500);

    glutIdleFunc(idle2);
    glutMainLoop();
}
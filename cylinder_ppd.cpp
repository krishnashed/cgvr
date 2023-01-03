#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;
uint id1, id2;

void drawRectangle(int x0, int y0, int x1, int y1)
{
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex2i(x0, y0);
    glVertex2i(x0, y1);
    glVertex2i(x1, y1);
    glVertex2i(x1, y0);
    glEnd();
    glFlush();
}

void drawPPD()
{
    for (int i = 0; i < 50; i += 5)
    {
        drawRectangle(250 + i, 250 - i, 350 + i, 350 - i);
    }
    glutSwapBuffers();
}

void drawPoints(int x0, int y0, int x, int y)
{
    glVertex2i(x0 + x, y0 + y);
    glVertex2i(x0 + x, y0 - y);
    glVertex2i(x0 - x, y0 + y);
    glVertex2i(x0 - x, y0 - y);

    glVertex2i(x0 + y, y0 + x);
    glVertex2i(x0 + y, y0 - x);
    glVertex2i(x0 - y, y0 + x);
    glVertex2i(x0 - y, y0 - x);
}

void drawCircle(int x0, int y0, int r)
{

    int x = 0, y = r, p = 3 - 2 * r;
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    while (x < y)
    {
        drawPoints(x0, y0, x, y);
        if (p < 0)
        {
            p = p + 4 * x + 6;
        }
        else
        {
            p = p + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
    glEnd();
    glFlush();
}

void drawCylinder()
{
    for (int i = 0; i < 50; i += 5)
    {
        drawCircle(250, 250 - i, 50);
    }
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);

    id1 = glutCreateWindow("Cylinder");
    glutDisplayFunc(drawCylinder);
    gluOrtho2D(0, 500, 0, 500);

    id2 = glutCreateWindow("PPD");
    glutDisplayFunc(drawPPD);
    gluOrtho2D(0, 500, 0, 500);

    glutMainLoop();
}
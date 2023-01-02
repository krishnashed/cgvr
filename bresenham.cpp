#include <GL/glut.h>
#include <iostream>
#include <math.h>

int x1, x2, yc1, y2, flag = 0;

void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawLine()
{
    int x, y, dx, dy, p, incx = 1, incy = 1, i;
    dx = x2 - x1;
    dy = y2 - yc1;

    if (dx < 0)
        dx = -1 * dx;
    if (dy < 0)
        dy = -1 * dy;
    if (x2 < x1)
        incx = -1;
    if (y2 < yc1)
        incy = -1;
    x = x1;
    y = yc1;
    if (dy < dx)
    {
        p = 2 * dy - dx;
        for (i = 0; i < dx; i++)
        {
            drawPixel(x, y);
            if (p < 0)
            {
                p = p + 2 * dy;
            }
            else
            {
                p = p + 2 * (dy - dx);
                y = y + incy;
            }
            x = x + incx;
        }
    }
    else
    {
        p = 2 * dx - dy;
        for (i = 0; i < dy; i++)
        {
            drawPixel(x, y);
            if (p < 0)
            {
                p = p + 2 * dx;
            }
            else
            {
                p = p + 2 * (dx - dy);
                x = x + incx;
            }
            y = y + incy;
        }
    }
    glFlush();
}

void mouseHandler(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (flag == 0)
        {
            x1 = x - 250;
            yc1 = 250 - y;
            flag = 1;
        }
        else
        {
            x2 = x - 250;
            y2 = 250 - y;
            drawLine();
            flag = 0;
        }
    }
}

void dummy() {}

void myInit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 1);
    glColor3f(0, 0, 1);
    glPointSize(3);
    gluOrtho2D(-250, 250, -250, 250);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Line drawing");

    glutMouseFunc(mouseHandler);
    glutDisplayFunc(dummy);
    myInit();
    glutMainLoop();
}
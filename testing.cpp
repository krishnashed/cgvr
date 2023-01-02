#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;

int x_1, y_1, x_2, y_2, point1_done = 0;

void drawPoint(int x, int y)
{
    glBegin(GL_POINTS);
    glColor3f(0, 0, 1);
    glVertex2i(x, y);
    glEnd();
}

void drawLine()
{
    int x, y, dx, dy, p, xinc = 1, yinc = 1;
    cout << "x1 = " << x_1 << " y1 = " << y_1 << " x2 = " << x_2 << " y2 = " << y_2 << "\n";
    dx = x_2 - x_1;
    dy = y_2 - y_1;

    if (dx < 0)
        dx = -1 * dx;
    if (dy < 0)
        dy = -1 * dy;
    if (x_2 < x_1)
        xinc = -1;
    if (y_2 < y_1)
        yinc = -1;
    x = x_1;
    y = y_1;

    if (dy < dx)
    {
        p = 2 * dy - dx;

        for (int i = 0; i < dx; i++)
        {
            drawPoint(x, y);

            if (p < 0)
            {
                p = p + 2 * dy;
            }
            else
            {
                p = p + 2 * (dy - dx);
                y = y + yinc;
            }
            x = x + xinc;
        }
    }
    else
    {
        p = 2 * dx - dy;

        for (int i = 0; i < dy; i++)
        {
            drawPoint(x, y);

            if (p < 0)
            {
                p = p + 2 * dx;
            }
            else
            {
                p = p + 2 * (dx - dy);
                x = x + xinc;
            }
            y = y + yinc;
        }
    }
    glFlush();
}

void mouseHandler(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (point1_done == 0)
        {
            x_1 = x - 250;
            y_1 = 250 - y;
            point1_done = 1;
        }
        else
        {
            x_2 = x - 250;
            y_2 = 250 - y;
            drawLine();
            point1_done = 0;
        }
    }
}

void myInit()
{
    glClearColor(0, 0, 0, 1);
    glColor3f(0, 0, 1);
    glPointSize(3);
    gluOrtho2D(-250, 250, -250, 250);
}

void dummy() {}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Lines");
    glutMouseFunc(mouseHandler);
    glutDisplayFunc(dummy);
    myInit();

    glutMainLoop();
}
#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;

int xc, yc, r;
int px1, px2, py1, py2, point1_done = 0;

void drawCircle(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc - y, yc - x);
    glEnd();
}

void bresenham()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x = 0, y = r;
    int p = 3 - 2 * r;

    while (x <= y)
    {
        drawCircle(x, y);
        x++;
        if (p < 0)
        {
            p = p + 4 * x + 6;
        }
        else
        {
            p = p + 4 * (x - y) + 10;
            y--;
        }
    }

    glFlush();
}

void mouseFunc(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && point1_done == 0)
    {
        px1 = x - 250;
        py1 = 250 - y;
        xc = px1;
        yc = py1;
        point1_done = 1;
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        float exp;
        px2 = x - 250;
        py2 = 250 - y;
        exp = (px2 - px1) * (px2 - px1) + (py2 - py1) * (py2 - py1);
        r = (int)(sqrt(exp));
        bresenham();
        point1_done = 0;
    }
}

void myInit()
{
    glClearColor(1, 1, 1, 1);
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(3);
    gluOrtho2D(-250, 250, -250, 250);
}

void dummyDraw() {}

int main(int argc, char **argv)
{
    int choice;
    cout << "1. Keyboard\n2. Mouse\n";
    cin >> choice;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    switch (choice)
    {
    case 1:
        cin >> xc >> yc >> r;
        glutCreateWindow("Bresenhams Circle");
        glutDisplayFunc(bresenham);
        myInit();
        break;
    case 2:
        glutCreateWindow("Bresenhams Circle");
        glutMouseFunc(mouseFunc);
        glutDisplayFunc(dummyDraw);
        myInit();
        break;
    default:
        cout << "Invalid Entry\n";
    }
    glutMainLoop();
}
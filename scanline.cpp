#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int x[100], y[100], n, m;
static int xint[10] = {0};

void drawLine(int x1, int y1, int x2, int y2)
{
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
    glFlush();
    for (int i = 0; i < 1 << 24; i++)
    {
        i++;
    }
}

void findEdge(int x1, int y1, int x2, int y2, int sl)
{
    if (y2 < y1)
    {
        swap(x1, x2);
        swap(y1, y2);
    }
    if (sl > y1 && sl < y2)
    {
        xint[m++] = x1 + (sl - y1) * (x2 - x1) / (y2 - y1);
    }
}

void scanfill()
{
    for (int sl = 0; sl < 500; sl++)
    {
        m = 0;
        for (int i = 0; i < n; i++)
            findEdge(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n], sl);

        sort(xint, xint + m);

        if (m >= 2)
            for (int i = 0; i < m; i += 2)
            {
                drawLine(xint[i], sl, xint[i + 1], sl);
            }
    }
}

void display()
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; i++)
    {
        glVertex2i(x[i], y[i]);
    }
    glEnd();
    scanfill();
    glFlush();
}

void myInit()
{
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 500, 0, 500);
    glPointSize(2);
    glColor3f(1, 1, 1);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);

    cout << "Enter number of Vertices\n";
    cin >> n;
    cout << "Enter Vertices\n";
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    glutCreateWindow("Scanline");
    glutDisplayFunc(display);

    myInit();
    glutMainLoop();
}
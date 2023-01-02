#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;
typedef float vec2[2];
float m, c, t, xr, yr;
vec2 house[11] = {
    {100, 100},
    {140, 100},
    {140, 150},
    {160, 150},
    {160, 100},
    {200, 100},
    {200, 200},
    {220, 200},
    {150, 300},
    {80, 200},
    {100, 200},
};

void drawhouse()
{
    glBegin(GL_LINE_LOOP);
    for (auto v : house)
    {
        glVertex2fv(v);
    }
    glEnd();
}

void drawrefl()
{
    glColor3f(0, 1, 0);
    drawhouse();
    glColor3f(0, 0, 1);
    int x0 = 0, x1 = 500;
    int y1 = m * x1 + c, y0 = m * x0 + c;
    glBegin(GL_LINES);
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
    glEnd();
    glPushMatrix();
    glTranslatef(0, c, 0);
    float r = atan(m) * 180 / 3.14f;
    glRotatef(r, 0, 0, 1);
    glScalef(1, -1, 1);
    glRotatef(-r, 0, 0, 1);
    glTranslatef(0, -c, 0);
    glColor3f(1, 0, 0);
    drawhouse();
    glPopMatrix();
    glFlush();
}

void drawrot()
{
    glColor3f(0, 1, 0);
    drawhouse();
    glPushMatrix();
    glTranslatef(xr, yr, 0);
    glRotatef(t, 0, 0, 1);
    glTranslatef(-xr, -yr, 0);
    glColor3f(1, 0, 0);
    drawhouse();
    glPopMatrix();
    glFlush();
}

void myInit()
{
    gluOrtho2D(0, 500, 0, 500);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int c, char **v)
{
    glutInit(&c, v);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("House");
    int opt;
    cout << "Input 1 for Reflection, 2 for Rotation\n";
    cin >> opt;
    if (opt == 1)
    {
        cout << "m,c\n";
        cin >> m >> c;
        glutDisplayFunc(drawrefl);
    }
    if (opt == 2)
    {
        cout << "t,xr,yr\n";
        cin >> t >> xr >> yr;
        glutDisplayFunc(drawrot);
    }
    myInit();
    glutMainLoop();
}
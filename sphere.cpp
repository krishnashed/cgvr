#include <GL/glut.h>
#include <iostream>
#include <math.h>

// degrees to pi conversion factor
#define DPI (3.14 / 180.f)

void sphere()
{
    float p, p1, p2, t, thetar, x, y, z, c80, xc, yc;
    for (p = -80; p <= 80; p += 10)
    {
        p1 = DPI * p;
        p2 = DPI * (p + 10);

        glBegin(GL_QUAD_STRIP);
        for (t = -180; t <= 180; t += 10)
        {
            thetar = DPI * t;

            x = sin(thetar) * cos(p1);
            y = cos(thetar) * cos(p1);
            z = sin(p1);
            glVertex3f(x, y, z);

            x = sin(thetar) * cos(p2);
            y = cos(thetar) * cos(p2);
            z = sin(p2);
            glVertex3f(x, y, z);
        }
        glEnd();
    }

    // 1st pole – use triangle fans
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 0, 0);  // both triangle colors are affected by this
    glVertex3f(0, 0, 1); // top pole
    c80 = DPI * 80;
    z = sin(c80);
    for (t = -180; t <= 180; t += 10)
    {
        thetar = DPI * t;
        x = sin(thetar) * cos(c80);
        y = cos(thetar) * cos(c80);
        glVertex3f(x, y, z);
    }
    glEnd();

    // 2nd pole – use triangle fans
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, -1); // bottom pole
    z = -sin(c80);
    for (t = -180; t <= 180; t += 10)
    {
        thetar = DPI * t;
        x = sin(thetar) * cos(c80);
        y = cos(thetar) * cos(c80);
        glVertex3f(x, y, z);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // the quad doesn't get filled up and only boundary appears

    glLoadIdentity();
    glTranslatef(0, 0, -1);
    // change the below parameter to control the viewing angle
    glRotatef(60, 1, 1, 0); // rotate by how much angle and about which axis (angle,x,y,z)
    sphere();
    glFlush();
}

void myInit()
{
    glClearColor(1, 1, 1, 1);
    glColor3f(0, 0, 1);
    gluOrtho2D(-250, 250, -250, 250);
    glPointSize(1);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Sphere");
    glutDisplayFunc(display);

    myInit();
    glutMainLoop();
}
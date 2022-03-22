#include <stdio.h>
#include <GL/glut.h>
#include <math.h>


void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(10.0);
    glBegin(GL_POINTS);
    glVertex2i(80, 80);
    // glVertex2i(10, 145);
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 300);
    glutCreateWindow("my first attempt to draw a point");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

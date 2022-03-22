#include <GL/glut.h>
#include <iostream>
using namespace std;
void init(void)
{
	glClearColor(0.7, 0.7, 0.7, 0.7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 400, 0, 400);
}

void drawCircle(float r, float x, float y)
{
    float i = 0.0f;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y); // Center
    for (i = 0.0f; i <= 360; i++)
        glVertex2f(r * cos(M_PI * i / 180.0) + x, r * sin(M_PI * i / 180.0) + y);

    // glEnd();
}

void display()
{
    // glClearColor(1, 1, 1, 1);
    // glClear(GL_COLOR_BUFFER_BIT);
    // glColor3f(0.0, 0, 0);
    drawCircle(30,160,200);
    glFlush();
}



int main(int argc, char **argv)
{
   glutInit(&argc, argv);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(500, 500);
  glutCreateWindow("scan line");
  init();
  glutDisplayFunc(display);
  // glutDisplayFunc(midpoint_circle);
//   glutCreateMenu(ScanMenu);
//   glutMouseFunc(mouse);
//   glutAddMenuEntry("scanfill", 1);
//   glutAddMenuEntry("clear", 2);
//   glutAddMenuEntry("exit", 3);
//   glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutMainLoop();
  return 0;
}
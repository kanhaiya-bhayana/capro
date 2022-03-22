#include <stdio.h>
#include <GL/glut.h>
#include <math.h>



void init()
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,200.0,0.0,150.0);
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0,1.0,0.0);
  glPointSize(8.0);
  glBegin(GL_LINES);
    glVertex2i(10,10);
    glVertex2i(50,50);
  glEnd();

  glFlush();

}

int main(int argc, char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
  glutInitWindowPosition(50,100);
  glutInitWindowSize(400,300);
  glutCreateWindow("Points Display");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
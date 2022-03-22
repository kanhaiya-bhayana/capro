#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857

void display() {
 //glClearColor(1.0, 0.0, 0.0, 0.0); //black
  // glClearColor(0.0, 1.0, 0.0, 0.0); //green
 // glClearColor(0.0, 0.0, 1.0, 0.0); //blue
   glClearColor(1.0, 1.0, 1.0, 1.0); //white
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}


void init() {
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(100,200);
  glutCreateWindow("EMPTY WINDOW");
  glutDisplayFunc(display);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  init();
  glutMainLoop();
}

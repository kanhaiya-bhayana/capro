// #include<stdio.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
#include <math.h>
#include <cstdlib>
float xc, yc, r;


int ww = 600, wh = 500;  
float bgCol[3] = { 1.0,1.0,1.0 };  
float intCol[3] = { 1.0,0.0,0.0 };  
float fillCol[3] = { 0.4,0.5,0.0 };  
void setPixel(int pointx, int pointy, float f[3])  
{
  glBegin(GL_POINTS);  
  glColor3fv(f);  
  glVertex2i(pointx, pointy);  
  glEnd();  
  glFlush(); 
}  
void getPixel(int x, int y, float pixels[3]) 
{  
  glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, pixels); 
}
void plot_point(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(xc + x, yc + y);
  glVertex2i(xc + x, yc - y);
  glVertex2i(xc + y, yc + x);
  glVertex2i(xc + y, yc - x);
  glVertex2i(xc - x, yc - y);
  glVertex2i(xc - y, yc - x);
  glVertex2i(xc - x, yc + y);
  glVertex2i(xc - y, yc + x);
  glEnd();
}

void midpoint_circle(void)
{
  // glClearColor(1, 1, 1, 1);
  // glClear(GL_COLOR_BUFFER_BIT);
  // glColor3f(0.0, 0, 0);
  int x = 0, y = r;
  float p = 1 - r;
  while (x <= y)
  {
    plot_point(x, y);
    if (p < 0)
      p = p + 2 * x + 3;
    else
    {
      p = p + 2 * x + 5 - 2 * y;
      y--;
    }
    x++;
  }

  glFlush();
}

void floodfill4(int x, int y, float oldcolor[3], float newcolor[3])  { float color[3];  
getPixel(x, y, color);  
if (color[0] == oldcolor[0] && (color[1]) == oldcolor[1] && (color[2]) ==  oldcolor[2])  
{ 
  setPixel(x, y, newcolor);  
  floodfill4(x + 1, y, oldcolor, newcolor);  
  floodfill4(x - 1, y, oldcolor, newcolor);  
  floodfill4(x, y + 1, oldcolor, newcolor);  
  floodfill4(x, y - 1, oldcolor, newcolor);  
}  
} 
void mouse(int btn, int state, int x, int y)  
{  
if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
{
  int xi = x;  
  int yi = (wh - y);  
  floodfill4(xi, yi, intCol, fillCol);  
} 
} 
int le[500], re[500], flag = 0, m;
void init()
{
  gluOrtho2D(0, 500, 0, 500);
}
void edge(int x0, int y0, int x1, int y1)
{
  if (y1 < y0)
  {
    int tmp;
    tmp = y1;
    y1 = y0;
    y0 = tmp;
    tmp = x1;
    x1 = x0;
    x0 = tmp;
  }
  int x = x0;
  m = (y1 - y0) / (x1 - x0);
  for (int i = y0; i < y1; i++)
  {
    if (x < le[i])
      le[i] = x;
    if (x > re[i])
      re[i] = x;
    x += (1 / m);
  }
}
void display()
{
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0, 0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(200, 100);
  glVertex2f(100, 200);
  glVertex2f(200, 300);
  // glVertex2f(300, 200);
  glEnd();
  for (int i = 0; i < 500; i++)
  {
    le[i] = 500;
    re[i] = 0;
  }
  edge(200, 100, 100, 200);
  edge(100, 200, 200, 300);
  edge(200, 300, 300, 200);
  // edge(300, 200, 200, 100);
  if (flag == 1)
  {
    for (int i = 0; i < 500; i++)
    {
      if (le[i] < re[i])
      {
        for (int j = le[i]; j < re[i]; j++)
        {
          glColor3f(1, 0.5, 0.0);
          glBegin(GL_POINTS);
          glVertex2f(j, i);
          glEnd();
        }
      }
    }
  }
  midpoint_circle();
  glFlush();
}
void ScanMenu(int id)
{
  if (id == 1)
    flag = 1;
  else if (id == 2)
    flag = 0;
  else
    exit(0);
  glutPostRedisplay();
}
int main(int argc, char **argv)
{
  cout << "Enter the value of centre x1 : ";
  cin >> xc;
  cout << "Enter the value of centre y1 : ";
  cin >> yc;
  cout << "Enter the value of radius : ";
  cin >> r;

  glutInit(&argc, argv);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(500, 500);
  glutCreateWindow("scan line");
  init();
  glutDisplayFunc(display);
  // glutDisplayFunc(midpoint_circle);
  glutCreateMenu(ScanMenu);
  glutMouseFunc(mouse);
  glutAddMenuEntry("scanfill", 1);
  glutAddMenuEntry("clear", 2);
  glutAddMenuEntry("exit", 3);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  glutMainLoop();
  return 0;
}
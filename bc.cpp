#include<GL/glut.h>
#include<iostream>
using namespace std;
float xc, yc, r;

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


void bresanham_circle(void) {
	int x=0, y=r;
	float d = 3 - 2 * r;	
	while (x <= y)
	{
		plot_point(x, y);
		if (d < 0)
			d = d + 4 * x + 6;
		else 
		{
		    d = d + 4 * x + 10 - 4 * y;
		    y--;
	    }
		x++;
	}
	glColor3f(0.0,0.0,0.0);
    // 
	glFlush();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0); //white
  glClear(GL_COLOR_BUFFER_BIT);
    // glFlush();
	// glClear(GL_COLOR_BUFFER_BIT);
    // glClearColor(0.7, 0.7, 0.7, 0.7); //white
    // glColor3f(0.0, 0.0, 0.0);
    // glFlush(); 
	glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	gluOrtho2D(0, 400, 0, 400);
}

int main(int argc, char** argv) {
	cout << "Enter the value of centre x1 : ";
	cin >> xc;
	cout << "Enter the value of centre y1 : ";
	cin >> yc;
	cout << "Enter the value of radius : ";
	cin >> r;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Circle Algo");
	init();
	glutDisplayFunc(bresanham_circle);
	glutMainLoop();

	return 0;
}
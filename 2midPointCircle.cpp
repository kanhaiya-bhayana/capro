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


void midpoint_circle(void) {
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

void init(void)
{
	glClearColor(0.7, 0.7, 0.7, 0.7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
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
	glutDisplayFunc(midpoint_circle);
	glutMainLoop();

	return 0;
}
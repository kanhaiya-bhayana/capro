#include<GL/glut.h>
#include<iostream>
using namespace std;
int a1, b1, rx, ry;

void plot(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x + a1, y + b1);
	glEnd();
}
void display(void) {
	float x, y, dx, dy, p;
	x = 0;
	y = ry;
	p = ry * ry - (rx * rx) * ry + (rx * rx) * 0.25;
	dx = 2 * (ry * ry) * x;
	dy = 2 * (rx * rx) * y;

	while (dx < dy) {
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		x++;
		if (p < 0) {
			dx = 2 * (ry * ry) * x;
			p = p + dx + (ry * ry);
		}
		else {
			y--;
			dx = 2 * (ry * ry) * x;
			dy = 2 * (rx * rx) * y;
			p = p + dx - dy + (ry * ry);
		}
	}
	float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y - 1) * (y - 1) - (rx * rx) * (ry * ry);


	while (y > 0)
	{
		//plot (x,y)
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		y--;
		if (p2 > 0)
		{
			x = x;
			dy = 2 * (rx * rx) * y;
			//dy = 2 * rx * rx *y;
			p2 = p2 - dy + (rx * rx);
		}
		else
		{
			x = x + 1;
			dy = dy - 2 * (rx * rx);
			dx = dx + 2 * (ry * ry);
			p2 = p2 + dx -
				dy + (rx * rx);
		}
	}
	glFlush();
}

void init(void)
{
	glClearColor(0.7, 0.7, 0.7, 0.7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char** argv) {
	cout << "Enter the value of x0 : ";
	cin >> a1;
	cout << "Enter the value of y0 : ";
	cin >> b1;
	cout << "Enter the value of semi-major axis : ";
	cin >> rx;
	cout << "Enter the value of semi-minor axis: ";
	cin >> ry;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Ellipse drawing algorithm");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
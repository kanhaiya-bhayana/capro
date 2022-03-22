#include<gl/glut.h>
#include<iostream>
using namespace std;
int a1, b1, r;

void plot(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x + a1, y + b1);
	glEnd();
}
void display(void) {
	int x, y, d;
	x = 0;
	y = r;
	d = 3 - 2 * r;
	plot(x, y);

	while (x < y) {

		x++;
		if (d < 0) {
			d = d + (4 * x + 6);
		}
		else {
			d = d + 4 * (x - y) + 10;
			y--;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(y, -x);
		plot(-y, x);
		plot(-y, -x);

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
	cout << "Enter the value of radius : ";
	cin >> r;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bresenham's circle drawing algorithm");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
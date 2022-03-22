#include<GL/glut.h>
#include<iostream>
using namespace std;
int a1, a2, b1, b2;

void display(void) {
	int x, y, dx, dy, p;
	x = a1;
	y = b1;
	dx = a2 - a1;
	dy = b2 - b1;
	p = 2 * dx - dy;
	while (x <= a2) {
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
		x++;
		if (p < 0) {
			p = p + 2 * dy;
		}
		else {
			p = p + 2 * dy - 2 * dx;
			y++;
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
	cout << "Enter the value of x1 : ";
	cin >> a1;
	cout << "Enter the value of y1 : ";
	cin >> b1;
	cout << "Enter the value of x2 : ";
	cin >> a2;
	cout << "Enter the value of y2 : ";
	cin >> b2;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bresenham line algorithm");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
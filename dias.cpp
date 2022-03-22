#include<GL/glut.h>
#include <iostream>
// #include <windows.h>
using namespace std;
// Salman Aslam

void SalmanAslamDisplay(void); // define function to display output
void SalmanAslamDrawDot();	// define function to draw dots

void SalmanAslamDrawDot(){
	// base vertex
	glVertex2f(100, 100);
	glVertex2f(400, 100);
	// right straight line upward
	glVertex2f(400, 100);	
	glVertex2f(400, 300);	
	// curve left upward
	glVertex2f(400, 300);
	glVertex2f(250,400);	
	// curve downward 
	glVertex2f(250, 400);
	glVertex2f(100, 300);	
	// left straight downward
	glVertex2f(100, 300);
	glVertex2f(100, 100); 
	// door code
	// lett up
	glVertex2f(200, 100);
	glVertex2f(200, 200);
	// left to right
	glVertex2f(200, 200);
	glVertex2f(300, 200);
	// rigt down
	glVertex2f(300, 200);
	glVertex2f(300, 100);
	// door center
	glVertex2f(200, 100);
	glVertex2f(250, 100);
	// center line of gate
	glVertex2f(250, 100);
	glVertex2f(250, 200);
	// window code
	//top line
	glVertex2f(150, 300);
	glVertex2f(350, 300);
	//right down
	glVertex2f(350, 300);
	glVertex2f(350, 250);
	//right to left
	glVertex2f(350, 250);
	glVertex2f(150, 250);
	//left down to up
	glVertex2f(150, 250);
	glVertex2f(150, 300);
	//horizontal line of window
	glVertex2f(250, 250);
	glVertex2f(250, 300);
	// verticle line of window
	glVertex2f(150, 275);
	glVertex2f(350, 275);



}

void Init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 500, 0, 500, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void SalmanAslamDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Code to draw
	glBegin(GL_LINES);
	SalmanAslamDrawDot(); // function to draw dots
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char **argv) {
	glutInitWindowSize(500, 500);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutCreateWindow("Salman Aslam Assignment No#2");
	Init();
	glutDisplayFunc(SalmanAslamDisplay); // call function to display output
	glutMainLoop();
	return 0;
}
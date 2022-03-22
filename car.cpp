#include<GL/glut.h>
#include <iostream>
using namespace std;
#include<math.h>

void init(){
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,800,0.0,600);
}

void wheel(int x, int y) {
	float th;
	glBegin(GL_POLYGON);
	glColor3f(0,0,0); 
	for(int i=0;i<360;i++) { // generate all points in circle
		th=i*(3.1416/180);
		glVertex2f(x+30*cos(th),y+30*sin(th));
	}
	glEnd();
}

void small_wheel(int x,int y) {
	float th;
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	for(int i=0;i<360;i++) {
		th=i*(3.1416/180);
		glVertex2f(x+8*cos(th),y+8*sin(th));
	}
	glEnd();
}

void car() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3,0.5,0.8);
	glBegin(GL_POLYGON); // rectangle base
	glVertex2f(200,300);
	glVertex2f(200,400);
	glVertex2f(600,400);
	glVertex2f(600,300);
	glEnd();
	glColor3f(0.0,0.0,0.0);	 // upper windows
	glBegin(GL_POLYGON);
	glVertex2f(200,370);
	glVertex2f(220,370);
	glVertex2f(220,350);
	glVertex2f(200,350);
	glEnd();
	glColor3f(0.0,0.0,0.0);	// headlights
	glBegin(GL_POLYGON);
	glVertex2f(200,330);
	glVertex2f(220,330);
	glVertex2f(220,310);
	glVertex2f(200,310);
	glEnd();
	glColor3f(0.0,0.0,0.0);	// headlights
	glBegin(GL_POLYGON);
	glVertex2f(580,380);
	glVertex2f(600,380);
	glVertex2f(600,360);
	glVertex2f(580,360);
	glEnd();
	glColor3f(0.0,0.0,0.0);	// headlights
	glBegin(GL_POLYGON);
	glVertex2f(580,340);
	glVertex2f(600,340);
	glVertex2f(600,320);
	glVertex2f(580,320);
	glEnd();
	glColor3f(0.7,0.2,0.3); // headlights
	glBegin(GL_POLYGON);
	glVertex2f(250,400);
	glVertex2f(330,500);
	glVertex2f(470,500);
	glVertex2f(550,400);
	glEnd();
	wheel(330,280); // outer wheel
	wheel(470,280);
	small_wheel(330,280); // inner white wheel
	small_wheel(470,280);
	/*
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(0,250);
	glVertex2f(800,250);
	glEnd();
	*/
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(350,500);
	glVertex2f(350,400);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(450,500);
	glVertex2f(450,400);
	glEnd();
	glFlush();
}
int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("Car");
	init();
	glutDisplayFunc(car);
	glutMainLoop();
    return 0;
}
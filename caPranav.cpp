#include <GLUT/glut.h>
#include <iostream>
using namespace std;

// Function to initialize the drivers
void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}

void DisplayScreen(void)
{
    glPointSize(10.0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(200.0, 100.0);
    glEnd();
    glFlush();
}

void plot(int x, int y, int a1, int a2)
{
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(a1+x, a2+y);
    glEnd();
}

void Circle(int a1, int a2, float r)
{
    int x = 0;
    int y = r;
    float p = 1 - r;
    glPointSize(3.0);
    plot (x, y, a1, a2);
    
    while(x<y)
    {
        x++;
        if(p < 0)
        {
            p = p + 2*x + 1;
        }
        else{
            y--;
            p = p + 2*x - 2*y + 1;
        }
        plot(x, y, a1, a2);
        plot(x, -y, a1, a2);
        plot(-x, y, a1, a2);
        plot(-x, -y, a1, a2);
        plot(y, x, a1, a2);
        plot(-y, x, a1, a2);
        plot(y, -x, a1, a2);
        plot(-y, -x, a1, a2);
    }
    
}
// Function to display the Hut like
// structure on the console
void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(200, 400);
    glVertex2i(200, 300);
    glVertex2i(600, 300);
    glVertex2i(600, 400);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(330, 500);
    glVertex2i(470, 500);
    glVertex2i(550, 400);
    glVertex2i(250, 400);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(3.0);
    glVertex2i(330, 500);
    glVertex2i(330, 400);
    glEnd();
    
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(3.0);
    glVertex2i(470, 500);
    glVertex2i(470, 400);
    glEnd();
    
    Circle(335, 300, 30);
    Circle(465, 300, 30);
    Circle(335, 300, 10);
    Circle(465, 300, 10);
    
    glFlush();
    
}
int main(int argc, char** argv)
{
    // Initialize the init function
    glutInit(&argc, argv);

    // Initialize the toolkit;
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Sets the display mode and
    // specify the colour scheme
    glutInitWindowSize(1000, 1000);

    // Specify the window size
    glutInitWindowPosition(0, 0);

    // Sets the starting position
    // for the window
    glutCreateWindow("Basic hut like structure");

    // Creates the window and
    // sets the title
    myInit();
    glutDisplayFunc(Display);

    glutMainLoop();
    return 0;
}
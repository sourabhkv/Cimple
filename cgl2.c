BANGALORE INSTITUTE OF TECHNOLOGY
K R ROAD, V V  PURAM, BANGALORE-04

DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING


Course Title: COMPUTER GRAPHICS AND IMAGE PROCESSING LABORATORY	    Course Code: 21CSL66
No. of Lecture Hrs./Week: 02P                                                                	    Exam Hours: 03
Total No. of Lecture Hrs.: 24                                                                    	    Exam Marks: 50
Faculty Incharges: Dr.Girija J, Dr.Bhanushree K J, Dr.Gunavathi H S

Week 2 - Sample programs

1.Write a program to Draw a triangle with OpenGL.


#include<stdio.h>
#include<GL/glut.h>
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,1.0,0.0);
 glBegin(GL_TRIANGLES);
  	glVertex3f(2.0,4.0,0.0);
  	glVertex3f(6.0,4.0,0.0);
	glVertex3f(4.0,6.0,0.0);
 glEnd();
 glFlush();
}

int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

 glutInitWindowPosition(100,100);
 glutInitWindowSize(600,600);
 glutCreateWindow("triangle");

 glClearColor(0.0,0.0,0.0,0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(0.0,10.0,0.0,10.0,-1.0,1.0);

 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}

 

2.Write a program to Draw a quadrilateral with OpenGL.

#include<stdio.h>
#include<GL/glut.h>
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,1.0,0.0);
 glBegin(GL_QUADS);
  	glVertex3f(2.0,4.0,0.0);
  	glVertex3f(6.0,4.0,0.0);
	glVertex3f(8.0,6.0,0.0);
 	glVertex3f(4.0,6.0,0.0);
 glEnd();
 glFlush();
}

int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

 glutInitWindowPosition(100,100);
 glutInitWindowSize(600,600);
 glutCreateWindow("quads");

 glClearColor(1.0,0.0,0.0,1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(0.0,10.0,0.0,10.0,-1.0,1.0);

 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
 

3.Write a program to Draw a Rectangle with OpenGL
#include<stdio.h>
#include<GL/glut.h>
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,1.0,0.0);
 glBegin(GL_POLYGON);
  	glVertex3f(2.0,4.0,0.0);
  	glVertex3f(8.0,4.0,0.0);
  	glVertex3f(8.0,6.0,0.0);
  	glVertex3f(2.0,6.0,0.0);
 glEnd();
 glFlush();
}

int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowPosition(100,100);
 glutInitWindowSize(300,300);
 glutCreateWindow("square");
 glClearColor(0.0,0.0,0.0,0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(0.0,10.0,0.0,10.0,-1.0,1.0);
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
 


4.Write a program to Draw a Triangle strip with OpenGL.
(Try quad strip((GL_QUAD_STRIP))

#include<stdio.h>
#include<GL/glut.h>
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_TRIANGLE_STRIP);
	
	glColor3f(1.0,0.0,0.0);
  	glVertex3f(2.0,4.0,0.0);
  	glVertex3f(3.0,5.0,0.0);
  	glVertex3f(4.0,4.0,0.0);
	
	glColor3f(0,1.0,0.0);
	glVertex3f(3.0,5.0,0.0);
  	glVertex3f(4.0,4.0,0.0);
  	glVertex3f(5.0,5.0,0.0);
	

  	glColor3f(1.0,0.0,0.0);
	glVertex3f(4.0,4.0,0.0);
  	glVertex3f(5.0,5.0,0.0);
	glVertex3f(6.0,4.0,0.0);
	
	glColor3f(0.0,0.0,1.0);
	glVertex3f(5.0,5.0,0.0);
	glVertex3f(6.0,4.0,0.0);
	glVertex3f(7.0,5.0,0.0);
	
	glColor3f(0,1.0,1.0);
	glVertex3f(6.0,4.0,0.0);
	glVertex3f(7.0,5.0,0.0);
  	glVertex3f(8.0,4.0,0.0);
	
 glEnd();
 glFlush();
}

int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

 glutInitWindowPosition(100,100);
 glutInitWindowSize(600,600);
 glutCreateWindow("TriangleStrip");

 glClearColor(0.0,0.0,0.0,1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(0.0,10.0,0.0,10.0,-1.0,1.0);

 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}

 


4.Write a program to Draw a Triangle Fan with OpenGL.

#include<stdio.h>
#include<GL/glut.h>
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_TRIANGLE_FAN);
	
	glColor3f(1.0,0.0,0.0);
  	glVertex3f(4.0,4.0,0.0);
  	glVertex3f(3.0,6.0,0.0);
  	glVertex3f(5.0,6.0,0.0);
	
	glColor3f(0.0,1.0,0.0);
	glVertex3f(4.0,4.0,0.0);
  	glVertex3f(5.0,6.0,0.0);
  	glVertex3f(7.0,4.5,0.0);
	

  	glColor3f(0.0,0.0,1.0);
	glVertex3f(4.0,4.0,0.0);
  	glVertex3f(7.0,4.5,0.0);
	glVertex3f(7.0,3.5,0.0);
	
	glColor3f(1.0,0.0,0.0);
	glVertex3f(4.0,4.0,0.0);
	glVertex3f(7.0,3.5,0.0);
	glVertex3f(5.0,2.0,0.0);
	
	glColor3f(0.0,1.0,0.0);
	glVertex3f(4.0,4.0,0.0);
	glVertex3f(5.0,2.0,0.0);
  	glVertex3f(3.0,2.0,0.0);

	glColor3f(0.0,0.0,1.0);
	glVertex3f(4.0,4.0,0.0);
	glVertex3f(3.0,2.0,0.0);
  	glVertex3f(1.0,3.5,0.0);

	glColor3f(1.0,0.0,0.0);
	glVertex3f(4.0,4.0,0.0);
	glVertex3f(1.0,3.5,0.0);
  	glVertex3f(1.0,4.5,0.0);

	glColor3f(0.0,1.0,0.0);
	glVertex3f(4.0,4.0,0.0);
	glVertex3f(1.0,4.5,0.0);
  	glVertex3f(3.0,6.0,0.0);
	
 glEnd();
 glFlush();
}

int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

 glutInitWindowPosition(100,100);
 glutInitWindowSize(600,600);
 glutCreateWindow("TriangleFan");

 glClearColor(0.0,0.0,0.0,1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(0.0,10.0,0.0,10.0,-1.0,1.0);

 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}

 


5.Write a program to Draw a triangle with OpenGL (number of vertices and vertex values needs to be entered)


#include<stdio.h>
#include<GL/glut.h>
void display(void)
{
 int i;
 float a[10][10];
 printf("Enter the no of vertices\n");
 for(i=0;i<3;i++)
{
	printf("Enter the values for traingle vertex %d ",i+1);
	scanf("%f %f %f",&a[i][0],&a[i][1],&a[i][2]);
}
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,1.0,0.0);
 glBegin(GL_POLYGON);
  	glVertex3f(a[0][0],a[0][1],a[0][2]);
  	glVertex3f(a[1][0],a[1][1],a[1][2]);
	glVertex3f(a[2][0],a[2][1],a[2][2]);
 glEnd();
 glFlush();
}

int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

 glutInitWindowPosition(100,100);
 glutInitWindowSize(600,600);
 glutCreateWindow("triangle input");

 glClearColor(1.0,0.0,0.0,1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(0.0,10.0,0.0,10.0,-1.0,1.0);

 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}

Try GL_LINE_LOOP
Try GL_LINE_STRIP
Try GL_POINTS







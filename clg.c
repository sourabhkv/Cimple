BANGALORE INSTITUTE OF TECHNOLOGY
K R ROAD, V V  PURAM, BANGALORE-04

DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING


Course Title: COMPUTER GRAPHICS AND IMAGE PROCESSING LABORATORY	    Course Code: 21CSL66
No. of Lecture Hrs./Week: 02P                                                                	    Exam Hours: 03
Total No. of Lecture Hrs.: 24                                                                    	    Exam Marks: 50

Faculty Incharges: Dr.Girija J,Dr.Bhanushree K J,Dr.Gunavathi H S

Week 1-Sample programs

1.Write a progrm to Draw a line with openGL.

#include <stdio.h> 
#include <GL/glut.h> 

void display(void) 
{  
 glClear( GL_COLOR_BUFFER_BIT); 
 glColor3f(0.0, 1.0, 0.0); 
 glBegin(GL_LINES); 
  glVertex3f(2.0, 4.0, 0.0); 
  glVertex3f(8.0, 4.0, 0.0); 
  
 glEnd(); 
 glFlush(); 
} 

int main(int argc, char **argv) 
{ 
 
 glutInit(&argc, argv); 
 glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); 

 glutInitWindowPosition(100,100); 
 glutInitWindowSize(300,300); 
 glutCreateWindow ("Line"); 

 glClearColor(0.0, 0.0, 0.0, 0.0);         // black background 
 glMatrixMode(GL_PROJECTION);              // setup viewing projection 
 glLoadIdentity();                           // start with identity matrix 
 glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0); // setup a 10x10x2 viewing world 

 glutDisplayFunc(display); 
 glutMainLoop(); 

 return 0; 
}
2.Draw a square with openGL.
#include <stdio.h> 
#include <GL/glut.h> 

void display(void) 
{  
 glClear( GL_COLOR_BUFFER_BIT); 
 glColor3f(0.0, 1.0, 0.0); 
 glBegin(GL_POLYGON); 
  glVertex3f(2.0, 4.0, 0.0); 
  glVertex3f(8.0, 4.0, 0.0); 
  glVertex3f(8.0, 6.0, 0.0); 
  glVertex3f(2.0, 6.0, 0.0); 
 glEnd(); 
 glFlush(); 
} 

int main(int argc, char **argv) 
{ 
 
 glutInit(&argc, argv); 
 glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); 

 glutInitWindowPosition(100,100); 
 glutInitWindowSize(300,300); 
 glutCreateWindow ("square"); 

 glClearColor(0.0, 0.0, 0.0, 0.0);         // black background 
 glMatrixMode(GL_PROJECTION);              // setup viewing projection 
 glLoadIdentity();                           // start with identity matrix 
 glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   // setup a 10x10x2 viewing world 

 glutDisplayFunc(display); 
 glutMainLoop(); 

 return 0; 
}









3.Draw a triangle with openGL.
#include <stdio.h> 
#include <GL/glut.h> 

void display(void) 
{  
 glClear( GL_COLOR_BUFFER_BIT); 
 glColor3f(0.0, 1.0, 0.0); 
 glBegin(GL_TRIANGLES); 
  glVertex3f(2.0, 4.0, 0.0); 
  glVertex3f(8.0, 4.0, 0.0); 
  glVertex3f(8.0, 6.0, 0.0); 
  
 glEnd(); 
 glFlush(); 
} 

int main(int argc, char **argv) 
{ 
 
 glutInit(&argc, argv); 
 glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); 

 glutInitWindowPosition(100,100); 
 glutInitWindowSize(300,300); 
 glutCreateWindow ("Triangles"); 

 glClearColor(0.0, 0.0, 0.0, 0.0);         // black background 
 glMatrixMode(GL_PROJECTION);              // setup viewing projection 
 glLoadIdentity();                           // start with identity matrix 
 glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   // setup a 10x10x2 viewing world 

 glutDisplayFunc(display); 
 glutMainLoop(); 

 return 0; 
}


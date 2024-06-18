#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

GLfloat TriangleVertices[3][3] = {{100.0, 250.0, 175.0}, {100.0, 100.0, 300.0}, {1.0, 1.0, 1.0}};
GLfloat rotatement[3][3] = {{0}, {0}, {0}};
GLfloat Result[3][3] = {{0}, {0}, {0}};
GLfloat m = 0;
GLfloat n = 0;
float theta;
float rotation_angle;
float arbitrary_x, arbitrary_y;

void drawTriangle() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(TriangleVertices[0][0], TriangleVertices[1][0]);
    glVertex2f(TriangleVertices[0][1], TriangleVertices[1][1]);
    glVertex2f(TriangleVertices[0][2], TriangleVertices[1][2]);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawTriangle();
    
    glPushMatrix();
    glTranslatef(m, n, 0);
    glRotatef(theta, 0, 0, 1);
    glTranslatef(-m, -n, 0);
    drawTriangle();
    glPopMatrix();
    
    glFlush();
}

void myinit() {
    glClearColor(1, 1, 1, 1);
    glColor3f(1, 0, 0);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 449, 0, 499);
}

void rotateAboutOrigin() {
    theta = rotation_angle * 180.0 / M_PI;  // Convert radians to degrees
    m = 0;
    n = 0;
}

void rotateAboutFixedPoint() {
    theta = rotation_angle * 180.0 / M_PI;  // Convert radians to degrees
    m = arbitrary_x;
    n = arbitrary_y;
}

int main(int argc, char** argv) {
    int ch;
    printf("Enter your choice \n1: Rotation about origin \n2: Rotation about a Fixed point\n");
    scanf("%d", &ch);
    switch(ch) {
        case 1:
            printf("Enter the rotation angle in degrees: ");
            scanf("%f", &rotation_angle);
            rotation_angle = (M_PI * rotation_angle) / 180.0;  // Convert degrees to radians
            rotateAboutOrigin();
            break;
        case 2:
            printf("Enter the fixed points: ");
            scanf("%f %f", &arbitrary_x, &arbitrary_y);
            printf("Enter rotation angle in degrees: ");
            scanf("%f", &rotation_angle);
            rotation_angle = (M_PI * rotation_angle) / 180.0;  // Convert degrees to radians
            rotateAboutFixedPoint();
            break;
        default:
            printf("Invalid choice\n");
            return -1;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Triangle Rotation");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}

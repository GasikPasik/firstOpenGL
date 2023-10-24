#include <GL/glut.h>
#include <bits/stdc++.h>

//g++ lab1.cpp -o lab1 -lglut -lGLU -lGL

double rotateY = 0; 
double rotateX = 0;


void display() {
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();

    glRotatef( rotateX, 1.0, 0.0, 0.0 );
    glRotatef( rotateY, 0.0, 1.0, 0.0 );

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 0.5 );
    glVertex3f(  0.5, -0.5, -0.5 );      
    glVertex3f(  0.5,  0.5, -0.5 );      
    glVertex3f( -0.5,  0.5, -0.5 );      
    glVertex3f( -0.5, -0.5, -0.5 );     
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 1.0 );
    glVertex3f(  0.5, -0.5, 0.5 );
    glVertex3f(  0.5,  0.5, 0.5 );
    glVertex3f( -0.5,  0.5, 0.5 );
    glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(  1.0,  0.0,  1.0 );
    glVertex3f( 0.5, -0.5, -0.5 );
    glVertex3f( 0.5,  0.5, -0.5 );
    glVertex3f( 0.5,  0.5,  0.5 );
    glVertex3f( 0.5, -0.5,  0.5 );
    glEnd();

  
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  1.0,  0.0 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();

   
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  0.0,  1.0 );
    glVertex3f(  0.5,  0.5,  0.5 );
    glVertex3f(  0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5, -0.5 );
    glVertex3f( -0.5,  0.5,  0.5 );
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(   1.0,  0.0,  0.0 );
    glVertex3f(  0.5, -0.5, -0.5 );
    glVertex3f(  0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5,  0.5 );
    glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void specialKeys( int key, int x, int y ) {


    if (key == GLUT_KEY_RIGHT)
    rotateY += 5;
    

    else if (key == GLUT_KEY_LEFT)
    rotateY -= 5;

    else if (key == GLUT_KEY_UP)
    rotateX += 5;

    else if (key == GLUT_KEY_DOWN)
    rotateX -= 5;

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    
    
    glutCreateWindow("Cube");
    glutInitWindowSize(640, 480);

    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    
    glutMainLoop();
    
    return 0;
}
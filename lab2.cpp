#include <GL/glut.h>
#include <bits/stdc++.h>

//g++ lab1.cpp -o lab1 -lglut -lGLU -lGL

double rotateY = 0; 
double rotateX = 0;
double scale = 1;

void drawCube(float x, float y, float z){

    glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 0.5 );
    glVertex3f(  0.5 + x, -0.5 + y, -0.5 + z );      
    glVertex3f(  0.5 + x,  0.5 + y, -0.5 + z );      
    glVertex3f( -0.5 + x,  0.5 + y, -0.5 + z );      
    glVertex3f( -0.5 + x, -0.5 + y, -0.5 + z );     
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 1.0  );
    glVertex3f(  0.5 + x, -0.5 + y, 0.5 + z );
    glVertex3f(  0.5 + x,  0.5 + y, 0.5 + z );
    glVertex3f( -0.5 + x,  0.5 + y, 0.5 + z );
    glVertex3f( -0.5 + x, -0.5 + y, 0.5 + z );
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(  1.0 ,  0.0,  1.0 );
    glVertex3f( 0.5 + x, -0.5 + y, -0.5 + z );
    glVertex3f( 0.5 + x,  0.5 + y, -0.5 + z );
    glVertex3f( 0.5 + x,  0.5 + y,  0.5 + z );
    glVertex3f( 0.5 + x, -0.5 + y,  0.5 + z );
    glEnd();

  
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  1.0,  0.0 );
    glVertex3f( -0.5 + x, -0.5 + y,  0.5 + z );
    glVertex3f( -0.5 + x,  0.5 + y,  0.5 + z );
    glVertex3f( -0.5 + x,  0.5 + y, -0.5 + z );
    glVertex3f( -0.5 + x, -0.5 + y, -0.5 + z );
    glEnd();

   
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  0.0,  1.0 );
    glVertex3f(  0.5 + x,  0.5 + y,  0.5 + z );
    glVertex3f(  0.5 + x,  0.5 + y, -0.5 + z );
    glVertex3f( -0.5 + x,  0.5 + y, -0.5 + z );
    glVertex3f( -0.5 + x,  0.5 + y,  0.5 + z );
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(   1.0,  0.0,  0.0 );
    glVertex3f(  0.5 + x, -0.5 + y, -0.5 + z );
    glVertex3f(  0.5 + x, -0.5 + y,  0.5 + z );
    glVertex3f( -0.5 + x, -0.5 + y,  0.5 + z );
    glVertex3f( -0.5 + x, -0.5 + y, -0.5 + z );
    glEnd();
}

void drawTetrahedron(float x, float y, float z){

 glBegin(GL_POLYGON);

    glColor3f( 1.0, 0.0, 1.0 ); glVertex3f( 0.5 + x, -0.5 + y, -0.5 + z );      
    glColor3f(  1.0,  1.0, 1.0);
    glVertex3f( x,  0.5 + y, z );      
    glVertex3f( x,  0.5 + y, z );    
    glColor3f( 0.0,  1.0,  0.0); glVertex3f( -0.5 + x, -0.5 + y, -0.5 + z );     
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(  1.0, 0.0,  0.0 ); glVertex3f( 0.5 + x, -0.5 + y, 0.5 + z );
    glColor3f(  1.0,  1.0, 1.0);
    glVertex3f( x,  0.5 + y, z );
    glVertex3f( x,  0.5 + y, z );
    glColor3f(  1.0,  1.0, 0.5 ); glVertex3f( -0.5 + x, -0.5 + y, 0.5 + z );
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f( 1.0, 0.0, 1.0 );  glVertex3f( 0.5 + x, -0.5 + y, -0.5 + z );
    glColor3f(  1.0,  1.0, 1.0);
    glVertex3f( x,  0.5 + y, z );
    glVertex3f( x,  0.5 + y, z );
    glColor3f(  1.0, 0.0,  0.0 ); glVertex3f( 0.5 + x, -0.5 + y,  0.5 + z );
    glEnd();

  
    glBegin(GL_POLYGON);
    glColor3f(  1.0,  1.0, 0.5 ); glVertex3f( -0.5 + x, -0.5 + y,  0.5 + z );
    glColor3f(  1.0,  1.0, 1.0);
    glVertex3f( x, 0.5 + y, z );
    glVertex3f( x, 0.5 + y, z );
    glColor3f( 0.0,  1.0,  0.0);  glVertex3f( -0.5 + x, -0.5 + y, -0.5 + z );
    glEnd();

   
    glBegin(GL_POLYGON);
    glColor3f(  1.0, 0.0,  0.0 ); glVertex3f(  0.5 + x, -0.5 + y, -0.5 + z );
    glColor3f( 0.0,  1.0,  0.0); glVertex3f(  0.5 + x, -0.5 + y,  0.5 + z );
    glColor3f( 1.0, 0.0, 1.0 ); glVertex3f( -0.5 + x, -0.5 + y,  0.5 + z );
    glColor3f(  1.0,  1.0, 0.5 ); glVertex3f( -0.5 + x, -0.5 + y, -0.5 + z );
    glEnd();
}

void display() {
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glScalef( scale, scale, scale );

    glRotatef( rotateX, 1.0, 0.0, 0.0 );
    glRotatef( rotateY, 0.0, 1.0, 0.0 );
  


    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    drawTetrahedron(0.8, 0, 00);
    drawCube(-0.8, 0, 0);

    glFlush();
    glutSwapBuffers();
}
void mouseClick(int btn, int state, int x, int y) {
  if (state == GLUT_DOWN) {
    switch(btn) {
    case 3:  //mouse wheel scrolls
            scale += 0.05;

      break;
    case 4:
      if(scale > 0.05)
        scale -= 0.05;

      break;
    default:
      break;
    }
  }
  glutPostRedisplay();
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
    glutMouseFunc(mouseClick);
    glutSpecialFunc(specialKeys);
    
    glutMainLoop();
    
    return 0;
}
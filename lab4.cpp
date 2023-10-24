#include <GL/glut.h>
#include <bits/stdc++.h>

//g++ lab1.cpp -o lab1 -lglut -lGLU -lGL
#define PI 3.14159265 
using namespace std;

double rotateY = 0; 
double rotateX = 0;
double scale = 1;

float speedUpdate = 0.05;
double curTime = 0;
float widthFlag = 14;
float heightFlag = 8;
float step = 0.004;


void drawFlag(float x, float y, float z){
    float power = 0;
    for(float x = 0; x < widthFlag - step;){
        power += 0.0005;
        float curZ = sin(x + curTime)*power;
        float curZtmp = sin(x + step + curTime)*power;
        glBegin(GL_POLYGON);
        glVertex3f(x, y, curZ);      
        glVertex3f(x, y + heightFlag, curZ);      
        glVertex3f(x + step, y + heightFlag, curZtmp);      
        glVertex3f(x + step, y, curZtmp);      
        glEnd();
        x += step;
    }
    curTime += 0.05;

}


void display() {
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glScalef( scale, scale, scale );

    glRotatef( rotateX, 1.0, 0.0, 0.0 );
    glRotatef( rotateY, 0.0, 1.0, 0.0 );

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  
    drawFlag(-widthFlag/2, 0, 0);

    glFlush();
    glutSwapBuffers();
  glutPostRedisplay();
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

}

static int redisplay_interval;

void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(redisplay_interval, timer, 0);
}

void setFPS(int fps)
{
    redisplay_interval = 1000 / fps;
    glutTimerFunc(redisplay_interval, timer, 0);
}

int main(int argc, char** argv) {
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Cube");
    glutInitWindowSize(640, 480);   
    setFPS(30);

    glutDisplayFunc(display);
    glutMouseFunc(mouseClick);
    glutSpecialFunc(specialKeys);
    
    glutMainLoop();
    
    return 0;
}
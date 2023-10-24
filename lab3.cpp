#include <GL/glut.h>
#include <bits/stdc++.h>

//g++ lab1.cpp -o lab1 -lglut -lGLU -lGL

using namespace std;

double rotateY = 0; 
double rotateX = 0;
double scale = 1;

typedef struct {
   GLfloat x, z, y_start, y_end;
} each_pole;

std::vector<each_pole> each_pole_vector;

GLfloat cylinder_height = 1.0f,
        cylinder_radius = 0.5f,
        nr_of_points_cylinder = 360.f;



void drawCilindr(float x, float y, float z){
    
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 0.5 );
    for(auto i : each_pole_vector)
        glVertex3f(  i.x + x, 0 + y, i.z + z );      
   
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 0.5 );
    for(auto i : each_pole_vector)
        glVertex3f(  i.x + x, cylinder_height+ y, i.z + z );      
    glEnd();

    glColor3f( 0,  1.0, 0.5 );


    size_t size = each_pole_vector.size();
    glBegin(GL_POLYGON);
        glVertex3f(  each_pole_vector[size-1].x + x, 0 + y, each_pole_vector[size-1].z + z );      
        glVertex3f(  each_pole_vector[size-1].x + x, cylinder_height + y, each_pole_vector[size-1].z + z );      
        glVertex3f(  each_pole_vector[0].x + x, cylinder_height + y, each_pole_vector[0].z + z );      
        glVertex3f(  each_pole_vector[0].x + x, 0 + y, each_pole_vector[0].z + z );      
    glEnd();

    for(int i = 1; i < size; i++){

        auto f = each_pole_vector[i-1];
        auto s = each_pole_vector[i];

        glBegin(GL_POLYGON);
        glVertex3f(  f.x + x, 0 + y, f.z + z );      
        glVertex3f(  f.x + x, cylinder_height + y, f.z + z );      
        glVertex3f(  s.x + x, cylinder_height + y, s.z + z );      
        glVertex3f(  s.x + x, 0 + y, s.z + z );      
        glEnd();
    }
}



void display() {
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glScalef( scale, scale, scale );

    glRotatef( rotateX, 1.0, 0.0, 0.0 );
    glRotatef( rotateY, 0.0, 1.0, 0.0 );
  


    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    drawCilindr(0, 0, 0);

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

void makeCilindr(){
    for (int i = 0; i < nr_of_points_cylinder; ++i)
    {
        GLfloat u = i / static_cast<GLfloat>(nr_of_points_cylinder);

        each_pole pole;

        pole.x = cylinder_radius * cos(2 * M_PI * u);
        pole.z = cylinder_radius * sin(2 * M_PI * u);
        pole.y_start = 0.0f;
        pole.y_end = cylinder_height;

        each_pole_vector.push_back(pole);
    }

}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    makeCilindr();

    glutCreateWindow("Cube");
    glutInitWindowSize(640, 480);

    glutDisplayFunc(display);
    glutMouseFunc(mouseClick);
    glutSpecialFunc(specialKeys);
    
    glutMainLoop();
    
    return 0;
}
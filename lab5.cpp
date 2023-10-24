#include <GL/glut.h>
#include <bits/stdc++.h>

//g++ lab1.cpp -o lab1 -lglut -lGLU -lGL
#define PI 3.14159265 
using namespace std;

double rotateY = 0; 
double rotateX = 0;
double rotateZ = 0;
double scale = 1;

GLfloat LENGHT_LINE = 100;

GLfloat starRadius = 695.0f;
GLfloat planetRadius = 0.5f;
GLfloat planetDistance = 2.0f;

struct Planet {
  int idx;
  GLfloat radius;
  GLfloat distance;
  GLfloat angle;
  GLuint textureID;
};


vector<double> SCALE_ZOOM = {0.05, 0.001, 0,0005, 0.0001};
unordered_map<int, Planet> satellite = {
  {4, { -1, 8.0f, 2.0f, 90.0f }}
};


vector<string> texturePlanet = { "./texture/mars.bmp", "./texture/blueplanet.jpeg" };

vector<Planet> planets = {
  { 0, 2.4f, 0.387f, 0.0f },
  { 1, 6.0f, 0.723f, 90.0f },
  { 2, 6.5f, 1.0f, 180.0f },
  { 3, 3.335f, 1.52f, 180.0f },
  { 4, 70.24f, 5.2f, 180.0f },
  { 5, 60.21f, 9.54f, 180.0f },
  { 6, 25.2f, 19.2f, 180.0f },
  { 7, 24.2f, 30.0f, 180.0f },
  { 8, 2.12f, 39.0f, 180.0f }
};

void drawText(string str, int x, int y, vector<int> color){
  glColor3f(color[0]/255.0, color[1]/255.0, color[2]/255.0);
  glRasterPos2f(x, y);
  for(auto i : str){
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
  }
}

void drawTextUI(string str, int x, int y, vector<int> color){
  glColor3f(color[0]/255.0, color[1]/255.0, color[2]/255.0);
  glRasterPos2f(x, y);
  for(auto i : str){
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
  }
}

void drawStar() {

  glColor3f(1.0f, 1.0f, 0.0f);
  glutSolidSphere(starRadius, 32, 32);

}

void drawOrbit(Planet planet) {

  float verbes = 1/100;

  glColor3f(1.0f, 1.0f, 1.0f);

  int num_segments = 360;  
  glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++)   {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = planet.distance * cosf(theta);
        float y = planet.distance * sinf(theta);
        glVertex3f(x, y, 0);
  }
  glEnd();

}
void drawPlanet(Planet planet) {

  glColor3f(0.0f, 0.0f, 1.0f);

  GLfloat x = planet.distance * cos(planet.angle);
  GLfloat y = planet.distance * sin(planet.angle);

  glTranslatef(x, y, 0.0f);

  glutSolidSphere(planet.radius, 32, 32);

  if(satellite.find(planet.idx) != satellite.end()){
    satellite[planet.idx].angle += 0.01 / satellite[planet.idx].distance;
    drawPlanet(satellite[planet.idx]);  
  }

  glTranslatef(-x, -y, 0.0f);

  drawOrbit(planet);

}

void displayDebag(){
  
}

void displayAxes(){
  glColor3f(200/255.0, 30/255.0, 30/255.0);

  glBegin(GL_LINE_LOOP);
  glVertex3f(-LENGHT_LINE, 0, 0);
  glVertex3f(LENGHT_LINE, 0, 0);
  glEnd();

  glColor3f(0/255.0, 128/255.0, 0/255.0);

  glBegin(GL_LINE_LOOP);
  glVertex3f(0, -LENGHT_LINE, 0);
  glVertex3f(0, LENGHT_LINE, 0);
  glEnd();

  glColor3f(50/255.0, 50/255.0, 255/255.0);

  glBegin(GL_LINE_LOOP);
  glVertex3f(0, 0, -LENGHT_LINE);
  glVertex3f(0, 0, LENGHT_LINE);
  glEnd();


  glColor3f(1.0f, 1.0f, 1.0f);
  glutSolidSphere(0.1, 32, 32);

}

void display() {
  glEnable(GL_DEPTH_TEST);
  cout << (scale) << endl;
  glLoadIdentity();
  glScalef(scale, scale, scale);

  glRotatef(rotateX, 1.0, 0.0, 0.0);
  glRotatef(rotateY, 0.0, 1.0, 0.0);
  glRotatef(rotateZ, 0.0, 0.0, 1.0);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glShadeModel(GL_SMOOTH);
  displayDebag();
  displayAxes();
  drawStar();

  for (int i = 0; i < planets.size(); i++) {
    planets[i].angle += 1 / planets[i].distance;
    drawPlanet(planets[i]);
  }

  glFlush();
  glutSwapBuffers();
  glutPostRedisplay();
}




void mouseClick(int btn, int state, int x, int y) {
  if (state == GLUT_DOWN) {
    switch(btn) {
    case 3: 
   
      // for(auto i : SCALE_ZOOM){
      //   if(scale > i)
      //     continue;
      //   scale += 1;
      //   break;
      // }

      scale += 0.01;
      break;
    case 4:
      
      // for(auto i : SCALE_ZOOM){
      //   if(scale < i)
      //     continue;
      //   scale -= i;
      //   break;
      // }
      if(scale >= 0.01)
      scale -= 0.01;
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

    else if (key == 219)
      rotateZ -= 5;

    else if (key == 221)
      rotateZ += 5;

}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    double aspect = (double)w / h;
   
    glOrtho(-2.0 * aspect, 2.0 * aspect, -2.0, 2.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
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

void init(){
  planets[0].distance += starRadius;
  for (int i = 1; i < planets.size(); i++) {
    planets[i].distance += planets[i-1].radius + planets[i].radius + planets[i-1].distance;
    if(satellite.find(i) != satellite.end()){
      satellite[i].distance += satellite[i].radius + planets[i].radius;
    }
  }
  
}

int main(int argc, char** argv) {
    
    init();

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Cube");
    glutInitWindowSize(640, 480);   
    setFPS(30);

    glutDisplayFunc(display);
    glutMouseFunc(mouseClick);
    glutSpecialFunc(specialKeys);
    //glutReshapeFunc(reshape);

    glutMainLoop();
    
    return 0;
}
#include <stdlib.h>
#include <iostream>
#include <vector>
 #ifdef __unix__
     #include <GL/glut.h>
 #endif

 #ifdef __APPLE__
     #include "GLUT/glut.h"
 #endif

 #ifdef _WIN32
     #include <gl/glut.h>
 #endif
#include "MyVector.h"
#include "GameGrid.h"
#include "Player.h"
#include "PlayerAI.h"
#include "lighting.h"
#include "constants.h"
#include "UI.h"
#include "models.h"

int GW, GH;
//Camera variables
MyVector camera;//Camera's positon held by x, y, z,
                //the lookat held by i, j, k
MyVector newCam;
MyVector u;
MyVector v;
MyVector w;
float theta = 0.0;
float phi = 0.0; 
Player p1;
PlayerAI opponent;
int tlx, tly;
int ulx, uly;
std::vector<Button*> buttons;
bool clicked = false;
int last_time;
int last_cycle;

void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  gluLookAt(camera.getX(), camera.getY(), camera.getZ(), 
            camera.getI(), camera.getJ(), camera.getK(),
            0.0, 1.0, 0.0);
  glColor3f(0.8, 0.5, 0.3);
  float lx = tlx*2.0*GRID_SIZE - GRID_SIZE*float(GRID_WIDTH) + GRID_SIZE;
  float lz = tly*2.0*GRID_SIZE - GRID_SIZE*float(GRID_HEIGHT) + GRID_SIZE;
  setMaterial(Exp2);
  glBegin(GL_LINES);{
    glVertex3f(lx, 0.0, lz);
    glVertex3f(lx, 5.0, lz);
  }
  glEnd();
  
  //testGrid.draw();
  glPushMatrix();
  p1.draw();
  glScalef(-1.0, 1.0, -1.0);
  glTranslatef(0.0, 0.0, GRID_SIZE*(GRID_HEIGHT + 8)*2.0);
  opponent.player.draw();
  glPopMatrix();
  glPushMatrix();
  renderUI(GW, GH, GL_RENDER);
  glPopMatrix();
  
  drawMouseBox(clicked);

  glPopMatrix();
  glutSwapBuffers();
}

void reshape(int w, int h){
  GW = w;
  GH = h;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, 1.0 * w / h, 1.0, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glViewport(0, 0, w, h);
  glutPostRedisplay();
}

void init_lighting() {
  //light position
  GLfloat light_pos[4] = {1.0, 1.0, 1.5, 1.0};
  //light color (ambiant, diffuse and specular)
  GLfloat light_amb[4] = {0.6, 0.6, 0.6, 1.0};
  GLfloat light_diff[4] = {0.6, 0.6, 0.6, 1.0};
  GLfloat light_spec[4] = {0.8, 0.8, 0.8, 1.0};
  //turn on light0
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
  //set up the diffuse, ambient and specular components for the light
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diff);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_spec);
  //specify our lighting model as 1 normal per face
  glShadeModel(GL_FLAT);

  glEnable(GL_NORMALIZE);
}

void update(int param){
  int this_time = glutGet(GLUT_ELAPSED_TIME);
  int dt = this_time - last_time;
  //fps = 1000.00/dt; 
  last_time = this_time;
  last_cycle += dt;
  if(CYCLE_TIME < last_cycle){
    p1.calcResources();
    opponent.player.calcResources();
    std::cout << "INCOME! " << p1.getIncome() << std::endl;
    last_cycle -= CYCLE_TIME;
  }
  p1.update(dt);
  opponent.update(dt);
  glutPostRedisplay();
  glutTimerFunc(10, update, 0);
}

void keyboard(unsigned char key, int x, int y){
  switch(key){
    case 'w': case 'W':
      camera.setVector(camera.getI() + GRID_SIZE*2.0*w.getI(),
                       camera.getJ() + GRID_SIZE*2.0*w.getJ(),
                       camera.getK() + GRID_SIZE*2.0*w.getK());
      camera.setPosition(camera.getX() + GRID_SIZE*2.0*w.getI(),
                         camera.getY() + GRID_SIZE*2.0*w.getJ(),
                         camera.getZ() + GRID_SIZE*2.0*w.getK());
      break;
    case 'a': case 'A':
      camera.setVector(camera.getI() + GRID_SIZE*2.0*u.getI(),
                       camera.getJ() + GRID_SIZE*2.0*u.getJ(),
                       camera.getK() + GRID_SIZE*2.0*u.getK());
      camera.setPosition(camera.getX() + GRID_SIZE*2.0*u.getI(),
                         camera.getY() + GRID_SIZE*2.0*u.getJ(),
                         camera.getZ() + GRID_SIZE*2.0*u.getK());
      break;
    case 's': case 'S':
      camera.setVector(camera.getI() - GRID_SIZE*2.0*w.getI(),
                       camera.getJ() - GRID_SIZE*2.0*w.getJ(),
                       camera.getK() - GRID_SIZE*2.0*w.getK());
      camera.setPosition(camera.getX() - GRID_SIZE*2.0*w.getI(),
                         camera.getY() - GRID_SIZE*2.0*w.getJ(),
                         camera.getZ() - GRID_SIZE*2.0*w.getK());
      break;
    case 'd': case 'D':
      camera.setVector(camera.getI() - GRID_SIZE*2.0*u.getI(),
                       camera.getJ() - GRID_SIZE*2.0*u.getJ(),
                       camera.getK() - GRID_SIZE*2.0*u.getK());
      camera.setPosition(camera.getX() - GRID_SIZE*2.0*u.getI(),
                         camera.getY() - GRID_SIZE*2.0*u.getJ(),
                         camera.getZ() - GRID_SIZE*2.0*u.getK());
      break;
    case 't': case 'T':
      /*if(testGrid.setTower(tlx, tly)){
        towers.push_back(g_elem(tlx, tly));
      }*/
      p1.placeTower(tlx, tly, 16);
      //std::cout << towers.size() << std::endl;
      break;
    case 'r': case 'R':
      //testGrid.removeTower(tlx, tly, towers);
      p1.destroyTower(tlx, tly);
      break;
    case 'u': case 'U':
	   p1.spawnUnit( 0);
	   break;
  }
}
void specKeys(int key, int x, int y){
  switch(key){
    case GLUT_KEY_DOWN:
    //  ++tly;
       ++uly;
      break;
    case GLUT_KEY_UP:
    //  --tly;
        --uly;
      break;
    case GLUT_KEY_RIGHT:
    //  ++tlx;
        ++ulx;
      break;
    case GLUT_KEY_LEFT:
     // --tlx;
        --ulx;
      break;
  }
}

int main(int argc, char** argv){
  //Initialize globals
  camera.setPosition(0.0, 10.0, 10.0);
  camera.setVector(0.0, 0.0, 0.0);
  newCam = camera;
  u.setVector(-1.0, 0.0, 0.0);
  v.setVector(0.0, 1.0, 0.0);
  w.setVector(0.0, 0.0, -1.0);
  p1.setOpponent(&(opponent.player));
  tlx = 0;
  tly = 0;
  ulx = 0;   
  uly = 0;
  //Initialize window
  GW = 800;
  GH = 600;
  
    /* initialize buttons */
  GLfloat col[] = {1.0,1.0,1.0};
  for (int i = 0; i < 18; i++) {
	Button * newBtn = new Button(i, col, NULL);
    buttons.push_back(newBtn);
  }
  
  buttons.at(17)->setObject(new BasicTower(float(-0.5)*GRID_SIZE*2.0 + GRID_SIZE, 0.25, 
     float(-0.5)*GRID_SIZE*2.0 + GRID_SIZE, 0, 0));
  buttons.at(16)->setObject(new FreezeTower(float(-0.5)*GRID_SIZE*2.0 + GRID_SIZE, 0.25, 
     float(-0.5)*GRID_SIZE*2.0 + GRID_SIZE, 0, 0));
  buttons.at(15)->setObject(new FastTower(float(-0.5)*GRID_SIZE*2.0 + GRID_SIZE, 0.25, 
     float(-0.5)*GRID_SIZE*2.0 + GRID_SIZE, 0, 0));
  buttons.at(14)->setObject(new SlowTower(float(-0.5)*GRID_SIZE*2.0 + GRID_SIZE, 0.25, 
     float(-0.5)*GRID_SIZE*2.0 + GRID_SIZE, 0, 0));
  buttons.at(13)->setObject(new TrapTower(float(-0.5)*GRID_SIZE*2.0 + GRID_SIZE, 0.25, 
     float(-0.5)*GRID_SIZE*2.0 + GRID_SIZE, 0, 0));
  buttons.at(12)->setObject(new WallTower(float(-0.5)*GRID_SIZE*2.0 + GRID_SIZE, 0.25, 
     float(-0.5)*GRID_SIZE*2.0 + GRID_SIZE, 0, 0));
  
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(GW, GH);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("<Sweet>");
  glClearColor(1.0, 1.0, 1.0, 1.0);

  //Register GLUT callbacks
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(specKeys);
  glutMouseFunc(mouseClick);
  glutPassiveMotionFunc(mouseMotion);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  init_lighting();
  composeDisplayLists();
  glutTimerFunc(1000/60, update, 0);
  initializeUI();
  glutMainLoop();
}

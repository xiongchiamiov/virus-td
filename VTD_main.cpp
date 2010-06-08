#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map> 
#include <time.h>
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
#include "Camera.h"
#include "GameGrid.h"
#include "Player.h"
#include "PlayerAI.h"
#include "lighting.h"
#include "constants.h"
#include "UI.h"
#include "models.h"
#include "Scenery.h"
#include "Projectile.h"
#if VTD_SOUNDS
#include "GameSounds.h"
#endif

const int PLAYER_WIN = 0;
const int COMPUTER_WIN = 1;

int GW, GH;
//Camera variables
MyVector camera;//Camera's positon held by x, y, z,
                //the lookat held by i, j, k
Camera cam;
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
bool paused = false;
bool gameOver = false;
bool exitting = false;
bool starting = true;
int winner = 0;
GLuint winTexture;
Scenery scene("scenery.grid", &p1);
GameSounds sound; 

void drawBlueScreen(void);
void drawWinScreen(void);

void place_lights()
{
	GLfloat light_pos2[4] = {0.25, 3.0, 0.25, 1.0};
	glLightfv(GL_LIGHT1, GL_POSITION, light_pos2);

	GLfloat light_pos3[4] = {12.25, 3.0, 0.25, 1.0};
	glLightfv(GL_LIGHT2, GL_POSITION, light_pos3);
}

void display(){
  if(exitting) {
    exit(0);
    return;
  }
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClearColor(0.0f,0.0f,0.0f,0.0f);	// Black Background
  glPushMatrix();
  gluLookAt(cam.getCamX(), cam.getCamY(), cam.getCamZ(),
    cam.getLookAtX(), cam.getLookAtY(), cam.getLookAtZ(),
    0.0, 1.0, 0.0);

  place_lights();
  if(!gameOver)
  {
    glPushMatrix();
    p1.draw(placingTower); // GL_RENDER for normal, GL_SELECT for picking.
    opponent.player.draw(false);
    //drawProjectiles();
    glPopMatrix();

    vfc::extractPlanes();
    glColor3f(0.8, 0.5, 0.3);
    float lx = tlx*2.0*GRID_SIZE - GRID_SIZE*float(GRID_WIDTH) + GRID_SIZE + (GRID_SIZE * 2);
    float lz = tly*2.0*GRID_SIZE - GRID_SIZE*float(GRID_HEIGHT) + GRID_SIZE + (GRID_SIZE * 2);
    if(placingTower){
      setMaterial(Exp);
      glNormal3f(0.0, 1.0, 0.0);
      glBegin(GL_POLYGON);{
        glVertex3f(worldX - GRID_SIZE*2.0, 0.001, worldZ - GRID_SIZE*2.0);
        glVertex3f(worldX - GRID_SIZE*2.0, 0.001, worldZ + GRID_SIZE*2.0);
        glVertex3f(worldX + GRID_SIZE*2.0, 0.001, worldZ + GRID_SIZE*2.0);
        glVertex3f(worldX + GRID_SIZE*2.0, 0.001, worldZ - GRID_SIZE*2.0);
      }glEnd();
    }
    if(towerSelected){
      setMaterial(Exp);
      glNormal3f(0.0, 1.0, 0.0);
      glBegin(GL_POLYGON);{
        glVertex3f(towerSelect->getX() - GRID_SIZE*2.0 + P1_POSX, 0.001, towerSelect->getZ() - GRID_SIZE*2.0 + P1_POSZ);
        glVertex3f(towerSelect->getX() - GRID_SIZE*2.0 + P1_POSX, 0.001, towerSelect->getZ() + GRID_SIZE*2.0 + P1_POSZ);
        glVertex3f(towerSelect->getX() + GRID_SIZE*2.0 + P1_POSX, 0.001, towerSelect->getZ() + GRID_SIZE*2.0 + P1_POSZ);
        glVertex3f(towerSelect->getX() + GRID_SIZE*2.0 + P1_POSX, 0.001, towerSelect->getZ() - GRID_SIZE*2.0 + P1_POSZ);
      }glEnd();
    }


    // draw root directories
    glPushMatrix();
    glTranslatef(0.0, 2 * GRID_SIZE, 1.0 * GRID_HEIGHT * GRID_SIZE + (GRID_SIZE * 8));

    glPushMatrix(); 
    glScalef(0.25, 0.25, 0.25);
    glCallList(vtd_dl::rootDL);
    glPopMatrix();

    glTranslatef(GRID_WIDTH * GRID_SIZE * 3, 0.0, 0.0);

    glPushMatrix(); 
    glScalef(0.25, 0.25, 0.25);
    glCallList(vtd_dl::rootDL);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    scene.draw();
    glPopMatrix();
    if(!starting){
      glPushMatrix();
      renderUI(GW, GH,&p1,&opponent.player,((CYCLE_TIME-last_cycle)/1000.0), GL_RENDER);
      glPopMatrix();
    }

    drawMouseBox(clicked);
  }
  else
  {
    if(winner == COMPUTER_WIN)
      drawBlueScreen();
    else
      drawWinScreen();
  }

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
  GLfloat light_pos[4] = {0.0, 0.0, 0.0, 1.0};
  //light color (ambiant, diffuse and specular)
  GLfloat light_amb[4] = {0.3, 0.3, 0.3, 1.0};
  GLfloat light_diff[4] = {0.3, 0.3, 0.3, 1.0};
  GLfloat light_spec[4] = {0.0, 0.0, 0.0, 1.0};
  //turn on light0
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
  //set up the diffuse, ambient and specular components for the light
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diff);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_spec);

  const GLfloat light_atten = 0.3f;
  //light position
  GLfloat light_pos2[4] = {0.25, 2.0, 0.25, 1.0};
  //light color (ambiant, diffuse and specular)
  GLfloat light_amb2[4] = {0.0, 0.0, 0.0, 1.0};
  GLfloat light_diff2[4] = {0.0, 0.0, 0.4, 1.0};
  GLfloat light_spec2[4] = {0.0, 0.0, 0.8, 1.0};
  //turn on light0
  glEnable(GL_LIGHT1);
  glLightfv(GL_LIGHT1, GL_POSITION, light_pos2);
  //set up the diffuse, ambient and specular components for the light
  glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diff2);
  glLightfv(GL_LIGHT1, GL_AMBIENT, light_amb2);
  glLightfv(GL_LIGHT1, GL_SPECULAR, light_spec2);
  glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, light_atten);

  //light position
  GLfloat light_pos3[4] = {12.25, 2.0, 0.25, 1.0};
  //light color (ambiant, diffuse and specular)
  GLfloat light_amb3[4] = {0.0, 0.0, 0.0, 1.0};
  GLfloat light_diff3[4] = {0.4, 0.0, 0.0, 1.0};
  GLfloat light_spec3[4] = {0.8, 0.0, 0.0, 1.0};
  //turn on light0
  glEnable(GL_LIGHT2);
  glLightfv(GL_LIGHT2, GL_POSITION, light_pos3);
  //set up the diffuse, ambient and specular components for the light
  glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diff3);
  glLightfv(GL_LIGHT2, GL_AMBIENT, light_amb3);
  glLightfv(GL_LIGHT2, GL_SPECULAR, light_spec3);
  glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, light_atten);


  //specify our lighting model as 1 normal per face
  glShadeModel(SHADING_MODE);
  glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1.0f);

  glEnable(GL_NORMALIZE);
}

void drawBitmapString(float x, float y, void *font,char *string) {
  glPushMatrix();
  char *c;
  glRasterPos3f(x, y, 0.1);
  for (c=string; *c != '\0'; c++) {
	  if(*c == '\n') {
		  y += 18;
		  glRasterPos3f(x, y, 0.1);
	  }
	  else
		  glutBitmapCharacter(font, *c);
  }
  glPopMatrix();
}

void drawBlueScreen()
{
	//Switch to Ortho
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, GW, 0, GH, -5, 5);
	glScalef(1, -1, 1);
	glTranslatef(0, -GH, 0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	
	//Draw blue screen
	glDisable(GL_LIGHTING);
	glColor3f(0.0f,0.0f,1.0f);
	glBegin(GL_QUADS);
    glVertex2f(0,0);
    glVertex2f(GW,0);
    glVertex2f(GW,GH);
    glVertex2f(0,GH);
    glEnd();
	glTranslatef(0.0f,0.0f,0.1);
	int center_x = GW/2.0;
	int center_y = GH/2.0;
	char *title = "GAME OVER";
	char *info = "An exception 06 has occured at 0028:C11B3ADC in VxD DiskTSD(03) +\n00001660.   This was called from 0028:C11B40CB in VxD voltrack(04) +\n00000000.   System is unable to continue running.";
	char *instr = "*   Press any key to attempt to continue.\n*   Press CTRL+ALT+RESET to restart your computer.  You will\n    lose any unsaved information in all applications.";
	char *lose = "Your root folder has been corrupted. You have lost";
	char *todo = "Press SPACE key to exit";
	const int title_W = getBitmapStringWidth(GLUT_BITMAP_9_BY_15,title);;
	const int title_Y = -128;
	const int info_W = getBitmapStringWidth(GLUT_BITMAP_9_BY_15,info);
	const int info_Y = -80;
	const int instr_W = getBitmapStringWidth(GLUT_BITMAP_9_BY_15,instr);
	const int instr_Y = 0;
	const int lose_W = getBitmapStringWidth(GLUT_BITMAP_9_BY_15,lose);
	const int lose_Y = 80;
	const int todo_W = getBitmapStringWidth(GLUT_BITMAP_9_BY_15,todo);
	const int todo_Y = 120;
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_QUADS);
    glVertex2f(center_x - title_W/2 - 10,center_y + title_Y-15);
    glVertex2f(center_x + title_W/2 + 10,center_y + title_Y-15);
    glVertex2f(center_x + title_W/2 + 10,center_y + title_Y+5);
    glVertex2f(center_x - title_W/2 - 10,center_y + title_Y+5);
    glEnd();
	glColor3f(0.0f,0.0f,1.0f);
	drawBitmapString(center_x - title_W/2,center_y + title_Y,GLUT_BITMAP_9_BY_15,title);
	glColor3f(1.0f,1.0f,1.0f);
	drawBitmapString(center_x - info_W/2,center_y + info_Y,GLUT_BITMAP_9_BY_15,info);
	drawBitmapString(center_x - instr_W/2,center_y + instr_Y,GLUT_BITMAP_9_BY_15,instr);
	drawBitmapString(center_x - lose_W/2,center_y + lose_Y,GLUT_BITMAP_9_BY_15,lose);
	drawBitmapString(center_x - todo_W/2,center_y + todo_Y,GLUT_BITMAP_9_BY_15,todo);

	glEnable(GL_LIGHTING);

	//Switch back to perspective
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void drawWinScreen()
{
	//Switch to Ortho
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, GW, 0, GH, -5, 5);
	glScalef(1, -1, 1);
	glTranslatef(0, -GH, 0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, winTexture);

	glDisable(GL_LIGHTING);
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0,1.0);
    glVertex2f(0,0);
	glTexCoord2f(0.0,0.0);
    glVertex2f(0,GH);
	glTexCoord2f(1.0,0.0);
    glVertex2f(GW,GH);
	glTexCoord2f(1.0,1.0);
    glVertex2f(GW,0);
    glEnd();

	glEnable(GL_LIGHTING);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	//Switch back to perspective
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void update(int param){
	if(exitting) {
		exit(0);
		return;
	}
  int this_time = glutGet(GLUT_ELAPSED_TIME);
  int dt = this_time - last_time;
  //fps = 1000.00/dt; 
  last_time = this_time;
  if(!paused && !starting) {
    last_cycle += dt;
  }
  if(controls::keyMap[controls::BACKWARD]){
    cam.moveBackward();
  }
  if(controls::keyMap[controls::FOREWARD]){
    cam.moveForward();
  }
  if(controls::keyMap[controls::RIGHT]){
    cam.moveRight();
  }
  if(controls::keyMap[controls::LEFT]){
    cam.moveLeft();
  }
  if(controls::keyMap[controls::ZOOM_IN]){
    cam.zoomIn();
  }
  if(controls::keyMap[controls::ZOOM_OUT]){
    cam.zoomOut();
  }

  if(!paused && !starting){
    if(CYCLE_TIME < last_cycle){
      p1.calcResources();
      opponent.player.calcResources();
      std::cout << "INCOME! " << p1.getIncome() << std::endl;
      last_cycle -= CYCLE_TIME;
    }
    p1.update(dt);
    opponent.update(dt);
    sound.checkForEnd();

    if(p1.getLives() <= 0) {
      paused = true;
      gameOver = true;
      winner = COMPUTER_WIN;
    }
    if(opponent.player.getLives() <= 0) {
      paused = true;
      gameOver = true;
      winner = PLAYER_WIN;
    }
  }
  glutPostRedisplay();
  glutTimerFunc(10, update, 0);
  
}

void keyboard(unsigned char key, int x, int y){
	if(gameOver) {
		if(key == 32) {    
      p1.reset();
      opponent.reset();
      resetUI();
      gameOver = false;
      paused = false;
      starting = true;
		}
	}
	else
	{
  switch(key){
    case 'l': case 'L':
      for(int i = 0; i < GRID_WIDTH; i+=2){
        p1.placeTower(i, GRID_HEIGHT/2, 12);
      }
      break;
    case 't': case 'T':
      p1.placeTower(tlx, tly, 16);
      break;
    case 'r': case 'R':
      p1.destroyTower(tlx, tly);
      break;
    case 'p': case 'P':
		if(!gameOver)
			paused = !paused;
      break;
    case 'k': case 'K':
      p1.reset();
      opponent.reset();
	    resetUI();
      gameOver = false;
      paused = false;
      starting = true;
      break;
    case 'm': case 'M':
      sound.toggleMusic();
      break;
	case 27:
		exitting = true;
		exit(0);
		break;
  case 32:
    starting = false;
    break;
  }
  controls::keyMap[key] = true;
	}
}

void keyboardUp(unsigned char key, int x, int y){
	if(exitting) {
		exit(0);
		return;
	}
  controls::keyMap[key] = false;
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
  //srand(time(NULL));
  camera.setPosition(0.0, 10.0, 10.0);
  camera.setVector(0.0, 0.0, 0.0);
  newCam = camera;
  u.setVector(-1.0, 0.0, 0.0);
  v.setVector(0.0, 1.0, 0.0);
  w.setVector(0.0, 0.0, -1.0);
  p1.setOpponent(&(opponent.player));
  p1.setPosition(P1_POSX, P1_POSY, P1_POSZ);
  opponent.player.setPosition(OPP_POSX2, OPP_POSY2, OPP_POSZ2);

  cam.setListenerPos();
  sound.toggleMusic();

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
  
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(GW, GH);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Crash & Burn");
  glClearColor(1.0, 1.0, 1.0, 1.0);

  //Register GLUT callbacks
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutKeyboardUpFunc(keyboardUp);
  glutSpecialFunc(specKeys);
  glutMouseFunc(mouseClick);
  glutPassiveMotionFunc(mouseMotion);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  init_lighting();
  composeDisplayLists();
  glutTimerFunc(1000/60, update, 0);

  initializeParticleTextures();
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

  initializeUI();
  winTexture = LoadTexture("Win.bmp");
  p1.pGrid.initialize(false);
  opponent.player.pGrid.initialize(true);
  scene.initialize();

  glutMainLoop();
}


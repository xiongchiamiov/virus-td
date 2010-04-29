#include "BasicTower.h"
#include "constants.h"

namespace b_tower{
  const int MAX_HP = 10;
  const int ATK = 3;
  const float RANGE = 3.0;
  const int BUILD_TIME = 3000;
}
using namespace b_tower;

BasicTower::BasicTower(float inx, float iny, float inz, int gx, int gy):
Tower(inx, iny, inz, gx, gy)/*, hp(MAX_HP), max_hp(MAX_HP), atk_dmg(ATK),
type(T_BASIC), build_time(BUILD_TIME), stage(0)*/
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  atk_dmg = ATK;
  type = T_BASIC;
  build_time = BUILD_TIME;
  stage = 0;
}

BasicTower::~BasicTower(void)
{
}

void BasicTower::draw(){
  glPushMatrix();
  glTranslatef(x, y, z);
  //Front
  glNormal3f(0.0, 0.0, -1.0);
  glBegin(GL_POLYGON);{
    glVertex3f(-GRID_SIZE*2.0, 0.0, -GRID_SIZE*2.0);
    glVertex3f(-GRID_SIZE*2.0, GRID_SIZE*2.0, -GRID_SIZE*2.0);
    glVertex3f(GRID_SIZE*2.0, GRID_SIZE*2.0, -GRID_SIZE*2.0);
    glVertex3f(GRID_SIZE*2.0, 0.0, -GRID_SIZE*2.0);
  }
  glEnd();
  //Back
  glNormal3f(0.0, 0.0, 1.0);
  glBegin(GL_POLYGON);{
    glVertex3f(-GRID_SIZE*2.0, 0.0, GRID_SIZE*2.0);
    glVertex3f(-GRID_SIZE*2.0, GRID_SIZE*2.0, GRID_SIZE*2.0);
    glVertex3f(GRID_SIZE*2.0, GRID_SIZE*2.0, GRID_SIZE*2.0);
    glVertex3f(GRID_SIZE*2.0, 0.0, GRID_SIZE*2.0);
  }
  glEnd();
  //Left
  glNormal3f(-1.0, 0.0, 0.0);
  glBegin(GL_POLYGON);{
    glVertex3f(-GRID_SIZE*2.0, 0.0, -GRID_SIZE*2.0);
    glVertex3f(-GRID_SIZE*2.0, GRID_SIZE*2.0, -GRID_SIZE*2.0);
    glVertex3f(-GRID_SIZE*2.0, GRID_SIZE*2.0, GRID_SIZE*2.0);
    glVertex3f(-GRID_SIZE*2.0, 0.0, GRID_SIZE*2.0);
  }
  glEnd();
  //Right
  glNormal3f(1.0, 0.0, 0.0);
  glBegin(GL_POLYGON);{
    glVertex3f(GRID_SIZE*2.0, 0.0, -GRID_SIZE*2.0);
    glVertex3f(GRID_SIZE*2.0, GRID_SIZE*2.0, -GRID_SIZE*2.0);
    glVertex3f(GRID_SIZE*2.0, GRID_SIZE*2.0, GRID_SIZE*2.0);
    glVertex3f(GRID_SIZE*2.0, 0.0, GRID_SIZE*2.0);
  }
  glEnd();
  //Center
  glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, GRID_SIZE*2.0, 0.0);
  glEnd();
  glPopMatrix();
}

void BasicTower::step(float dt){

}

void BasicTower::shoot(){
}
#include "BasicTower.h"
#include "constants.h"
#include "lighting.h"

namespace b_tower{
  const int MAX_UPGRADES = 3;
  const int MAX_HP[MAX_UPGRADES] = {10, 20, 30};
  const int ATK[MAX_UPGRADES] = {3};
  const float RANGE[MAX_UPGRADES] = {3.0};
  const int BUILD_TIME = 3000;
}
using namespace b_tower;

BasicTower::BasicTower(float inx, float iny, float inz, int gx, int gy):
Tower(inx, iny, inz, gx, gy)
{
  hp = MAX_HP[0];
  max_hp = MAX_HP[0];
  ai.atk_dmg = ATK[0];
  ai.range = RANGE[0];
  type = T_BASIC;
  build_time = BUILD_TIME;
  stage = 0;
}

BasicTower::~BasicTower(void)
{
}

void BasicTower::draw(){
  glPushMatrix();
  setMaterial(RedFlat);
  if(ai.hasTarget){
    glBegin(GL_LINES);
      glVertex3f(x, GRID_SIZE*2.0, z);
      glVertex3f(ai.target->getX(), ai.target->getY(), ai.target->getZ());
    glEnd();
  }
  setMaterial(Exp);
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

#include "WallTower.h"
#include "constants.h"
#include "lighting.h"
#include "models.h"

namespace w_tower{
  const int MAX_UPGRADES = 3;
  const int MAX_HP[MAX_UPGRADES] = {30, 50, 70};
  const int ATK[MAX_UPGRADES] = {0, 0, 0};
  const int ATK_DT[MAX_UPGRADES] = {1000, 1000, 1000}; //Milleseconds between attacks
  const float RANGE[MAX_UPGRADES] = {0.0, 0.0, 0.0};
  const int BUILD_TIME = 3000;
}
using namespace w_tower;

WallTower::WallTower(float inx, float iny, float inz, int gx, int gy):
Tower(inx, iny, inz, gx, gy)
{
  hp = MAX_HP[0];
  max_hp = MAX_HP[0];
  ai.atk_dmg = ATK[0];
  ai.atk_dt = ATK[0]; 
  ai.range = RANGE[0];
  type = T_BASIC;
  build_time = BUILD_TIME;
  stage = 0;
}

WallTower::~WallTower(void)
{
}

void WallTower::draw(){
  glPushMatrix();
  setMaterial(Yellow);
  if(ai.hasTarget){
    glBegin(GL_LINES);
      glVertex3f(x, GRID_SIZE*2.0, z);
      glVertex3f(ai.target->getX(), ai.target->getY(), ai.target->getZ());
    glEnd();
  }
  glTranslatef(x, y, z);
     glPushMatrix();
        // Scale and orient model to fit grid
        glTranslatef(0.5, 1.25, 0.0);
        // Mini Tower Defense TBQH
        glScaled(0.05, 0.05, 0.05);
      //  glRotated(83, 0.0, 1.0, 0.0);
        glCallList(vtd_dl::shieldDL);
     glPopMatrix();
  glPopMatrix();
}

void WallTower::step(float dt){

}

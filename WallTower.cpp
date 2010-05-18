#include "WallTower.h"
#include "constants.h"
#include "lighting.h"
#include "models.h"

namespace w_tower{
  const int MAX_HP = 20;
  const int ATK = 0;
  const float RANGE = 0;
  const int BUILD_TIME = 1000;
}
using namespace w_tower;

WallTower::WallTower(float inx, float iny, float inz, int gx, int gy):
Tower(inx, iny, inz, gx, gy)/*, hp(MAX_HP), max_hp(MAX_HP), atk_dmg(ATK),
type(T_BASIC), build_time(BUILD_TIME), stage(0)*/
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  ai.atk_dmg = ATK;
  ai.range = RANGE;
  type = T_WALL;
  build_time = BUILD_TIME;
  stage = 0;
}

WallTower::~WallTower(void)
{
}

void WallTower::draw(){
  glPushMatrix();
  setMaterial(RedFlat);
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

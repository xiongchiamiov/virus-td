#include "FreezeTower.h"
#include "constants.h"
#include "models.h"

namespace f_tower{
  const int MAX_HP = 8;
  const int ATK = 2;
  const float RANGE = 3.0;
  const int BUILD_TIME = 4000;
}

using namespace f_tower;

FreezeTower::FreezeTower(float inx, float iny, float inz, int gx, int gy):
   Tower(inx, iny, inz, gx, gy)/*, hp(MAX_HP), max_hp(MAX_HP), atk_dmg(ATK),
type(T_BASIC), build_time(BUILD_TIME), stage(0)*/
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  ai.atk_dmg = ATK;
  ai.range = RANGE;
  type = T_FREEZE;
  build_time = BUILD_TIME;
  stage = 0;
}

FreezeTower::~FreezeTower(void)
{
}

void FreezeTower::draw(){
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
        glTranslatef(0.0, 0.4, 0.0);
        // Mini Tower Defense TBQH
        glScaled(0.035, 0.035, 0.035);
        //drawCPUFan();
        glCallList(vtd_dl::fanDL);
     glPopMatrix();
  glPopMatrix();
}

void FreezeTower::step(float dt){

}

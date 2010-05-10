#include "SlowTower.h"
#include "constants.h"
#include "models.h"

namespace sl_tower{
  const int MAX_HP = 12;
  const int ATK = 6;
  const float RANGE = 5.0;
  const int BUILD_TIME = 5500;
}

using namespace sl_tower;

SlowTower::SlowTower(float inx, float iny, float inz, int gx, int gy):
   Tower(inx, iny, inz, gx, gy)/*, hp(MAX_HP), max_hp(MAX_HP), atk_dmg(ATK),
type(T_BASIC), build_time(BUILD_TIME), stage(0)*/
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  ai.atk_dmg = ATK;
  ai.range = RANGE;
  type = T_SLOW;
  build_time = BUILD_TIME;
  stage = 0;
}

SlowTower::~SlowTower(void)
{
}

void SlowTower::draw(){
  glPushMatrix();
  setMaterial(RedFlat);
  if(ai.hasTarget){
    glBegin(GL_LINES);
      glVertex3f(x, GRID_SIZE*2.0, z);
      glVertex3f(ai.target->getX(), ai.target->getY(), ai.target->getZ());
    glEnd();
  }
  setMaterial(GreenShiny);
  glTranslatef(x, y, z);
     glPushMatrix();
        // Scale and orient model to fit grid
        glTranslatef(0.0, 1.25, 0.0);
        // Mini Tower Defense TBQH
        glScaled(0.06, 0.08, 0.06);
        glRotated(83, 0.0, 1.0, 0.0);
        //drawTeslaCoil();
        glCallList(vtd_dl::teslaDL);
     glPopMatrix();
  glPopMatrix();
}

void SlowTower::step(float dt){

}

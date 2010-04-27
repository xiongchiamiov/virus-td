#include "FreezeTower.h"
#include "constants.h"

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
  atk_dmg = ATK;
  type = T_BASIC;
  build_time = BUILD_TIME;
  stage = 0;
}

FreezeTower::~FreezeTower(void)
{
}

void FreezeTower::draw(){
  glPushMatrix();
  setMaterial(Purple);
  glTranslatef(x, y, z);
   glutSolidSphere(0.25, 10, 10);
  glPopMatrix();
}

void FreezeTower::step(float dt){

}

void FreezeTower::shoot(){
}
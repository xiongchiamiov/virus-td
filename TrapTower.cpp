#include "TrapTower.h"
#include "constants.h"

namespace tr_tower{
  const int MAX_HP = 8;
  const int ATK = 2;
  const float RANGE = 3.0;
  const int BUILD_TIME = 4000;
}

using namespace tr_tower;

TrapTower::TrapTower(float inx, float iny, float inz, int gx, int gy):
   Tower(inx, iny, inz, gx, gy)/*, hp(MAX_HP), max_hp(MAX_HP), atk_dmg(ATK),
type(T_BASIC), build_time(BUILD_TIME), stage(0)*/
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  atk_dmg = ATK;
  type = T_TRAP;
  build_time = BUILD_TIME;
  stage = 0;
}

TrapTower::~TrapTower(void)
{
}

void TrapTower::draw(){
  glPushMatrix();
  setMaterial(Exp);
  glTranslatef(x, y, z);
   glutSolidTorus(0.2, 0.25, 10, 10);
  glPopMatrix();
}

void TrapTower::step(float dt){

}

void TrapTower::shoot(){
}

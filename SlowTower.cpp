#include "SlowTower.h"
#include "constants.h"

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
  ai.range = BUILD_TIME;
  type = T_SLOW;
  build_time = BUILD_TIME;
  stage = 0;
}

SlowTower::~SlowTower(void)
{
}

void SlowTower::draw(){
  glPushMatrix();
  setMaterial(GreenShiny);
  glTranslatef(x, y, z);
   glutSolidCone(0.25, 0.5, 10, 10);
  glPopMatrix();
}

void SlowTower::step(float dt){

}

void SlowTower::shoot(){
}

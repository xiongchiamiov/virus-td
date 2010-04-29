#include "FastTower.h"
#include "constants.h"

namespace fs_tower{
  const int MAX_HP = 6;
  const int ATK = 1;
  const float RANGE = 5.0;
  const int BUILD_TIME = 3500;
}

using namespace fs_tower;

FastTower::FastTower(float inx, float iny, float inz, int gx, int gy):
   Tower(inx, iny, inz, gx, gy)/*, hp(MAX_HP), max_hp(MAX_HP), atk_dmg(ATK),
type(T_BASIC), build_time(BUILD_TIME), stage(0)*/
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  atk_dmg = ATK;
  type = T_FAST;
  build_time = BUILD_TIME;
  stage = 0;
}

FastTower::~FastTower(void)
{
}

void FastTower::draw(){
  glPushMatrix();
  setMaterial(FieryOrange);
  glTranslatef(x, y, z);
   glutSolidTeapot(0.25);
  glPopMatrix();
}

void FastTower::step(float dt){

}

void FastTower::shoot(){
}

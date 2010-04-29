#include "FastUnit.h"

namespace f_unit {
  const int MAX_HP = 10;
  const int ATK = 3;
  const float SPD = 0.2;
}

using namespace f_unit;

FastUnit::FastUnit(float inx, float iny, float inz, int gx, int gy) {
  hp = MAX_HP;
  max_hp = MAX_HP;
  atk_dmg = ATK;
  speed = SPD;
  type = U_BASIC;
}

FastUnit::~FastUnit(void) {

}

void FastUnit::draw() {
  glPushMatrix();
  setMaterial(RedFlat);
  glTranslatef(x, y, z);
   glutSolidTeapot(0.25);
  glPopMatrix();
}

void FastUnit::step(float dt){

}

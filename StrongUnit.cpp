#include "StrongUnit.h"
#include "constants.h"
namespace s_unit {
  const int MAX_HP = 15;
  const int ATK = 8;
  const float SPD = 0.7;
}

using namespace s_unit;

StrongUnit::StrongUnit(float inx, float iny, float inz, int gx, int gy):
      Unit(inx, iny, inz, gx, gy) {
  hp = MAX_HP;
  max_hp = MAX_HP;
  atk_dmg = ATK;
  speed = SPD;
  type = U_STRONG;
}

StrongUnit::~StrongUnit(void) {

}

unit_dir StrongUnit::move(unit_dir direction) {
	return direction;
}

void StrongUnit::draw() {
  glPushMatrix();
  glTranslatef(x, y, z);
  glutSolidSphere(.45,10,10);
  glPopMatrix();
}

void StrongUnit::step(float dt) {
	//will be changed by waypoint
	z = z + dt;
}


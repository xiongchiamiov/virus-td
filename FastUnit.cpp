#include "FastUnit.h"
#include "constants.h"
namespace f_unit {
  const int MAX_HP = 8;
  const int ATK = 2;
  const float SPD = 0.2;
}

using namespace f_unit;

FastUnit::FastUnit(float inx, float iny, float inz, int gx, int gy):
      Unit(inx, iny, inz, gx, gy) {
  hp = MAX_HP;
  max_hp = MAX_HP;
  atk_dmg = ATK;
  speed = SPD;
  type = U_FAST;
}

FastUnit::~FastUnit(void) {

}

unit_dir FastUnit::move(unit_dir direction) {
	return direction;
}

void FastUnit::draw() {
  glPushMatrix();
  glTranslatef(x, y, z);
  glutSolidSphere(.15,10,10);
  glPopMatrix();
}

void FastUnit::step(float dt) {
	//will be changed by waypoint
	z = z + dt;
}

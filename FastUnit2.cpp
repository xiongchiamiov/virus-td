#include "FastUnit2.h"
#include "constants.h"
#include "lighting.h"
#include "models.h"
#include "shadow.h"

namespace f2_unit {
  const int MAX_HP = 16;
  const int ATK = 3;
  const float SPD = 0.0032;
}

using namespace f2_unit;

FastUnit2::FastUnit2(float inx, float iny, float inz):
Unit(inx, iny, inz) 
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  atk_dmg = ATK;
  speed = SPD;
  max_speed = SPD;
  type = U_FAST;
  value = unit_bonus::FAST2;
  animateSpeed = 1.0;
}

FastUnit2::~FastUnit2(void) {

}

unit_dir FastUnit2::move(unit_dir direction) {
	return direction;
}

void FastUnit2::draw() {
  static float incr = 0.01;

  glPushMatrix();
  glTranslatef(x, y, z);

  glPushMatrix();

  glPushMatrix();
  glTranslatef(0.0,1.0,0.0);
  this->drawHealthBar();
  glPopMatrix();

  // Setup so to scale and orient with the game grid
  glScaled(0.25, 0.25, 0.25);
  glTranslatef(0, 1, 0);

  //glRotatef(-90, 0.0, 1.0, 0.0);

 drawPhish();
  glPopMatrix();
	 glPushMatrix();
//		draw_shadow(8);
	 glPopMatrix();
  glPopMatrix();
}

//void FastUnit::step(float dt) {
//	//will be changed by waypoint
//	z = z + dt;
//}

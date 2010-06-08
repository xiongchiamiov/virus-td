#include "StrongUnit2.h"
#include "constants.h"
#include "lighting.h"
#include "models.h"
#include "shadow.h"

namespace s2_unit {
  const int MAX_HP = unit_health::STRONG2;
  const int ATK = 8;
  const float SPD = unit_speed::STRONG2;
}

using namespace s2_unit;

StrongUnit2::StrongUnit2(float inx, float iny, float inz):
Unit(inx, iny, inz) 
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  atk_dmg = ATK;
  speed = SPD;
  max_speed = SPD;
  type = U_STRONG;
  value = unit_bonus::STRONG2;
}

StrongUnit2::~StrongUnit2(void) {

}

unit_dir StrongUnit2::move(unit_dir direction) {
	return direction;
}

void StrongUnit2::draw() {
  glPushMatrix();
  glTranslatef(x, y, z);
     glPushMatrix();

		glPushMatrix();
		glTranslatef(0.0,2.3,0.5);
		this->drawHealthBar();
		glPopMatrix();

        glScaled(0.15, 0.15, 0.15);
        glTranslatef(0, 10, 0);
        glCallList(vtd_dl::trojanDL);
     glPopMatrix();
	 glPushMatrix();
		draw_shadow(10);
	 glPopMatrix();
  glPopMatrix();
}

//void StrongUnit2::step(float dt) {
	//will be changed by waypoint
//	z = z + dt;
//}



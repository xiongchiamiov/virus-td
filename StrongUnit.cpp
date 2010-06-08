#include "StrongUnit.h"
#include "constants.h"
#include "lighting.h"
#include "models.h"
#include "shadow.h"

namespace s_unit {
  const int MAX_HP = unit_health::STRONG;
  const int ATK = 8;
  const float SPD = unit_speed::STRONG;
}

using namespace s_unit;

StrongUnit::StrongUnit(float inx, float iny, float inz):
Unit(inx, iny, inz) 
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  atk_dmg = ATK;
  speed = SPD;
  max_speed = SPD;
  type = U_STRONG;
  value = unit_bonus::STRONG;
  animateSpeed = 0.25;
}

StrongUnit::~StrongUnit(void) {

}

unit_dir StrongUnit::move(unit_dir direction) {
	return direction;
}

void StrongUnit::draw() {
  glPushMatrix();
  glTranslatef(x, y, z);
     glPushMatrix();
		glPushMatrix();
		glTranslatef(0.0,1.2,0.0);
		this->drawHealthBar();
		glPopMatrix();

      if (animateSpeed >= 1) {
         animateSpeed = 0.25;
      }
        glScaled(0.25, 0.25, 0.25);
        glTranslatef(0, 1, 0);
       drawForkBombDLAnimated(animateSpeed+=0.01, 2);
     //   glCallList(vtd_dl::forkbDL);
        //glCallList(vtd_dl::virusDL);
     glPopMatrix();
	 glPushMatrix();
		draw_shadow(9);
	 glPopMatrix();
  glPopMatrix();
}

//void StrongUnit::step(float dt) {
	//will be changed by waypoint
//	z = z + dt;
//}


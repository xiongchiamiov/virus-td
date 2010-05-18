#include "FastUnit.h"
#include "constants.h"
#include "lighting.h"
#include "models.h"

namespace f_unit {
  const int MAX_HP = 8;
  const int ATK = 2;
  const float SPD = 0.0025;
}

using namespace f_unit;

FastUnit::FastUnit(float inx, float iny, float inz):
Unit(inx, iny, inz) 
{
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

  glPushMatrix();
  // Setup so to scale and orient with the game grid
  glScaled(0.25, 0.25, 0.25);
  glTranslatef(0, 1, 0);
  //glRotatef(-90, 0.0, 1.0, 0.0);
  glCallList(vtd_dl::virusDL);
  //glCallList(vtd_dl::forkbDL);
  glPopMatrix();

  glPopMatrix();
}

//void FastUnit::step(float dt) {
//	//will be changed by waypoint
//	z = z + dt;
//}

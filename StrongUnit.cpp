#include "StrongUnit.h"
#include "constants.h"
#include "lighting.h"
#include "models.h"

namespace s_unit {
  const int MAX_HP = 15;
  const int ATK = 8;
  const float SPD = 0.001;
}

using namespace s_unit;

StrongUnit::StrongUnit(float inx, float iny, float inz):
Unit(inx, iny, inz) 
{
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
  glPushMatrix();
  glScaled(0.25, 0.25, 0.25);
  glTranslatef(0, 1, 0);
  glCallList(vtd_dl::forkbDL);
  //glCallList(vtd_dl::virusDL);
  glPopMatrix();
  //glutSolidSphere(.45,10,10);
  glPopMatrix();
}

//void StrongUnit::step(float dt) {
	//will be changed by waypoint
//	z = z + dt;
//}


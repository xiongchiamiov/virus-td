#include "FastUnit.h"
#include "constants.h"
#include "lighting.h"
#include "models.h"
#include "shadow.h"

namespace f_unit {
  const int MAX_HP = unit_health::FAST;
  const int ATK = 2;
  const float SPD = unit_speed::FAST;
}

using namespace f_unit;

FastUnit::FastUnit(float inx, float iny, float inz):
Unit(inx, iny, inz) 
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  atk_dmg = ATK;
  speed = SPD;
  max_speed = SPD;
  type = U_FAST;
  value = unit_bonus::FAST;
  animateSpeed = 1.0;
}

FastUnit::~FastUnit(void) {

}

unit_dir FastUnit::move(unit_dir direction) {
	return direction;
}

void FastUnit::draw() {
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
  if (animateSpeed >= 1.1) {
     incr = -0.03;
  }
  
  if (animateSpeed <= 0.7) {
     incr = 0.03;
  }

  double dist = sqrt((getX() - cam.getCamX()) * (getX() - cam.getCamX())
     + (getY() - cam.getCamY()) * (getY() - cam.getCamY())
     + (getZ() - cam.getCamZ()) * (getZ() - cam.getCamZ()));

  if (dist <= 10) {
     drawVirusDLAnimated(animateSpeed+=incr, 3);
  } else if (dist <= 11.5) {
     drawVirusDLAnimated(animateSpeed+=incr, 2);
  } else {
     drawVirusDLAnimated(animateSpeed+=incr, 1);
  }

 // glCallList(vtd_dl::virusDL);
  //glCallList(vtd_dl::forkbDL);
  glPopMatrix();
	 glPushMatrix();
		draw_shadow(8);
	 glPopMatrix();
  glPopMatrix();
}

//void FastUnit::step(float dt) {
//	//will be changed by waypoint
//	z = z + dt;
//}

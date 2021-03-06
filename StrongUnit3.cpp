#include "StrongUnit3.h"
#include "constants.h"
#include "lighting.h"
#include "models.h"
#include "shadow.h"

namespace s3_unit {
  const int MAX_HP = unit_health::STRONG3;
  const int ATK = 7;
  const float SPD = unit_speed::STRONG3;
}

using namespace s3_unit;

StrongUnit3::StrongUnit3(float inx, float iny, float inz):
Unit(inx, iny, inz) 
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  atk_dmg = ATK;
  speed = SPD;
  max_speed = SPD;
  type = U_STRONG;
  value = unit_bonus::STRONG3;
}

StrongUnit3::~StrongUnit3(void) {

}

unit_dir StrongUnit3::move(unit_dir direction) {
	return direction;
}

void StrongUnit3::draw() {
  glPushMatrix();
  glTranslatef(x, y, z);
     glPushMatrix();
		  glPushMatrix();
		    glTranslatef(0.0,1.2,0.0);
		    this->drawHealthBar();
        glPopMatrix();
        
        glScaled(0.4, 0.4, 0.4);
        glTranslatef(0, 1, 0);

  double dist = sqrt((getX() - cam.getCamX()) * (getX() - cam.getCamX())
     + (getY() - cam.getCamY()) * (getY() - cam.getCamY())
     + (getZ() - cam.getCamZ()) * (getZ() - cam.getCamZ()));

  if (dist <= 10) {
     glCallList(vtd_dl::lockL3DL);
  } else if (dist <= 11.5) {
     glCallList(vtd_dl::lockL2DL);
  } else {
     glCallList(vtd_dl::lockL1DL);
  }
  
     glPopMatrix();
     
    glPushMatrix();
      draw_shadow(5);
	 glPopMatrix();
  glPopMatrix();
}

//void StrongUnit::step(float dt) {
	//will be changed by waypoint
//	z = z + dt;
//}


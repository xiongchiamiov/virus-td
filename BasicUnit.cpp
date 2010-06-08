#include "BasicUnit.h"
#include "constants.h"
#include "lighting.h"
#include "models.h"
#include "shadow.h"

// NOTES 
//add xmin,xman,ymin,ymax,zmin,zmax to GameObject for collision detection
//add radius of object if applicable

namespace b_unit{
	const int MAX_HP = unit_health::BASIC;
	const int ATK = 3;
	const float SPD = unit_speed::BASIC;
}
using namespace b_unit;

BasicUnit::BasicUnit(float inx, float iny, float inz):
Unit(inx, iny, inz)
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  atk_dmg = ATK;
  speed = SPD;
  max_speed = SPD;
  type = U_BASIC;
  value = unit_bonus::BASIC;
  animateSpeed = 1.0;
  increment = 0.01;
}

BasicUnit::~BasicUnit(void)
{

}

void BasicUnit::draw()
{
  glPushMatrix();
  glTranslatef(x, y, z);

  glPushMatrix();

  glPushMatrix();
  glTranslatef(0.0,2.2,0.0);
  this->drawHealthBar();
  glPopMatrix();

  // Setup so to scale and orient with the game grid
  glScaled(0.1, 0.1, 0.1);
  glTranslatef(0.0, 15.0, 5.0);

  glRotatef(-90, 0.0, 1.0, 0.0);
  
  if (animateSpeed <= 0.85) {
     increment = 0.01;
  }
  
  if (animateSpeed >= 1.15) {
     increment = -0.01;
  } 
  
 // if (animateSpeed <= 0.9) {
 //    incr = 0.01;
 // }
 
  double dist = sqrt((getX() - cam.getCamX()) * (getX() - cam.getCamX())
     + (getY() - cam.getCamY()) * (getY() - cam.getCamY())
     + (getZ() - cam.getCamZ()) * (getZ() - cam.getCamZ()));

  if (dist <= 8) {
     drawWormDLAnimated(animateSpeed+=increment, 3);
  } else if (dist <= 13) {
     drawWormDLAnimated(animateSpeed+=increment, 2);
  } else {
     drawWormDLAnimated(animateSpeed+=increment, 1);
  }

//  glCallList(vtd_dl::wormDL);
  glPopMatrix();
	 glPushMatrix();
		draw_shadow(7);
	 glPopMatrix();
  glPopMatrix();
}
#include "BossUnit.h"
#include "constants.h"
#include "lighting.h"
#include "models.h"
#include "shadow.h"

// NOTES 
//add xmin,xman,ymin,ymax,zmin,zmax to GameObject for collision detection
//add radius of object if applicable

namespace boss_unit{
  const int MAX_HP = 1000;
  const int ATK = 30;
  const float SPD = 0.0017;
}
using namespace boss_unit;

BossUnit::BossUnit(float inx, float iny, float inz):
Unit(inx, iny, inz)
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  atk_dmg = ATK;
  speed = SPD;
  max_speed = SPD;
  type = U_BOSS;
  value = unit_bonus::BOSS;
  animateSpeed = 1.0;
}

BossUnit::~BossUnit(void)
{

}

void BossUnit::draw()
{
  static int incr = 1;

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

   if (animateSpeed >= 20) {
      incr = -2;
   }
   
   if (animateSpeed <= -20) {
      incr = 2;
   }
   
//  glRotatef(90, 0.0, 1.0, 0.0);
//  glCallList(vtd_dl::wormDL);
   drawBearDLAnimated(animateSpeed+=incr);
  glPopMatrix();
	 glPushMatrix();
//		draw_shadow(7);
	 glPopMatrix();
  glPopMatrix();
}

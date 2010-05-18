#include "BasicUnit.h"
#include "constants.h"
#include "lighting.h"
#include "models.h"

// NOTES 
//add xmin,xman,ymin,ymax,zmin,zmax to GameObject for collision detection
//add radius of object if applicable

namespace b_unit{
  const int MAX_HP = 10;
  const int ATK = 3;
  const float SPD = 0.0015;
}
using namespace b_unit;

BasicUnit::BasicUnit(float inx, float iny, float inz):
Unit(inx, iny, inz)
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  atk_dmg = ATK;
  speed = SPD;
  type = U_BASIC;
  value = unit_bonus::BASIC;
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
  glCallList(vtd_dl::wormDL);
  glPopMatrix();

  glPopMatrix();
}
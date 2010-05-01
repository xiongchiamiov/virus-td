#include "BasicUnit.h"
#include "constants.h"
#include "lighting.h"

// NOTES 
//add xmin,xman,ymin,ymax,zmin,zmax to GameObject for collision detection
//add radius of object if applicable

namespace b_unit{
  const int MAX_HP = 10;
  const int ATK = 3;
  const float SPD = 0.0005;
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
}

BasicUnit::~BasicUnit(void)
{

}

void BasicUnit::draw()
{
  glPushMatrix();
  setMaterial(Fuschia);
  glTranslatef(x, y, z);
  glutSolidSphere(.25,10,10);
  glPopMatrix();
}
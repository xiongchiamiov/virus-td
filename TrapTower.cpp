#include "TrapTower.h"
#include "constants.h"
#include "models.h"

namespace tr_tower{
  const int MAX_HP = 8;
  const int ATK = 2;
  const float RANGE = 3.0;
  const int BUILD_TIME = 4000;
}

using namespace tr_tower;

TrapTower::TrapTower(float inx, float iny, float inz, int gx, int gy):
   Tower(inx, iny, inz, gx, gy)/*, hp(MAX_HP), max_hp(MAX_HP), atk_dmg(ATK),
type(T_BASIC), build_time(BUILD_TIME), stage(0)*/
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  ai.atk_dmg = ATK;
  ai.range = RANGE;
  type = T_TRAP;
  build_time = BUILD_TIME;
  stage = 0;
  ai.hasTarget = false;
}

TrapTower::~TrapTower(void)
{
}

void TrapTower::draw(){
  glPushMatrix();
  setMaterial(Yellow);
  if(ai.hasTarget){
    glBegin(GL_LINES);
      glVertex3f(x, GRID_SIZE*2.0, z);
      glVertex3f(ai.target->getX(), ai.target->getY(), ai.target->getZ());
    glEnd();
  }
  setMaterial(Exp);
  glTranslatef(x, y, z);
  glPushMatrix();
   setMaterial(Black);
   glScalef(.5,.5,.5);
   glCallList(vtd_dl::blkhatDL);
   //glutSolidTorus(0.2, 0.25, 10, 10);
  glPopMatrix();
  glPopMatrix();
}

void TrapTower::step(float dt){

}

bool TrapTower::shoot(){
  bool ret = false;
  std::list<Unit*>::iterator i;
  for(i = ai.targetList->begin(); i != ai.targetList->end(); ++i){
    if(!(*i)->isDead() && ai.range > ai.getDistance(**i)){
      (*i)->takeDamage(ai.atk_dmg);
      ret = true;
    }
  }
  return true;
}

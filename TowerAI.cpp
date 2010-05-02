#include "TowerAI.h"
#include <math.h>

TowerAI::TowerAI(float inx, float iny, float inz):
x(inx), y(iny), z(inz), hasTarget(false), last_atk(0)
{
  mode = TM_FIRST;
  atk_dt = 1000;
}

TowerAI::~TowerAI(void)
{
}

bool TowerAI::shoot(){
  bool retVal;
  if(hasTarget && !target->isDead() && getDistance(*target) <= range){
    int dmg = target->takeDamage(atk_dmg); 
    if( 0 >= dmg){
      hasTarget = false;
    }
    retVal = true;
  } else {
    getNewTarget();
    retVal = false;
  }
  return retVal;
}

void TowerAI::getNewTarget(){
  std::list<Unit*>::iterator i;
  float thisDist, bestDist = range + 1.0;
  int low_hp = 2147483647, high_hp = -1;
  //std::cout << bestDist << std::endl;
  for(i = targetList->begin(); i != targetList->end(); ++i){
    if(!(*i)->isDead()){
      thisDist = getDistance(**i);
      if(mode == TM_FIRST && thisDist < bestDist){
        target = *i;
        bestDist = thisDist;
        hasTarget = bestDist < range;
      } else if(mode == TM_LOW_HP && (*i)->getHP() < low_hp && thisDist <= range){
        target = *i;
        hasTarget = true;
      } else if(mode == TM_HIGH_HP && (*i)->getHP() > high_hp && thisDist <= range){
        target = *i;
        hasTarget = true;
      }
    }
  }
}

float TowerAI::getDistance(Unit& other){
  float dx = x - other.getX();
  float dy = y - other.getY();
  float dz = z - other.getZ();
  return sqrt(dx*dx + dy*dy + dz*dz);
}
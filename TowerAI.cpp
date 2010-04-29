#include "TowerAI.h"
#include <math.h>

TowerAI::TowerAI(float inx, float iny, float inz):
x(inx), y(iny), z(inz), hasTarget(false)
{
}

TowerAI::~TowerAI(void)
{
}

void TowerAI::shoot(){
  if(hasTarget && !target->isDead() && getDistance(*target) <= range){
    if( 0 <= target->takeDamage(atk_dmg) ){
      hasTarget = false;
    }
  } else {
    getNewTarget();
  }
}



void TowerAI::getNewTarget(){
  std::list<Unit*>::iterator i;
  Unit* nTarget = NULL;
  float thisDist, bestDist = range + 1.0;
  //std::cout << bestDist << std::endl;
  for(i = targetList->begin(); i != targetList->end(); ++i){
    thisDist = getDistance(**i);
    if( thisDist < bestDist ){
      target = *i;
      bestDist = thisDist;
    }
  }
  hasTarget = bestDist < range;
}

float TowerAI::getDistance(Unit& other){
  float dx = x - other.getX();
  float dy = y - other.getY();
  float dz = z - other.getZ();
  return sqrt(dx*dx + dy*dy + dz*dz);
}
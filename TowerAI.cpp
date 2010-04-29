#include "TowerAI.h"
#include <math.h>

TowerAI::TowerAI(float inx, float iny, float inz):
x(inx), y(iny), z(inz), hasTarget(false), last_atk(0)
{
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
  Unit* nTarget = NULL;
  float thisDist, bestDist = range + 1.0;
  //std::cout << bestDist << std::endl;
  for(i = targetList->begin(); i != targetList->end(); ++i){
    if(!(*i)->isDead()){
      thisDist = getDistance(**i);
      if( thisDist < bestDist){
        target = *i;
        bestDist = thisDist;
      }
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
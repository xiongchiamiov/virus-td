#include "TowerAI.h"
#include <math.h>

TowerAI::TowerAI(float inx, float iny, float inz):
x(inx), y(iny), z(inz), hasTarget(false)
{
}

TowerAI::~TowerAI(void)
{
}

#include <iostream>
void TowerAI::shoot(){
  if(hasTarget && !target->isDead() && getDistance(*target) <= range){
    int dmg = target->takeDamage(atk_dmg); 
    if( 0 >= dmg){
      hasTarget = false;
      std::cout << "Dead" << std::endl;
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
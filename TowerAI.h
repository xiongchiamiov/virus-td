#pragma once
#include "Unit.h"
#include <list>

enum target_mode{
  TM_FIRST,
  TM_LOW_HP,
  TM_HIGH_HP
};
class TowerAI
{
public:
  TowerAI(float inx, float iny, float inz);
  ~TowerAI(void);
  inline float getX(){return x;}
  inline float getY(){return y;}
  inline float getZ(){return z;}
  void shoot();
  void getNewTarget();
  float getDistance(Unit& other);
  //Data
  int atk_dmg;   //Amount of damage
  float range;   //This tower's maximum range
  float x;
  float y;
  float z;
  Unit* target;
  std::list<Unit*> *targetList;
  bool hasTarget;
};

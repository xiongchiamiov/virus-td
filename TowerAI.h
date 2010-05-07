#pragma once
#include "Unit.h"
#include <list>

enum target_mode{
  TM_FIRST,
  TM_LOW_HP,
  TM_HIGH_HP,
  TM_FASTEST,
  TM_SLOWEST
};
class TowerAI
{
public:
  TowerAI(float inx, float iny, float inz);
  ~TowerAI(void);
  inline float getX(){return x;}
  inline float getY(){return y;}
  inline float getZ(){return z;}
  bool shoot();
  void getNewTarget();
  float getDistance(Unit& other);
  //Data
  int atk_dmg;   //Amount of damage
  int atk_dt;    //Time between attacks
  int last_atk;  //Time since last attack
  float range;   //This tower's maximum range
  float x;
  float y;
  float z;
  Unit* target;
  std::list<Unit*> *targetList;
  bool hasTarget;
  bool hasKill; 
  target_mode mode;
  inline void setMode(target_mode n_mode){ mode = n_mode;}
};

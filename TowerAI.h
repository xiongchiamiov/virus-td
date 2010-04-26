#pragma once
#include "Unit.h"

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
private:
  float x;
  float y;
  float z;
  Unit* target;
  bool hasTarget;
  float getDistance(Unit& other);
};
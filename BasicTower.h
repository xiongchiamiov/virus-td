#pragma once
#include "Tower.h"

class BasicTower :
  public Tower
{
public:
  BasicTower(float inx, float iny, float inz, int gx, int gy);
  ~BasicTower(void);
  void draw();
  void step(float dt);
  virtual void shoot();
};

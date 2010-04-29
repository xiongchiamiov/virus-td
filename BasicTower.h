#pragma once
#include "Tower.h"
#include "lighting.h"

class BasicTower :
  public Tower
{
public:
  BasicTower(float inx, float iny, float inz, int gx, int gy);
  ~BasicTower(void);
  void draw();
};

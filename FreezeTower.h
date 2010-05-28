#pragma once
#include "Tower.h"
#include "lighting.h"

class FreezeTower : public Tower {
   public:
     FreezeTower(float inx, float iny, float inz, int gx, int gy);
     ~FreezeTower(void);
     void draw();
     void step(float dt);
     bool shoot();
     bool upgrade();
};



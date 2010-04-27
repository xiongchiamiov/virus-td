#pragma once
#include "Tower.h"Slow
#include "lighting.h"

class SlowTower : public Tower {
   public:
     SlowTower(float inx, float iny, float inz, int gx, int gy);
     ~SlowTower(void);
     void draw();
     void step(float dt);
     virtual void shoot();
};



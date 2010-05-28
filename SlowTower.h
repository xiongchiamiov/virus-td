#pragma once
#include "Tower.h"
#include "lighting.h"

class SlowTower : public Tower {
   public:
     SlowTower(float inx, float iny, float inz, int gx, int gy);
     ~SlowTower(void);
     void draw();
     void step(float dt);
     bool upgrade();
};



#pragma once
#include "Tower.h"
#include "lighting.h"

class FastTower : public Tower {
   public:
      FastTower(float inx, float iny, float inz, int gx, int gy);
      ~FastTower(void);
      void draw();
      void step(float dt);
};



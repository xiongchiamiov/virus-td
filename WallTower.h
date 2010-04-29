#pragma once
#include "Tower.h"
#include "lighting.h"

class WallTower : public Tower {
   public:
      WallTower(float inx, float iny, float inz, int gx, int gy);
      ~WallTower(void);
      void draw();
      void step(float dt);
};

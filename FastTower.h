#pragma once
#include "Tower.h"
#include "lighting.h"

class FastTower : public Tower {
   public:
      FastTower(float inx, float iny, float inz, int gx, int gy);
      ~FastTower(void);
      double increment;
      void draw(GLuint id, GLenum mode);
      void step(float dt);
     bool upgrade();
};



#pragma once
#include "Tower.h"
#include "lighting.h"

class TrapTower : public Tower {
   public:
     TrapTower(float inx, float iny, float inz, int gx, int gy);
     ~TrapTower(void);
     void draw(GLuint id, GLenum mode);
     void step(float dt);
     bool shoot();
     bool upgrade();
};

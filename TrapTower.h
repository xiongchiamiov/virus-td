#pragma once
#include "Tower.h"
#include "lighting.h"
#include "Camera.h"
extern Camera cam;

class TrapTower : public Tower {
   public:
     TrapTower(float inx, float iny, float inz, int gx, int gy);
     ~TrapTower(void);
     void draw(GLuint id, GLenum mode);
     void step(float dt);
     bool shoot();
     bool upgrade();
};

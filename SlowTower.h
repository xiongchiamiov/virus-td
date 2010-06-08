#pragma once
#include "Tower.h"
#include "lighting.h"
#include "Camera.h"
extern Camera cam;

class SlowTower : public Tower {
   public:
     SlowTower(float inx, float iny, float inz, int gx, int gy);
     ~SlowTower(void);
     void draw(GLuint id, GLenum mode);
     void step(float dt);
     bool upgrade();
};



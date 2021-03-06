#pragma once
#include "Tower.h"
#include "lighting.h"
#include "Camera.h"
extern Camera cam;

class FastTower : public Tower {
   public:
      double increment;
      FastTower(float inx, float iny, float inz, int gx, int gy);
      ~FastTower(void);
      void draw(GLuint id, GLenum mode);
      void step(float dt);
     bool upgrade();
};



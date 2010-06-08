#pragma once
#include "Unit.h"
#include "Camera.h"
extern Camera cam;

class FastUnit2 : public Unit
{
   public:
   	FastUnit2(float inx, float iny, float inz);
   	~FastUnit2(void);
   	void draw();
   	void step(float dt);
      unit_dir move(unit_dir direction);
};



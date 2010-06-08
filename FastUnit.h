#pragma once
#include "Unit.h"
#include "Camera.h"
extern Camera cam;

class FastUnit : public Unit
{
   public:
   	FastUnit(float inx, float iny, float inz);
   	//BasicUnit(void);
   	~FastUnit(void);
   	void draw();
   	void step(float dt);
      unit_dir move(unit_dir direction);
};



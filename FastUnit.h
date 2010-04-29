#pragma once
#include "Unit.h"

class FastUnit : public Unit
{
   public:
   	FastUnit(float inx, float iny, float inz, int gx, int gy);
   	//BasicUnit(void);
   	~FastUnit(void);
   	void draw();
   	void step(float dt);
      unit_dir move(unit_dir direction);
};



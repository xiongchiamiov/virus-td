#pragma once
#include "Unit.h"

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



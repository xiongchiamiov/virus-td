#pragma once
#include "Unit.h"

class StrongUnit : public Unit {
   public:
   	StrongUnit(float inx, float iny, float inz);
   	//BasicUnit(void);
   	~StrongUnit(void);
   	void draw();
   	void step(float dt);
      unit_dir move(unit_dir direction);
};


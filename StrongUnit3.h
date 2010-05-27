#pragma once
#include "Unit.h"

class StrongUnit3 : public Unit {
   public:
   	StrongUnit3(float inx, float iny, float inz);
   	~StrongUnit3(void);
   	void draw();
   	void step(float dt);
      unit_dir move(unit_dir direction);
};


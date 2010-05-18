#pragma once
#include "Unit.h"

class StrongUnit2 : public Unit {
   public:
   	StrongUnit2(float inx, float iny, float inz);
   	~StrongUnit2(void);
   	void draw();
   	void step(float dt);
      unit_dir move(unit_dir direction);
};


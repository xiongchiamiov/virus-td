#pragma once
#include "Unit.h"

class FastUnit : public Unit
{
   public:
   	FastUnit(void);
   	~FastUnit(void);
   	void draw();
	   void step(float dt);
};



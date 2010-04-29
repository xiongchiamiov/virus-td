#pragma once
#include "Unit.h"

class BasicUnit :
	public Unit
{
public:
	BasicUnit(float inx, float iny, float inz, int gx, int gy);
	//BasicUnit(void);
	~BasicUnit(void);
	void draw();
	void step(float dt);
   unit_dir move(unit_dir direction);
};

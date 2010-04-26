#pragma once
#include "Unit.h"

class BasicUnit :
	public Unit
{
public:
	BasicUnit(void);
	~BasicUnit(void);
	void draw();
	void step(float dt);
};

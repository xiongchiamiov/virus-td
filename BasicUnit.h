#pragma once
#include "Unit.h"

class BasicUnit :
	public Unit
{
public:
	BasicUnit(float inx, float iny, float inz);
	//BasicUnit(void);
	~BasicUnit(void);
	void draw();
};

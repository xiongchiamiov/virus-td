#pragma once
#include "Unit.h"

class BossUnit :
	public Unit
{
public:
	BossUnit(float inx, float iny, float inz);
	//BasicUnit(void);
	~BossUnit(void);
	void draw();
};
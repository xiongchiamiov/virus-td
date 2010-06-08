#pragma once
#include "Unit.h"
#include "Camera.h"
extern Camera cam;

class BossUnit :
	public Unit
{
public:
	BossUnit(float inx, float iny, float inz);
	//BasicUnit(void);
	~BossUnit(void);
	void draw();
};
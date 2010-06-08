#pragma once
#include "Unit.h"
#include "Camera.h"

extern Camera cam;

class BasicUnit :
	public Unit
{
public:
   float increment;
	BasicUnit(float inx, float iny, float inz);
	//BasicUnit(void);
	~BasicUnit(void);
	void draw();
};

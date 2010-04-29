#pragma once
#include "Unit.h"

enum unit_dir{
  DIR_NORTH,
  DIR_SOUTH,
  DIR_EAST,
  DIR_WEST,
  DIR_COLLIDE,
};

class BasicUnit :
	public Unit
{
public:
	BasicUnit(float inx, float iny, float inz);
	//BasicUnit(void);
	~BasicUnit(void);
	void draw();
	
	void step(float dt);
  unit_dir move(unit_dir direction);
};

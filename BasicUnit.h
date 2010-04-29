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
	BasicUnit(float inx, float iny, float inz, int gx, int gy);
	//BasicUnit(void);
	~BasicUnit(void);
	void draw();
	int takeDamage(int damage); //returns health left
	void step(float dt);
   unit_dir move(unit_dir direction);
};

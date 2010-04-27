#pragma once
#include "Unit.h"
#include "GameGrid.h"
#include <list>

class UnitsAI
{
public:
	std::list<Unit*> uList;
	UnitsAI(GameGrid ingg);
	~UnitsAI(void);
	void determineUnitsPaths();
private:
	GameGrid gg;
};

#pragma once
#include "Unit.h"
#include <list>
#include "constants.h"
#include "Tower.h"

class UnitsAI
{
public:
	std::list<Unit*> uList;
	UnitsAI(void);
	~UnitsAI(void);
	void determineUnitsPaths();
};
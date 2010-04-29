#pragma once
#include "Unit.h"
#include <list>

class UnitsAI
{
public:
	std::list<Unit*> uList;
	UnitsAI(void);
	~UnitsAI(void);
	void determineUnitsPaths();
};

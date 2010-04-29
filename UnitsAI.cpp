#include "UnitsAI.h"

UnitsAI::UnitsAI(void)
{
}

UnitsAI::~UnitsAI(void)
{
}

void UnitsAI::determineUnitsPaths() {
	std::list<Unit*>::iterator i;

	// goal location will change
	g_elem goal(15, 31);

	for(i = uList.begin(); i != uList.end(); ++i) {
		while(true) {
			// left

			// right

			// up

			// down
		}
	}
}
#include "UnitsAI.h"

UnitsAI::UnitsAI(void)
{
}

UnitsAI::~UnitsAI(void)
{
}

void UnitsAI::determineUnitsPaths() {
	std::list<Unit*>::iterator i;

	// will be taken out once i establish how to get the current grid
	// begin
	const int G_WIDTH = 16;	
	const int G_HEIGHT = 32;
	int goalx = 15;
	int goaly = 31;
	int startx = 0;
	int starty = 0;
	bool grid[G_WIDTH][G_HEIGHT];
	// end

	for(i = uList.begin(); i != uList.end(); ++i) {
		
	}
}
#include "UnitsAI.h"

enum dir_t {
	north,
	south,
	east,
	west
};

struct MyNode {
	dir_t dir;
	int f;
	int g;
	int h;
};

UnitsAI::UnitsAI(GameGrid ingg)
{
	ingg = gg;
}

UnitsAI::~UnitsAI(void)
{
}

void UnitsAI::determineUnitsPaths() {
	std::list<Unit*>::iterator i;

	// begin
	int goalx = 15;
	int goaly = 31;
	// end

	/*for(i = uList.begin(); i != uList.end(); ++i) {
		int locx = 0; // get units current grid x location ?somehow?
		int locy = 0; // get units current grid y location ?somehow?

		while(locx != goalx && locy != goaly) {
			
			// north
			if(!gg.isWall(locx, locy - 1)) {
				
			}

			// south
			if(!gg.isWall(locx, locy + 1)) {
				
			}

			// east
			if(!gg.isWall(locx - 1, locy)) {
				
			}

			// west
			if(!gg.isWall(locx + 1, locy)) {
				
			}
		}
	}*/
}
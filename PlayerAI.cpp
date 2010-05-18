#include "PlayerAI.h"

PlayerAI::PlayerAI(void) {
	towers = 0;
	units = 0;
	updates = 0;
}
PlayerAI::~PlayerAI(void) {}

void PlayerAI::update(int dt) {
	//std::cout << "PlayerAI is updating for the " << updates << "th time.\n";
	
	// we don't want to do anything right at the very, very beginning
	if (updates) {
		if (!(updates % 200)) {
			/* randomly place towers
			 *
			 * NUMBER_OF_TOWERS is the number of different towers we can build
			 * STARTING_TOWER is the identifier for the lower-numbered tower
			 * These need to be modified when the towers in Player are changed,
			 * which means we probably shouldn't have them defined here. Oh well.
			 */
			srand(0);//time(NULL));
			const int NUMBER_OF_TOWERS = 6;
			const int STARTING_TOWER = 12;
			
			int i = 0;
			/*while(player.placeTower(rand() % player.pGrid.G_WIDTH + 1,
			                        rand() % player.pGrid.G_HEIGHT + 1,
			                        rand() % NUMBER_OF_TOWERS + STARTING_TOWER)
			   == INVALID_LOCATION
			   && i < 50) {
				// increment this so we don't go into infinite loops
				// when there are no available spots to place towers
				i++;
			}*/
		}
		if (!(updates % 500)) {
			player.spawnUnit(7);
		}
	}
	
	player.update(dt);
	updates++;
}

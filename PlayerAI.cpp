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
			player.placeTower(1, 1, 17);
		}
		if (!(updates % 500)) {
			player.spawnUnit(7);
		}
	}
	
	player.update(dt);
	updates++;
}

#include "PlayerAI.h"

PlayerAI::PlayerAI(void) {
	towers = 0;
	units = 0;
	updates = 0;
	desiredNumTowers = NULL;
	unitsToBuildCost = 0;
	GLfloat boundCol[] = {0.4,0.0,0.0};
	player.pGrid.setGridColor(boundCol);
	unitBunching = 1; // magick
	sendingUnitBunch = false;
}
PlayerAI::~PlayerAI(void) {}

void PlayerAI::update(int dt) {
	//std::cout << "PlayerAI is updating for the " << updates << "th time.\n";
	
	// we don't want to do anything right at the very, very beginning
	if (updates) {
		if (desiredNumTowers == NULL) {
			build_preferred_tower_layout();
			desiredNumTowers = towersToBuild.size();
		}
		
		/*cout << "Opponent's bytes: " << player.resources << endl;
		cout << "unitsToBuildCost: " << unitsToBuildCost << endl;
		cout << "Percentage of queue filled: " << unitsToBuild.size() << " / " << unitBunching << endl;
		cout << "need_more_towers(): " << need_more_towers() << endl;
		cout << "queue_more_units(): " << queue_more_units() << endl;*/
		
		if (need_more_towers() >= queue_more_units() && need_more_towers() > 0) {
			int towerCost = towersToBuild.top().first.second;
			if (player.resources >= towerCost + unitsToBuildCost) {
				int towerType = towersToBuild.top().first.first;
				pair<int, int> coordinates = towersToBuild.top().second;
				towersToBuild.pop();
				player.placeTower(coordinates.first, coordinates.second, towerType);
				//cout << towersToBuild.size() << "/" << desiredNumTowers << "towers left to build"
				//     << " (" << need_more_towers() << "%)." << endl;
			}
			else {
				//cout << "Didn't have " << towerCost << " bytes." << endl;
			}
		}
		else if (queue_more_units() > 0 && !sendingUnitBunch) {
			int percentageOfQueueFilled = (int)((float)(unitsToBuild.size()) / unitBunching * 100);
			if (percentageOfQueueFilled < 33) {
				unitsToBuild.push(make_pair(5, unit_cost::STRONG));
				unitsToBuildCost += unit_cost::STRONG;
			}
			else if (percentageOfQueueFilled < 67) {
				unitsToBuild.push(make_pair(7, unit_cost::BASIC));
				unitsToBuildCost += unit_cost::BASIC;
			}
			else {
				unitsToBuild.push(make_pair(8, unit_cost::FAST2));
				unitsToBuildCost += unit_cost::FAST2;
			}
			//cout << "Queued up another unit" << endl;
		}
		
		if (unitsToBuild.size() >= unitBunching && player.resources >= unitsToBuildCost) {
			sendingUnitBunch = true;
		}
		if (sendingUnitBunch) {
			//cout << "Attempting to send a unit out...";
			if (player.spawnUnit(unitsToBuild.front().first) == SUCCESS) {
				unitsToBuildCost -= unitsToBuild.front().second;
				unitsToBuild.pop();
				if (unitsToBuild.size() == 0) {
					sendingUnitBunch = false;
					// gradually increase how many units we send at a time
					unitBunching++;
				}
			}
		}
		//cout << endl;
	}
	
	player.update(dt);
	updates++;
}

void PlayerAI::build_preferred_tower_layout() {
	// for now, we'll totally just fake this
	towersToBuild.push(make_pair(make_pair(15, tower_cost::FAST), make_pair(6, 30)));
	towersToBuild.push(make_pair(make_pair(15, tower_cost::FAST), make_pair(9, 30)));
	towersToBuild.push(make_pair(make_pair(12, tower_cost::WALL), make_pair(4, 30)));
	towersToBuild.push(make_pair(make_pair(12, tower_cost::WALL), make_pair(2, 30)));
	towersToBuild.push(make_pair(make_pair(12, tower_cost::WALL), make_pair(0, 30)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(1, 27)));
	towersToBuild.push(make_pair(make_pair(12, tower_cost::WALL), make_pair(3, 27)));
	towersToBuild.push(make_pair(make_pair(12, tower_cost::WALL), make_pair(5, 27)));
	towersToBuild.push(make_pair(make_pair(12, tower_cost::WALL), make_pair(7, 27)));
	towersToBuild.push(make_pair(make_pair(12, tower_cost::WALL), make_pair(13, 28)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(14, 26)));
	towersToBuild.push(make_pair(make_pair(16, tower_cost::FREEZE), make_pair(14, 20)));
	towersToBuild.push(make_pair(make_pair(12, tower_cost::WALL), make_pair(11, 23)));
	towersToBuild.push(make_pair(make_pair(12, tower_cost::WALL), make_pair(9, 23)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(13, 23)));
	towersToBuild.push(make_pair(make_pair(12, tower_cost::WALL), make_pair(7, 23)));
	towersToBuild.push(make_pair(make_pair(12, tower_cost::WALL), make_pair(5, 23)));
}

// returns from 0 to 100, inclusive
int PlayerAI::need_more_towers() {
	// just the percentage of towers built
	if (towersToBuild.size() == 0) {
		return 0; // avoid divide-by-zero errors
	}
	return (int)((((float)towersToBuild.size()) / desiredNumTowers) * 100);
}

// returns 0 to 100, inclusive
int PlayerAI::queue_more_units() {
	if (unitsToBuild.size() == 0) {
		return 100; // avoid divide-by-zero error
	}
	return (int)((((((float)unitsToBuild.size()) / unitBunching) * 100) - 100) * -1);
}

void PlayerAI::reset(){
	while (!towersToBuild.empty()) {
		towersToBuild.pop();
	}
	towers = 0;
	units = 0;
	updates = 0;
	desiredNumTowers = NULL;
	unitsToBuildCost = 0;
	unitBunching = 1;
	sendingUnitBunch = false;
	player.reset();
}

#include "PlayerAI.h"

PlayerAI::PlayerAI(void) {
	towers = 0;
	units = 0;
	updates = 0;
	desiredNumTowers = NULL;
	unitsToBuildCost = 0;
	player.pGrid.setGridColor(EnemyGrid);
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
		
		cout << "Opponent's bytes: " << player.resources << endl;
		cout << "need_more_towers(): " << need_more_towers() << endl;
		cout << "queue_more_units(): " << queue_more_units() << endl;
		
		if (need_more_towers() >= queue_more_units() && need_more_towers() > 0) {
			int towerCost = towersToBuild.top().first.second;
			if (player.resources >= towerCost) {
				int towerType = towersToBuild.top().first.first;
				pair<int, int> coordinates = towersToBuild.top().second;
				towersToBuild.pop();
				player.placeTower(coordinates.first, coordinates.second, towerType);
				cout << towersToBuild.size() << "/" << desiredNumTowers << "towers left to build"
				     << " (" << need_more_towers() << "%)." << endl;
			}
			else {
				cout << "Didn't have " << towerCost << " bytes." << endl;
			}
		}
		else if (queue_more_units() > 0) {
			unitsToBuild.push(7);
			unitsToBuildCost += unit_cost::BASIC;
			cout << "Queued up another unit of cost " << unit_cost::BASIC << endl;
		}
		
		if (unitsToBuild.size() >= unitBunching && player.resources >= unitsToBuildCost) {
			while (unitsToBuild.size() > 0) {
				player.spawnUnit(unitsToBuild.top());
				unitsToBuildCost -= unit_cost::BASIC;
				unitsToBuild.pop();
			}
		}
	}
	
	player.update(dt);
	updates++;
}

void PlayerAI::build_preferred_tower_layout() {
	// for now, we'll totally just fake this
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(6, 30)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(9, 30)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(4, 30)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(2, 30)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(0, 30)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(1, 27)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(3, 27)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(5, 27)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(7, 27)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(13, 28)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(14, 26)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(15, 23)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(13, 23)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(11, 23)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(9, 23)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(7, 23)));
	towersToBuild.push(make_pair(make_pair(17, tower_cost::BASIC), make_pair(5, 23)));
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

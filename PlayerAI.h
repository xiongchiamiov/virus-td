#pragma once
#include "Player.h"
#include <iostream>

class PlayerAI {
  public:
    PlayerAI(void);
    ~PlayerAI(void);
    void update(int dt);
    Player player;
  private:
	void build_preferred_tower_layout();
	int need_more_towers();
	int queue_more_units();
    int towers;
    int units;
    int updates;
	int desiredNumTowers; // the number of towers we'd like to have
	stack< pair<int, int> > towersToBuild; // just (x,y) coordinates
	int towersToBuildCost;
	stack<int> unitsToBuild;
	int unitBunching; // number of units to send out in each push
};

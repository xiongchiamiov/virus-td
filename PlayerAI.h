#pragma once
#include "Player.h"
#include <iostream>
#include <queue>

class PlayerAI {
  public:
    PlayerAI(void);
    ~PlayerAI(void);
    void update(int dt);
    Player player;
    void reset();
  private:
	void build_preferred_tower_layout();
	int need_more_towers();
	int queue_more_units();
    int towers;
    int units;
    int updates;
	int desiredNumTowers; // the number of towers we'd like to have
	stack< pair< pair<int, int>, pair<int, int> > > towersToBuild; // tower type and tower cost, and (x,y) coordinates
	queue< pair<int, int> > unitsToBuild;
	int unitsToBuildCost;
	int unitBunching; // number of units to send out in each push
	bool sendingUnitBunch; // are we in the process of sending out a "bunch" of units?
};

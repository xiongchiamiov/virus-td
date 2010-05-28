#pragma once
#include "Player.h"
#include <iostream>

class PlayerAI {
  public:
    PlayerAI(void);
    ~PlayerAI(void);
    void update(int dt);
	void build_preferred_tower_layout();
	int need_more_towers();
    Player player;
  private:
    int towers;
    int units;
    int updates;
	int desiredNumTowers; // the number of towers we'd like to have
	stack< pair<int, int> > towersToBuild; // just (x,y) coordinates
};

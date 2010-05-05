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
    int towers;
    int units;
    int updates;
};

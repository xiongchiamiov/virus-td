#pragma once
#include "Player.h"
#include <iostream>

class PlayerAI {
  public:
    PlayerAI(void);
    ~PlayerAI(void);
    void update(int dt);
  private:
    Player player;
    int towers;
    int units;
    int updates;
};

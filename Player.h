#pragma once
#include "GameGrid.h"

class Player
{
public:
  Player(void);
  ~Player(void);
  void placeTower();
  void spawnUnit();
  void upgradeTower();
  void destroyTower();
private:
  int resources;
  GameGrid playerGrid;
};

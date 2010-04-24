#pragma once
#include "GameGrid.h"
#include "Tower.h"
#include "Unit.h"
#include "BasicTower.h"
#include <list>

class Player
{
public:
  Player(void);
  ~Player(void);
  void placeTower(int x, int y);
  void spawnUnit();
  void upgradeTower();
  void destroyTower(int x, int y);
  void draw();
private:
  int resources;
  int lives;
  GameGrid pGrid;
  std::list<Tower*> tList;
  std::list<Unit*> uList;
};

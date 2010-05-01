#pragma once
#include "GameGrid.h"
#include "Tower.h"
#include "BasicTower.h"
#include "FreezeTower.h"
#include "FastTower.h"
#include "SlowTower.h"
#include "TrapTower.h"
#include "WallTower.h"
#include "Unit.h"
#include "BasicUnit.h"
#include "UnitsAI.h"
#include <list>

class Player
{
public:
  Player(void);
  ~Player(void);
  void placeTower(int x, int y, int towerID);
  void spawnUnit(int unitID);
  void upgradeTower();
  void destroyTower(int x, int y);
  void moveUnits(float dt);
  void draw();
  void update(int dt);
  int getIncome();
  int calcResources();
  std::list<Tower*> tList;
private:
  int resources;
  int lives;
  int income;
  GameGrid pGrid;
  UnitsAI uai;
};

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
#include "FastUnit.h"
#include "UnitsAI.h"
#include <list>
#include <stack>

enum ReturnCode {SUCCESS, INSUFFICIENT_BYTES, INVALID_LOCATION, INVALID_TOWER};

class Player
{
public:
  Player(void);
  ~Player(void);
  ReturnCode placeTower(int x, int y, int towerID);
  void spawnUnit(int unitID);
  void upgradeTower();
  void destroyTower(int x, int y);
  void moveUnits(float dt);
  void draw();
  void update(int dt);
  int getIncome();
  int calcResources();
  void setOpponent(Player* newOpp);
  GameGrid pGrid;
  
private:
  int resources;
  int lives;
  int income;
  std::list<Tower*> tList;
  UnitsAI uai;
  std::stack<Unit*> delStack;
  Player* opponent;
};

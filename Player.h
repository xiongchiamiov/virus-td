#pragma once
#include "GameGrid.h"
#include "Tower.h"
//#include "Unit.h"
//#include "Tower.h"
#include "BasicTower.h"
#include "FastTower.h"
#include "FreezeTower.h"
#include "SlowTower.h"
#include "TrapTower.h"
#include "WallTower.h"
#include <list>
#include "BasicUnit.h"
//#include "UnitsAI.h"

class Player
{
public:
  Player(void);
  ~Player(void);
  void placeTower(int x, int y, int towerID);
  void spawnUnit(int x, int y);
  void upgradeTower();
  void destroyTower(int x, int y);
  void moveUnits(float dt);
  void draw();
  void update(int dt);
private:
  int resources;
  int lives;
  GameGrid pGrid;
  std::list<Tower*> tList;
  std::list<Unit*>  uList;
  //UnitsAI uai;
};

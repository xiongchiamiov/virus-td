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
#include "StrongUnit.h"
#include "FastUnit.h"
#include "StrongUnit2.h"
#include "StrongUnit3.h"
#include "UnitsAI.h"
#include "vfc.h"
#include <list>
#include <stack>

enum ReturnCode {SUCCESS, INSUFFICIENT_BYTES, INVALID_LOCATION, INVALID_TOWER};

class Player
{
  private:
  int resources;
  int lives;
  int income;
  std::list<Tower*> tList;
  UnitsAI uai;
  std::stack<GameObject*> delStack;
  Player* opponent;
  MyVector pos;
public:
  Player(void);
  ~Player(void);
  ReturnCode placeTower(int x, int y, int towerID);
  void spawnUnit(int unitID);
  void upgradeTower();
  void destroyTower(int x, int y);
  void moveUnits(float dt);
  void draw(bool isPlacing);
  bool cull(GameObject* obj);
  void update(int dt);
  int getIncome(void);
  int getResources(void);
  int getLives(void);
  MyVector getPosition(void);
  int calcResources();
  void setOpponent(Player* newOpp);
  inline void setPosition(float x, float y, float z){ pos.setPosition(x, y, z);}
  GameGrid pGrid;
};

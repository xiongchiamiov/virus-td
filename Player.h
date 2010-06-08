#pragma once
#include "GameGrid.h"
#include "Projectile.h"
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
#include "BossUnit.h"
#include "FastUnit2.h"
#include "vfc.h"
#include <list>
#include <stack>

enum ReturnCode {SUCCESS, INSUFFICIENT_BYTES, INVALID_LOCATION, INVALID_TOWER};

class Player
{
  private:
  int lives;
  int income;
  int uCooldown;
  std::list<Tower*> tList;
  UnitsAI uai;
  std::stack<GameObject*> delStack;
  Player* opponent;
  MyVector pos;
  ProjectileManager projectiles;
public:
  Player(void);
  ~Player(void);
  ReturnCode placeTower(int x, int y, int towerID);
  void spawnUnit(int unitID);
  void upgradeTower(int x, int y);
  void changeTowerMode(int x, int y, target_mode mode);
  void destroyTower(int x, int y);
  void moveUnits(float dt);
  void draw(bool isPlacing); // mode is used for picking
  bool cull(GameObject* obj);
  void update(int dt);
  int getIncome(void);
  int getResources(void);
  int getLives(void);
  std::list<Tower*> getTowerList(void);
  inline int getUnitCooldown(){return uCooldown;}
  MyVector getPosition(void);
  int calcResources();
  void setOpponent(Player* newOpp);
  inline void setPosition(float x, float y, float z){ pos.setPosition(x, y, z);}
  int resources;
  GameGrid pGrid;
  void reset();
};

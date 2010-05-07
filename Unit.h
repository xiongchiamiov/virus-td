#pragma once
#include <list>
#include <stack>
#include <iostream>
#include <math.h>
#include "constants.h"
#include "MyVector.h"
#include "GameObject.h"

enum unit_dir{
  DIR_NORTH,
  DIR_SOUTH,
  DIR_EAST,
  DIR_WEST,
  DIR_COLLIDE,
};

enum unit_t{
  U_BASIC,
  U_FAST,
  U_STRONG
};

class Unit :
  public GameObject
{
protected:
  int hp;
  int max_hp;
  int atk_dmg;
  float speed;
  unit_t type;
  int value;
  int build_time;//Measured in milliseconds
  int stage;     //Upgrade stage
public:
  Unit(float inx, float iny, float inz);
  virtual ~Unit(void);
  void attack();
  int takeDamage(int damage); //returns health left
  void moveToWaypoint();
  inline bool isDead(){return hp <= 0;}
  inline int getHP(){return hp;}
  inline float getSpeed(){return speed;}
  inline unit_t getValue(){return type;}
  void step(int dt);
  std::stack<g_elem> path;
  MyVector dir;
  bool foundGoal;
};
//
//class UnitList{
//public:
//  UnitList();
//  ~UnitList();
//  std::list<Unit*>::iterator begin();
//  std::list<Unit*>::iterator end();
//  void remove(std::list<Unit*>::iterator& iter);
//  
//private:
//  std::list<Unit*>* uList;
//};

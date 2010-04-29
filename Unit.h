#pragma once
#include <list>
#include "GameObject.h"
#include "MyVector.h"

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
public:
  Unit(float inx, float iny, float inz);
  virtual ~Unit(void);
  void attack();
  int takeDamage(int damage); //returns health left
  void moveToWaypoint();

protected:
  int hp;
  int max_hp;
  int atk_dmg;
  float speed;
  MyVector dir;
  unit_t type;
  int build_time;//Measured in milliseconds
  int stage;     //Upgrade stage
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

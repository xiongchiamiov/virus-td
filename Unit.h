#pragma once
#include <list>
#include "GameObject.h"
#include "MyVector.h"

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
  void moveToWaypoint();
  int takeDamage(int damage); //returns health left
protected:
  int hp;
  int max_hp;
  int atk_dmg;
  float speed;
  MyVector dir;
  unit_t type;
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

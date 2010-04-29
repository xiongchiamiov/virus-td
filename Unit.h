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
  Unit(float inx, float iny, float inz, int gx, int gy);
  virtual ~Unit(void);
  void attack();
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
  int grid_x;    //Coordinates with respect
  int grid_y;    //  to the game grid
 // UnitsAI ai;    //This unit's AI object
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

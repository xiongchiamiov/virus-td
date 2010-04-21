#pragma once
#include "GameObject.h"
#include "MyVector.h"

enum unit_t{
  U_REG,
  U_FAST,
  U_STRONG
};

class Unit :
  public GameObject
{
public:
  Unit(void);
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
};

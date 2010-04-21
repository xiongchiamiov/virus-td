#pragma once
#include "GameObject.h"

enum tower_t{
  T_BASIC,
  T_FREEZE,
  T_FAST
};

class Tower :
  public GameObject
{
public:
  Tower(float inx, float iny, float inz);
  virtual ~Tower(void);
  void shoot();
protected:
  int hp;        //Current HP
  int max_hp;    //Maximum HP
  int atk_dmg;   //Amount of damage
  float range;   //This tower's maximum range
  tower_t type;  //Type of tower
  int build_time;//Measured in milliseconds
  int stage;     //Upgrade stage
  int grid_x;    //Coordinates with respect
  int grid_y;    //  to the game grid
};

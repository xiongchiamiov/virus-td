#pragma once
#include "GameObject.h"
#include "TowerAI.h"
#include "Unit.h"
#include "constants.h"
#include <list>

enum tower_t{
  T_BASIC,
  T_FREEZE,
  T_FAST,
  T_SLOW,
  T_TRAP,
  T_WALL
};

//class Unit;

class Tower :
  public GameObject
{
protected:
  int hp;        //Current HP
  int max_hp;    //Maximum HP
  tower_t type;  //Type of tower
  int build_time;//Measured in milliseconds
  int stage;     //Upgrade stage
  int grid_x;    //Coordinates with respect
  int grid_y;    //  to the game grid
  TowerAI ai;    //This tower's AI object
public:
  Tower(float inx, float iny, float inz, int gx, int gy);
  virtual ~Tower(void);
  virtual bool shoot();
  inline int getGridX(){return grid_x;}
  inline int getGridY(){return grid_y;}
  inline float getWidth(){return x + GRID_SIZE * 2.0;}
  inline float getHeight(){return z + GRID_SIZE * 2.0;}
  bool operator==(const Tower& other);
  bool operator==(const g_elem& other);
  inline void setEnemyUnitList(std::list<Unit*> &enUList){ ai.targetList = &enUList;}
  void step(int dt);
  //inline void setTargetMode(target_mode nMode){ ai.setMode(nMode);}
};

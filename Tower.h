#pragma once
#include "GameObject.h"
#include "TowerAI.h"
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
struct g_elem{
  int x;
  int y;
  g_elem():x(0),y(0){}
  g_elem(int nx, int ny):x(nx),y(ny){}
  bool operator==(const g_elem other)
  { return (this->x == other.x) && (this->y == other.y);}
};

class Unit;

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
};

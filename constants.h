#pragma once
#include "MyVector.h"
extern const int GRID_WIDTH;
extern const int GRID_HEIGHT;
extern const float GRID_SIZE;
extern const int CYCLE_TIME;
extern const int SLOW_TIME;
extern const float GOAL_X;
extern const float GOAL_Z;
extern const float START_X;
extern const float START_Z;
extern bool RAND_SEEDED;
extern const float P1_POSX;
extern const float P1_POSY;
extern const float P1_POSZ;
extern const float OPP_POSX;
extern const float OPP_POSY;
extern const float OPP_POSZ;
extern const float OPP_POSX2;
extern const float OPP_POSY2;
extern const float OPP_POSZ2;

namespace unit_cost{
  extern const int BASIC;
  extern const int FAST;
  extern const int STRONG;
  extern const int STRONG2;
}
namespace unit_bonus{
  extern const int BASIC;
  extern const int FAST;
  extern const int STRONG;
  extern const int STRONG2;
}
namespace tower_cost{
  extern const int BASIC;
  extern const int FAST;
  extern const int FREEZE;
  extern const int SLOW;
  extern const int TRAP;
  extern const int WALL;
}

namespace tower_damage{
  extern const int BASIC;
  extern const int FAST;
  extern const int FREEZE;
  extern const int SLOW;
  extern const int TRAP;
  extern const int WALL;
}

namespace tower_name{
  extern const char* BASIC;
  extern const char* FAST;
  extern const char* FREEZE;
  extern const char* SLOW;
  extern const char* TRAP;
  extern const char* WALL;
}

namespace tower_description{
  extern const char* BASIC;
  extern const char* FAST;
  extern const char* FREEZE;
  extern const char* SLOW;
  extern const char* TRAP;
  extern const char* WALL;
}

struct g_elem{
  int x;
  int y;
  g_elem():x(0),y(0){}
  g_elem(int nx, int ny):x(nx),y(ny){}
  bool operator==(const g_elem other)
  { return (this->x == other.x) && (this->y == other.y);}
};

g_elem loc2grid(float x, float z);
void grid2loc(g_elem g, float * x, float * z);

const char* getTowerName(int index);
const char* getTowerDescription(int index);
int getTowerCost(int index);
int getTowerDamage(int index);
int getTowerSpeed(int index);
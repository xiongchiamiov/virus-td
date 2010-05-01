#pragma once
extern const int GRID_WIDTH;
extern const int GRID_HEIGHT;
extern const float GRID_SIZE;
extern const int CYCLE_TIME;

namespace unit_cost{
  extern const int BASIC;
  extern const int FAST;
  extern const int STRONG;
}
namespace unit_bonus{
  extern const int BASIC;
  extern const int FAST;
  extern const int STRONG;
}
namespace tower_cost{
  extern const int BASIC;
  extern const int FAST;
  extern const int FREEZE;
  extern const int SLOW;
  extern const int TRAP;
  extern const int WALL;
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
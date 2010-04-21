#pragma once
#include <list>
#include <gl/glut.h>
#include "lighting.h"

struct g_elem{
  int x;
  int y;
  g_elem():x(0),y(0){}
  g_elem(int nx, int ny):x(nx),y(ny){}
  bool operator==(const g_elem other)
  { return (this->x == other.x) && (this->y == other.y);}
};

const int GRID_WIDTH = 16;
const int GRID_HEIGHT = 32;
const float GRID_SIZE = 0.25;

class GameGrid
{
public:
  GameGrid(void);
  ~GameGrid(void);
  void draw();
  bool setTower(int x, int y);
  bool removeTower(int x, int y, std::list<g_elem>& towers);
private:
  float x;
  float y;
  bool grid[GRID_WIDTH][GRID_HEIGHT];

};

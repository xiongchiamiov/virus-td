#pragma once
#include <list>
//#include <gl/glut.h>
#include "lighting.h"
#include "constants.h"
#include "Tower.h"
//struct GridElement{
//  bool isEmpty;
//  Tower* tower;
//  bool isRemoved;
//};
class GameGrid
{
public:
  GameGrid(void);
  ~GameGrid(void);
  void draw();
  bool setTower(int x, int y);
  bool setUnit(int x, int y);
  bool removeTower(int x, int y, std::list<Tower*>& towers);
  bool destroyTower(int x, int y);
  bool isWall(g_elem cur);
  void setTowerGrid(int x, int y, Tower* tPtr);
  Tower* checkCollision(Unit* unit);
  static const int G_WIDTH = 16;
  static const int G_HEIGHT = 32;
private:
  float x;
  float y;
  bool grid[G_WIDTH][G_HEIGHT];
  Tower* tGrid[G_WIDTH][G_HEIGHT];
};
#pragma once
#include <list>
 #ifdef __unix__
     #include <GL/glut.h>
 #endif

 #ifdef __APPLE__
     #include "GLUT/glut.h"
 #endif

 #ifdef _WIN32
     #include <io.h>
     #include <fcntl.h>
     #include <glut.h>
 #endif
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
  bool removeTower(int x, int y, std::list<Tower*>& towers);
  bool isWall(int x, int y);
  static const int G_WIDTH = 16;
  static const int G_HEIGHT = 32;
private:
  float x;
  float y;
  bool grid[G_WIDTH][G_HEIGHT];
};

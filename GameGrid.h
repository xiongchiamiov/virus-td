#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <time.h>
//#include <gl/glut.h>
#include "lighting.h"
#include "constants.h"
#include "Tower.h"
//struct GridElement{
//  bool isEmpty;
//  Tower* tower;
//  bool isRemoved;
//};

const int FRACTAL_DEPTH = 2;
const float FRACTAL_VAR = 0.75;

class FractalSet {
public:
	FractalSet(int s_i,int e_i,int s_j,int e_j);
	void draw(void);
private:
	int start_i, end_i;
	int start_j, end_j;
	std::vector<std::vector<GLfloat> > zVals;
	void createFractals(int start_i, int h_cnt, int v_cnt);
};

class GameGrid
{
public:
  GameGrid(void);
  GameGrid(char  *filename);
  ~GameGrid(void);
  void draw();
  bool setTower(int x, int y);
  bool setUnit(int x, int y);
  bool removeTower(int x, int y, std::list<Tower*>& towers);
  bool destroyTower(int x, int y);
  bool isWall(g_elem cur);
  bool origianlIsWall(g_elem cur);
  void setTowerGrid(int x, int y, Tower* tPtr);
  Tower* checkCollision(Unit* unit);
  static const int G_WIDTH = 16;
  static const int G_HEIGHT = 32;
private:
  float x;
  float y;
  bool grid[G_WIDTH][G_HEIGHT];
  bool oGrid[G_WIDTH][G_HEIGHT];
  bool frac[G_WIDTH][G_HEIGHT];
  Tower* tGrid[G_WIDTH][G_HEIGHT];
  void createFractals(void);
  void drawFractals(void);
  std::list<FractalSet*> f_sets;
};
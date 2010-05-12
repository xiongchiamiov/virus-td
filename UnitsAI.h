#pragma once
#include "Unit.h"
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <math.h>
#include <iostream>
#include "GameGrid.h"
#include "constants.h"

int heuristic(g_elem cur, g_elem goal, int inRangeGrid[][40]); // note MAGIC NUMBERS

struct MyNode {
	g_elem loc;
	MyNode* parent;
	int f;
	int g;
	int h;
	MyNode(g_elem inloc, MyNode* inparent, int ing, int inh):
		loc(inloc),parent(inparent),g(ing),h(inh),f(ing+inh){}
};

class UnitsAI
{
public:
	std::list<Unit*> uList;
	std::list<Tower*> tList;
	GameGrid * gg;
	UnitsAI(void);
	UnitsAI(GameGrid& ingg, std::list<Tower*> &intList);
	~UnitsAI(void);
	void determineUnitsPaths();
    void setGrid(GameGrid& inGrid);
};

class CompareMyNode {
public:
	bool operator()(const MyNode* n1, const MyNode* n2) { 
		return (n2->f < n1->f); 
	}
};
#pragma once
#include "Unit.h"
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <math.h>
#include "constants.h"
#include "Tower.h"
#include "GameGrid.h"

int heuristic(g_elem cur, g_elem goal);

struct MyNode {
	g_elem loc;
	MyNode * parent;
	int f;
	int g;
	int h;
	MyNode(g_elem inloc, MyNode * inparent, int ing, int inh):
		loc(inloc),parent(inparent),g(ing),h(inh),f(ing+inh){}
};

class UnitsAI
{
public:
	std::list<Unit*> uList;
	GameGrid gg;
	UnitsAI(void);
	UnitsAI(GameGrid ingg);
	~UnitsAI(void);
	void determineUnitsPaths();
};

class CompareMyNode {
public:
	bool operator()(MyNode& n1, MyNode& n2) {
		if(n1.f <= n2.f)
			return true;
		else
			return false;
	}
};
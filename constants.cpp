#include "constants.h"

const int GRID_WIDTH = 16;
const int GRID_HEIGHT = 32;
const float GOAL_X = 3.5;
const float GOAL_Z = 17.5;
const float START_X = 3.5;
const float START_Z = -2.0;
const float GRID_SIZE = 0.25;
const int CYCLE_TIME = 5000;


namespace unit_cost{
  const int BASIC = 5;
  const int FAST = 10;
  const int STRONG = 20;
}
namespace unit_bonus{
  const int BASIC = 1;
  const int FAST = 2;
  const int STRONG = 5;
}
namespace tower_cost{
  const int BASIC = 5;
  const int FAST = 5;
  const int FREEZE = 10;
  const int SLOW = 25;
  const int TRAP = 15;
  const int WALL = 2;
}

namespace tower_name{
  extern const char* BASIC = "Basic";
  extern const char* FAST = "Fast";
  extern const char* FREEZE = "Freeze";
  extern const char* SLOW = "Slow";
  extern const char* TRAP = "Trap";
  extern const char* WALL = "Wall";
}

namespace tower_description{
  extern const char* BASIC = "This is the basic tower";
  extern const char* FAST = "This is the fast tower\nIts description has two lines";
  extern const char* FREEZE = "This is the freeze tower";
  extern const char* SLOW = "This is the slow tower";
  extern const char* TRAP = "This is the trap tower";
  extern const char* WALL = "This is the wall tower";
}

g_elem loc2grid(float x, float z) {
	return g_elem((int)((x)/(2.0 * GRID_SIZE) + 0.5), (int)((z)/(2.0 * GRID_SIZE) + 0.5 + 4.0));
}

void grid2loc(g_elem g, float * x, float * z) {
	*x = GRID_SIZE * 2.0 * g.x;
	*z = GRID_SIZE * 2.0 * g.y - 2.0;
}

int getTowerCost(int index) {
	switch(index) {
		case 0:	return tower_cost::BASIC;
			break;
		case 1: return tower_cost::FAST;
			break;
		case 2: return tower_cost::FREEZE;
			break;
		case 3: return tower_cost::SLOW;
			break;
		case 4: return tower_cost::TRAP;
			break;
		case 5: return tower_cost::WALL;
			break;
		default: return -1;
			 break;
	}
}

int getTowerDamage(int index) {
	return -1;
}

int getTowerSpeed(int index) {
	return -1;
}

const char* getTowerName(int index) {
	switch(index) {
		case 0:	return tower_name::BASIC;
			break;
		case 1: return tower_name::FAST;
			break;
		case 2: return tower_name::FREEZE;
			break;
		case 3: return tower_name::SLOW;
			break;
		case 4: return tower_name::TRAP;
			break;
		case 5: return tower_name::WALL;
			break;
		default: return "Unnamed";
			 break;
	}
}

const char* getTowerDescription(int index) {
	switch(index) {
		case 0:	return tower_description::BASIC;
			break;
		case 1: return tower_description::FAST;
			break;
		case 2: return tower_description::FREEZE;
			break;
		case 3: return tower_description::SLOW;
			break;
		case 4: return tower_description::TRAP;
			break;
		case 5: return tower_description::WALL;
			break;
		default: return "N/A";
			 break;
	}
}
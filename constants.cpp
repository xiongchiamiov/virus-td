#include "constants.h"

const int GRID_WIDTH = 16;
const int GRID_HEIGHT = 32;
const float GOAL_X = 3.5;
const float GOAL_Z = 17.5;
const float START_X = 3.5;
const float START_Z = -2.0;
const float GRID_SIZE = 0.25;
const int CYCLE_TIME = 5000;
const int SLOW_TIME = 3000;
bool RAND_SEEDED = false;
const float P1_POSX = -GRID_SIZE*float(GRID_WIDTH) + GRID_SIZE;
const float P1_POSY = 0.0;
const float P1_POSZ = -GRID_SIZE*float(GRID_HEIGHT) + GRID_SIZE;
const float OPP_POSX = -GRID_SIZE*float(GRID_WIDTH) + GRID_SIZE;
const float OPP_POSY = 0.0;
const float OPP_POSZ = -GRID_SIZE*float(GRID_HEIGHT) + GRID_SIZE + GRID_SIZE*(GRID_HEIGHT + 8)*2.0;
const float OPP_POSX2 = -GRID_SIZE*float(GRID_WIDTH) + GRID_SIZE + GRID_SIZE*(GRID_WIDTH + 8)*2.0;
const float OPP_POSY2 = 0.0;
const float OPP_POSZ2 = -GRID_SIZE*float(GRID_HEIGHT) + GRID_SIZE;



namespace unit_cost{
  const int BASIC = 5;
  const int FAST = 10;
  const int STRONG = 20;
  const int STRONG2 = 50;
  const int STRONG3 = 30;
}
namespace unit_bonus{
  const int BASIC = 1;
  const int FAST = 2;
  const int STRONG = 5;
  const int STRONG2 = 7;
  const int STRONG3 = 6;
}
namespace tower_cost{
  const int BASIC = 5;
  const int FAST = 5;
  const int FREEZE = 10;
  const int SLOW = 25;
  const int TRAP = 15;
  const int WALL = 2;
}

namespace tower_damage{
  const int BASIC = 10;
  const int FAST = 5;
  const int FREEZE = 10;
  const int SLOW = 25;
  const int TRAP = 15;
  const int WALL = 0;
}

namespace tower_speed{
  const int BASIC = 10;
  const int FAST = 25;
  const int FREEZE = 10;
  const int SLOW = 5;
  const int TRAP = 0;
  const int WALL = 0;
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
  extern const char* BASIC = "This tower has average speed\nand average damage";
  extern const char* FAST = "This tower fires very rapidly,\nbut its damage is low";
  extern const char* FREEZE = "This tower's damage is average,\nbut it causes enemies to slow\ndown after getting shot";
  extern const char* SLOW = "This tower has a very slow rate of fire,\nbut does a great deal of damage";
  extern const char* TRAP = "This tower can be placed along the path of\nviruses and it will do damage when\nthey cross the trap";
  extern const char* WALL = "This tower does not attack enemy units but\nmerely blocks them from passing";
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
	switch(index) {
		case 0:	return tower_damage::BASIC;
			break;
		case 1: return tower_damage::FAST;
			break;
		case 2: return tower_damage::FREEZE;
			break;
		case 3: return tower_damage::SLOW;
			break;
		case 4: return tower_damage::TRAP;
			break;
		case 5: return tower_damage::WALL;
			break;
		default: return -1;
			 break;
	}
}

int getTowerSpeed(int index) {
	switch(index) {
		case 0:	return tower_speed::BASIC;
			break;
		case 1: return tower_speed::FAST;
			break;
		case 2: return tower_speed::FREEZE;
			break;
		case 3: return tower_speed::SLOW;
			break;
		case 4: return tower_speed::TRAP;
			break;
		case 5: return tower_speed::WALL;
			break;
		default: return -1;
			 break;
	}
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
#include "constants.h"

const int GRID_WIDTH = 16;
const int GRID_HEIGHT = 32;
const float GOAL_X = 3.5;
const float GOAL_Z = 17.5;
const float START_X = 3.5;
const float START_Z = -2.0;
const float GRID_SIZE = 0.25;
const int CYCLE_TIME = 15000;
const int UNIT_COOLDOWN = 1000;
const int UNIT_MAX = 50;
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


namespace unit_cost {
  const int BASIC = 5;
  const int FAST = 10;
  const int FAST2 = 20;
  const int STRONG = 20;
  const int STRONG2 = 50;
  const int STRONG3 = 30;
  const int BOSS = 300;
}

namespace unit_bonus {
  const int BASIC = 1;
  const int FAST = 2;
  const int FAST2 = 3;
  const int STRONG = 5;
  const int STRONG2 = 12;
  const int STRONG3 = 7;
  const int BOSS = 20;
}

namespace unit_health {
  const int BASIC = 10;
  const int FAST = 8;
  const int FAST2 = 16;
  const int STRONG = 50;
  const int STRONG2 = 100;
  const int STRONG3 = 60;
  const int BOSS = 1000;
}

namespace unit_speed {
  const double BASIC = 0.0015;
  const double FAST = 0.003;
  const double FAST2 = 0.0032;
  const double STRONG = 0.001;
  const double STRONG2 = 0.001;
  const double STRONG3 = 0.0015;
  const double BOSS = 0.0017;
}

namespace unit_name {
   const char* BASIC = "Worm";
   const char* FAST = "Virus";
   const char* FAST2 = "Phish";
   const char* STRONG = "Fork Bomb";
   const char* STRONG2 = "Trojan Horse";
   const char* STRONG3 = "Lock";
   const char* BOSS = "Ultimate";
}

namespace unit_description {
   const char* BASIC = "This is a basic unit.";
   const char* FAST = "This unit is very fast, but dosen't\n have a lot of HP.";
   const char* STRONG = "This unit moves very \nslowly, but has a \nlot of HP.";
   const char* STRONG2 = "This unit moves very slowly, but has\n a lot of HP.";
   const char* FAST2 = "This unit is similar to the virus\n but it is stronger.";/*
   const char* STRONG = "This unit is strong, but slow.";
   const char* STRONG2 = "This unit is strong, but slow. This is stronger than a fork bomb.";*/
   const char* STRONG3 = "This unit is a stronger, faster worm unit.";
   const char* BOSS = "This is a boss unit. It is faster than normal\n units and extremely strong.";
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
  const char* BASIC = "Memory Turret";
  const char* FAST = "BackTrack";
  const char* FREEZE = "8-Core CPU Fan";
  const char* SLOW = "Tesla Coil";
  const char* TRAP = "Black Hat Trap";
  const char* WALL = "Firewall";
}

namespace tower_description{
  const char* BASIC = "This tower has average speed\nand average damage";
  const char* FAST = "This tower fires very rapidly,\nbut its damage is low";
  const char* FREEZE = "This tower's damage is average,\nbut it causes enemies to slow\ndown after getting shot";
  const char* SLOW = "This tower has a very slow rate of fire,\nbut does a great deal of damage";
  const char* TRAP = "This tower can be placed along the path of\nviruses and it will do damage when\nthey cross the trap";
  const char* WALL = "This tower does not attack enemy units but\nmerely blocks them from passing";
}

g_elem loc2grid(float x, float z) {
	return g_elem((int)((x)/(2.0 * GRID_SIZE) + 0.5), (int)((z)/(2.0 * GRID_SIZE) + 0.5 + 4.0));
}

void grid2loc(g_elem g, float * x, float * z) {
	*x = GRID_SIZE * 2.0 * g.x;
	*z = GRID_SIZE * 2.0 * g.y - 2.0;
}

   /* 
      Button Number Layout for checking the following
      Index parameters for button numbers on GUI.
      6 7 8         17 16 15
      3 4 5         14 13 12
      0 1 2         11 10 9
   */
int getObjectCost(int index) {
	switch(index) {
		case 17:	return tower_cost::BASIC;
			break;
		case 16: return tower_cost::FREEZE;
			break;
		case 15: return tower_cost::FAST;
			break;
		case 14: return tower_cost::SLOW;
			break;
		case 13: return tower_cost::TRAP;
			break;
		case 12: return tower_cost::WALL;
			break;

      case 8: return unit_cost::FAST2;
         break;
      case 7: return unit_cost::BASIC;
         break;
      case 6: return unit_cost::FAST;
         break;
      case 5: return unit_cost::STRONG;
         break;
      case 4: return unit_cost::STRONG2;
         break;
      case 3: return unit_cost::STRONG3;
         break;
         
      case 0: return unit_cost::BOSS;
         break;

		default: return -1;
			 break;
	}
}

int getObjectDamageHealth(int index) {
	switch(index) {
		case 17:	return tower_damage::BASIC;
			break;
		case 16: return tower_damage::FREEZE;
			break;
		case 15: return tower_damage::FAST;
			break;
		case 14: return tower_damage::SLOW;
			break;
		case 13: return tower_damage::TRAP;
			break;
		case 12: return tower_damage::WALL;
			break;
		case 6: return unit_health::FAST;
			break;
		case 7: return unit_health::BASIC;
			break;
		case 8: return unit_health::FAST2;
			break;
		case 3: return unit_health::STRONG3;
			break;
		case 4: return unit_health::STRONG2;
			break;
		case 5: return unit_health::STRONG;
			break;
		case 0: return unit_health::BOSS;
			break;
		default: return -1;
			 break;
	}
}

int getObjectSpeed(int index) {
	switch(index) {
		case 17:	return tower_speed::BASIC;
			break;
		case 16: return tower_speed::FREEZE;
			break;
		case 15: return tower_speed::FAST;
			break;
		case 14: return tower_speed::SLOW;
			break;
		case 13: return tower_speed::TRAP;
			break;
		case 12: return tower_speed::WALL;
			break;
		case 6: return (int)(10000.0 * unit_speed::FAST);
			break;
		case 7: return (int)(10000.0 * unit_speed::BASIC);
			break;
		case 8: return (int)(10000.0 * unit_speed::FAST2);
			break;
		case 3: return (int)(10000.0 * unit_speed::STRONG3);
			break;
		case 4: return (int)(10000.0 * unit_speed::STRONG2);
			break;
		case 5: return (int)(10000.0 * unit_speed::STRONG);
			break;
		case 0: return (int)(10000.0 * unit_speed::BOSS);
			break;
		default: return -1;
			 break;
	}
}

const char* getObjectName(int index) {
	switch(index) {
		case 17:	return tower_name::BASIC;
			break;
		case 16: return tower_name::FREEZE;
			break;
		case 15: return tower_name::FAST;
			break;
		case 14: return tower_name::SLOW;
			break;
		case 13: return tower_name::TRAP;
			break;
		case 12: return tower_name::WALL;
			break;
         
      case 8: return unit_name::FAST2;
         break;
      case 7: return unit_name::BASIC;
         break;
      case 6: return unit_name::FAST;
         break;
      case 5: return unit_name::STRONG;
         break;
      case 4: return unit_name::STRONG2;
         break;
      case 3: return unit_name::STRONG3;
         break;

      case 0: return unit_name::BOSS;
         break;

		default: return "Unnamed";
			 break;
	}
}

const char* getObjectDescription(int index) {
	switch(index) {
		case 17:	return tower_description::BASIC;
			break;
		case 16: return tower_description::FREEZE;
			break;
		case 15: return tower_description::FAST;
			break;
		case 14: return tower_description::SLOW;
			break;
		case 13: return tower_description::TRAP;
			break;
		case 12: return tower_description::WALL;
			break;
         
      case 8: return unit_description::FAST2;
         break;
      case 7: return unit_description::BASIC;
         break;
      case 6: return unit_description::FAST;
         break;
      case 5: return unit_description::STRONG;
         break;
      case 4: return unit_description::STRONG2;
         break;
      case 3: return unit_description::STRONG3;
         break;
         
      case 0: return unit_description::BOSS;
         break;
         
		default: return "N/A";
			 break;
	}
}
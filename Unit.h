#pragma once
#include <list>
#include <stack>
#include <iostream>
#include <math.h>
#include "constants.h"
#include "MyVector.h"
#include "GameObject.h"
#include "lighting.h"

enum unit_dir{
  DIR_NORTH,
  DIR_SOUTH,
  DIR_EAST,
  DIR_WEST,
  DIR_COLLIDE,
};

enum unit_t{
  U_BASIC,
  U_FAST,
  U_STRONG,
  U_BOSS
};

class Unit :
  public GameObject
{
protected:
  int hp;
  int max_hp;
  int atk_dmg;
  float speed;
  float max_speed;
  bool isSlowed;
  int slowTimer;
  unit_t type;
  int value;
  int build_time;//Measured in milliseconds
  int stage;     //Upgrade stage
  int last_atk; //Time since last attack
  int atk_dt; //Attack speed (number of milliseconds between attacks)
  int animateSpeed; // animation speed
  void drawHealthBar(void);
public:
  Unit(float inx, float iny, float inz);
  virtual ~Unit(void);
  void attack(GameObject* other);
  int takeDamage(int damage); //returns health left
  void moveToWaypoint();
  inline bool isDead(){return hp <= 0;}
  inline int getHP(){return hp;}
  inline float getSpeed(){return speed;}
  inline int getValue(){return value;}
  inline bool hasPath(){return hasPathB;}
  void step(int dt);
  void slow();
  bool checkCollison(GameObject* other);
  std::stack<g_elem> path;
  MyVector dir;
  bool foundGoal;
  bool hasPathB;
};
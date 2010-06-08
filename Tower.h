#pragma once
#include "GameObject.h"
#include "TowerAI.h"
#include "Unit.h"
#include "constants.h"
#include <list>
#include "Particles.h"
#include "Projectile.h"

enum tower_t{
  T_BASIC,
  T_FREEZE,
  T_FAST,
  T_SLOW,
  T_TRAP,
  T_WALL
};

class Tower :
  public GameObject
{
protected:
  int hp;        //Current HP
  int max_hp;    //Maximum HP
  tower_t type;  //Type of tower
  int build_time;//Measured in milliseconds
  int stage;     //Upgrade stage
  int grid_x;    //Coordinates with respect
  int grid_y;    //  to the game grid
  TowerAI ai;    //This tower's AI object
  Particles * weapon;// Particle
  char* sound;
  ProjectileManager* projectiles;
  double animateSpeed; // animation speed
  //shadow * the_shadow;
public:
  Tower(float inx, float iny, float inz, int gx, int gy);
  virtual ~Tower(void);
  virtual bool shoot();
  inline int getGridX(){return grid_x;}
  inline int getGridY(){return grid_y;}
  inline float getWidth(){return x + GRID_SIZE * 2.0;}
  inline float getHeight(){return z + GRID_SIZE * 2.0;}
  inline int getStage(){return stage;}
  inline tower_t getType(){return type;}
  bool operator==(const Tower& other);
  bool operator==(const g_elem& other);
  inline void setEnemyUnitList(std::list<Unit*> &enUList){ ai.targetList = &enUList;}
  inline void setProjectileManager(ProjectileManager* proj){ projectiles = proj;}
  virtual void step(int dt);
  virtual bool upgrade() = 0;
  void draw(void);
  virtual void draw(GLuint id, GLenum mode) = 0;
  int getKill();
  inline float getRange(){return ai.range;}
  inline void setTargetMode(target_mode nMode){ ai.setMode(nMode);}
  inline target_mode getTargetMode(void) { return ai.mode; }
  inline bool isDead(){return hp <= 0;}
  inline void retarget(){ if(ai.hasTarget && ai.target->isDead()) ai.hasTarget = false; }
  inline Unit* getTarget(){ return ai.target;}
  inline GLuint getWeaponType(){ return weapon->getWeaponType();}
  int takeDamage(int damage);
};

#pragma once
#include "Particles.h"
#include "MyVector.h"
#include "Unit.h"



class Projectile
{
private:
  Particles* effect;
  MyVector pos;
  float speed;
  Unit* target;
  bool done;
public:
  Projectile(Particles* p, Unit* targ, float x, float y, float z);
  ~Projectile(void);
  void draw();
  void step(int dt);
  inline bool getIsDone(){ return done;}
};

class ProjectileManager
{
private:
  std::list<Projectile> projectiles;
  //MyVector offset;
public:
  ProjectileManager();//float x, float y, float z);
  ~ProjectileManager();
  void addProjectile(Particles* p, Unit* targ, float x, float y, float z);
  void stepProjectiles(int dt);
  void drawProjectiles();
};
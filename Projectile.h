#pragma once
#include "Particles.h"
#include "MyVector.h"
#include "Unit.h"



class Projectile
{
private:
  Particles effect;
  MyVector pos;
  float speed;
  Unit* target;
  bool done;
public:
  Projectile(float pSize, Unit* targ, float x, float y, float z);
  ~Projectile(void);
  void draw();
  void step(int dt);
  inline bool getIsDone(){ return done;}
};

void addProjectile(float pSize, Unit* targ, float x, float y, float z);
void stepProjectiles(int dt);
void drawProjectiles();
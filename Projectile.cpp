#include <list>
#include "Projectile.h"

namespace projectile{
  const float SPD = 0.05;
  std::list<Projectile> projectiles;
}
using namespace projectile;

Projectile::Projectile(float pSize, Unit* targ, float x, float y, float z):
effect(pSize), target(targ), done(false), pos(0.0, 0.0, 0.0, x, y, z)
{
}

Projectile::~Projectile(void)
{
}

void Projectile::draw(){
  effect.drawParticles();
}

void Projectile::step(int dt){
  if(target != NULL && (target->isDead())){ /*|| ( (target->getX() >=  pos.getX() - SPD || target->getX() <= pos.getX() + SPD) 
                                           && (target->getY() >=  pos.getY() - SPD || target->getY() <= pos.getY() + SPD)
                                           && (target->getZ() >=  pos.getZ() - SPD || target->getZ() <= pos.getZ() + SPD)))){*/
    this->done = true;
  } else if(target != NULL){
  }
  //pos.setVector(target->getX() - pos
  pos.setPosition(pos.getX() + pos.getI() * SPD, pos.getY() + pos.getJ() * SPD, pos.getZ() + pos.getK() * SPD);
}

void addProjectile(float pSize, Unit* targ, float x, float y, float z){
  projectiles.push_back(Projectile(pSize, targ, x, y, z));
}

void stepProjectiles(int dt){
  std::list<Projectile>::iterator p;
  for(p = projectiles.begin(); p != projectiles.end();){
    p->step(dt);
    if(p->getIsDone()){
      p = projectiles.erase(p);
    } else {
      ++p;
    }
  }
}

void drawProjectiles(){
  std::list<Projectile>::iterator p;
  for(p = projectiles.begin(); p != projectiles.end(); ++p){
    p->draw();
  }
}
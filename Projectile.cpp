#include <list>
#include "Projectile.h"

namespace projectile{
  const float SPD = 0.5;
}
using namespace projectile;

Projectile::Projectile(Particles* p, Unit* targ, float x, float y, float z):
effect(p), target(targ), done(false), pos(0.0, 0.0, 0.0, x, y, z)
{
}

Projectile::~Projectile(void)
{
}

void Projectile::draw(){
  
  glPushMatrix();
  glTranslatef(pos.getX(), pos.getY(), pos.getZ());
  glScaled(0.15, 0.15, 0.15);
  effect->drawParticles();
  //glutSolidSphere(0.3, 4, 4);
  glPopMatrix();
}

void Projectile::step(int dt){
  if(target != NULL && (target->isDead() || (target->getX() >=  pos.getX() - SPD && target->getX() <= pos.getX() + SPD) 
                                         && (target->getY() >=  pos.getY() - SPD && target->getY() <= pos.getY() + SPD)
                                         && (target->getZ() >=  pos.getZ() - SPD && target->getZ() <= pos.getZ() + SPD)
                                         || target->foundGoal)){

    this->done = true;
  } else if(target != NULL){
    pos.setVector(target->getX() - pos.getX(), target->getY() - pos.getY(), target->getZ() - pos.getZ());
  }
  pos.normalize();
  pos.setPosition(pos.getX() + pos.getI() * SPD, pos.getY() + pos.getJ() * SPD, pos.getZ() + pos.getK() * SPD);
}

ProjectileManager::ProjectileManager()
{
}

ProjectileManager::~ProjectileManager(){
}

void ProjectileManager::addProjectile(Particles* p, Unit* targ, float x, float y, float z){
  projectiles.push_back(Projectile(p, targ, x, y, z));
}

void ProjectileManager::stepProjectiles(int dt){
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

void ProjectileManager::drawProjectiles(){
  std::list<Projectile>::iterator p;
  for(p = projectiles.begin(); p != projectiles.end(); ++p){
    p->draw();
  }
}
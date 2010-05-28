#include "BasicTower.h"
#include "constants.h"
#include "models.h"
#include "Particles.h"
#include "shadow.h"

namespace b_tower{
  const int MAX_UPGRADES = 3;
  const int MAX_HP[MAX_UPGRADES] = {10, 20, 30};
  const int ATK[MAX_UPGRADES] = {3, 6, 12};
  const int ATK_DT[MAX_UPGRADES] = {1000, 1000, 1000}; //Milleseconds between attacks
  const float RANGE[MAX_UPGRADES] = {3.0, 3.0, 3.0};
  const int BUILD_TIME = 3000;
}
using namespace b_tower;

BasicTower::BasicTower(float inx, float iny, float inz, int gx, int gy):
Tower(inx, iny, inz, gx, gy)
{
  hp = MAX_HP[0];
  max_hp = MAX_HP[0];
  ai.atk_dmg = ATK[0];
  ai.atk_dt = ATK_DT[0]; 
  ai.range = RANGE[0];
  type = T_BASIC;
  build_time = BUILD_TIME;
  stage = 0;
  weapon = new Particles(0.3);
  weapon->setWeaponType(particle_texture[0]);
}

BasicTower::~BasicTower(void)
{
  delete weapon;
}

void BasicTower::draw(){
  glPushMatrix();
     setMaterial(Yellow);
     if(ai.hasTarget){
       glBegin(GL_LINES);
         glVertex3f(x, GRID_SIZE*2.0, z);
         glVertex3f(ai.target->getX(), ai.target->getY(), ai.target->getZ());
       glEnd();
     }
     glTranslatef(x, y, z);
     glPushMatrix();
         glPushMatrix();
            // Scale and orient animation to fit grid
            glTranslatef(0.0, 0.25, 0.0);
            glScaled(0.15, 0.15, 0.15);
            if(ai.hasTarget){            
               if(ai.last_atk < ai.atk_dt) {
                  weapon->setDirection(ai.target->getX() - x, 0.0, ai.target->getZ() - z, true);
                  weapon->drawParticles();
               }
            } else {
               weapon->reset();
            }
         glPopMatrix();

         // Scale and orient model to fit grid
         glTranslatef(0.0, 0.25, 0.0);
         // Mini Tower Defense TBQH
         glScaled(0.15, 0.15, 0.15);

         glCallList(vtd_dl::turretDL);
      glPopMatrix();
	 glPushMatrix();
		draw_shadow(2);
	 glPopMatrix();
  glPopMatrix();
}

bool BasicTower::upgrade(){
  if(stage < MAX_UPGRADES){
    hp = MAX_HP[stage++];
    max_hp = MAX_HP[stage];
    ai.atk_dmg = ATK[stage];
    ai.atk_dt = ATK_DT[stage]; 
    ai.range = RANGE[stage];
    return true;
  }
  return false;
}
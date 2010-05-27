#include "FastTower.h"
#include "constants.h"
#include "models.h"
#include "Particles.h"

namespace fs_tower{
  const int MAX_UPGRADES = 3;
  const int MAX_HP[MAX_UPGRADES] = {4, 8, 12};
  const int ATK[MAX_UPGRADES] = {1, 2, 3};
  const int ATK_DT[MAX_UPGRADES] = {500, 500, 300}; //Milleseconds between attacks
  const float RANGE[MAX_UPGRADES] = {2.5, 2.5, 3.0};
  const int BUILD_TIME = 3000;
}

using namespace fs_tower;

FastTower::FastTower(float inx, float iny, float inz, int gx, int gy):
   Tower(inx, iny, inz, gx, gy)/*, hp(MAX_HP), max_hp(MAX_HP), atk_dmg(ATK),
type(T_BASIC), build_time(BUILD_TIME), stage(0)*/
{
  hp = MAX_HP[0];
  max_hp = MAX_HP[0];
  ai.atk_dmg = ATK[0];
  ai.atk_dt = ATK_DT[0]; 
  ai.range = RANGE[0];
  type = T_FAST;
  build_time = BUILD_TIME;
  stage = 0;
  weapon = new Particles(0.3);
  weapon->setWeaponType(particle_texture[1]);
}

FastTower::~FastTower(void)
{
  delete weapon;
}

void FastTower::draw(){
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
                  weapon->drawParticles();
               }
            } else {
               weapon->reset();
            }
         glPopMatrix();

       // Scale and orient model to fit grid
       glTranslatef(0.2, 2.0, 1.0);
       // Mini Tower Defense TBQH
       glScaled(0.03, 0.03, 0.03);
       glRotated(90, 0.0, 1.0, 0.0);

       glCallList(vtd_dl::backtrackDL);
    glPopMatrix();
  glPopMatrix();
}

void FastTower::step(float dt){

}


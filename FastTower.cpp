#include "FastTower.h"
#include "constants.h"
#include "models.h"
#include "Particles.h"

namespace fs_tower{
  const int MAX_HP = 6;
  const int ATK = 1;
  const float RANGE = 5.0;
  const int BUILD_TIME = 3500;
}

using namespace fs_tower;

FastTower::FastTower(float inx, float iny, float inz, int gx, int gy):
   Tower(inx, iny, inz, gx, gy)/*, hp(MAX_HP), max_hp(MAX_HP), atk_dmg(ATK),
type(T_BASIC), build_time(BUILD_TIME), stage(0)*/
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  ai.atk_dmg = ATK;
  ai.range = RANGE;
  type = T_FAST;
  build_time = BUILD_TIME;
  stage = 0;
  weapon = new Particles(0.3);
  weapon->setWeaponType(particle_texture[1]);
}

FastTower::~FastTower(void)
{
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


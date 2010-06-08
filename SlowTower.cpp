#include "SlowTower.h"
#include "constants.h"
#include "models.h"
#include "Particles.h"
#include "shadow.h"

namespace sl_tower{
  const int MAX_UPGRADES = 3;
  const int MAX_HP[MAX_UPGRADES] = {12, 20, 30};
  const int ATK[MAX_UPGRADES] = {6, 12, 18};
  const int ATK_DT[MAX_UPGRADES] = {3000, 3000, 3000}; //Milleseconds between attacks
  const float RANGE[MAX_UPGRADES] = {5.0, 6.0, 6.5};
  const int BUILD_TIME = 3000;
  char* SOUND = "media/sounds/big_laser.wav";
}

using namespace sl_tower;

SlowTower::SlowTower(float inx, float iny, float inz, int gx, int gy):
   Tower(inx, iny, inz, gx, gy)
{
  hp = MAX_HP[0];
  max_hp = MAX_HP[0];
  ai.atk_dmg = ATK[0];
  ai.atk_dt = ATK_DT[0]; 
  ai.range = RANGE[0];
  type = T_SLOW;
  build_time = BUILD_TIME;
  stage = 0;
  sound = SOUND;
  weapon = new Particles(0.3);
  weapon->setWeaponType(particle_texture[3]);
}

SlowTower::~SlowTower(void)
{
  delete weapon;
}

void SlowTower::draw(GLuint id, GLenum mode){
  glPushMatrix();
  setMaterial(Yellow);
  if(ai.hasTarget){
    glBegin(GL_LINES);
      glVertex3f(x, GRID_SIZE*2.0, z);
      glVertex3f(ai.target->getX(), ai.target->getY(), ai.target->getZ());
    glEnd();
  }
  setMaterial(GreenShiny);
  glTranslatef(x, y, z);
     glPushMatrix();
         //glPushMatrix();
         //   // Scale and orient animation to fit grid
         //   glTranslatef(0.0, 0.25, 0.0);
         //   glScaled(0.15, 0.15, 0.15);
         //   if(ai.hasTarget){
         //      if(ai.last_atk < ai.atk_dt) {
         //         weapon->setDirection(ai.target->getX() - x, 0.0, ai.target->getZ() - z, true);
         //         weapon->drawParticles();
         //      }

         //   } else {
         //      weapon->reset();
         //   }
         //glPopMatrix();

        // Scale and orient model to fit grid
        glTranslatef(0.0, 1.25, 0.0);
        // Mini Tower Defense TBQH
        glScaled(0.06, 0.08, 0.06);
        glRotated(83, 0.0, 1.0, 0.0);

        glCallList(vtd_dl::teslaDL);
     glPopMatrix();
	 glPushMatrix();
		draw_shadow(1);
	 glPopMatrix();
  glPopMatrix();
}

void SlowTower::step(float dt){

}

bool SlowTower::upgrade(){
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
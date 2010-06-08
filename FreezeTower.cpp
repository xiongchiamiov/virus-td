#include "FreezeTower.h"
#include "constants.h"
#include "models.h"
#include "Particles.h"
#include "shadow.h"

namespace f_tower{
  const int MAX_UPGRADES = 3;
  const int MAX_HP[MAX_UPGRADES] = {8, 12, 16};
  const int ATK[MAX_UPGRADES] = {4, 8, 16};
  const int ATK_DT[MAX_UPGRADES] = {3000, 3000, 3000}; //Milleseconds between attacks
  const float RANGE[MAX_UPGRADES] = {2.5, 2.5, 3.0};
  const int BUILD_TIME = 3000;
  char* SOUND = "media/sounds/whoosh.wav";
}

using namespace f_tower;

FreezeTower::FreezeTower(float inx, float iny, float inz, int gx, int gy):
   Tower(inx, iny, inz, gx, gy)
{
  hp = MAX_HP[0];
  max_hp = MAX_HP[0];
  ai.atk_dmg = ATK[0];
  ai.atk_dt = ATK_DT[0]; 
  ai.range = RANGE[0];
  type = T_FREEZE;
  build_time = BUILD_TIME;
  stage = 0;
  sound = SOUND;
  weapon = new Particles(0.3);
  weapon->setWeaponType(particle_texture[2]);
  weapon->setSpeed(1.75);
  weapon->setSpread(2.0);
  animateSpeed = 5;
}

FreezeTower::~FreezeTower(void)
{
  delete weapon;
}

void FreezeTower::draw(GLuint id, GLenum mode){
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
     //    glPushMatrix();
     //       // Scale and orient animation to fit grid
     //       glTranslatef(0.0, 0.25, 0.0);
     //       glScaled(0.15, 0.15, 0.15);
     //       if(ai.hasTarget){
     //          if(ai.last_atk < ai.atk_dt) {
     //             weapon->setDirection(ai.target->getX() - x, 0.0, ai.target->getZ() - z, true);
     //             weapon->drawParticles();
     //          }
     //       } else {
     //          weapon->reset();
     //       }
     //    glPopMatrix();

        // Scale and orient model to fit grid
        glTranslatef(0.0, 0.4, 0.0);
        // Mini Tower Defense TBQH
        glScaled(0.035, 0.035, 0.035);
        glTranslatef(0.0, 2.0, 0.0);

    // glCallList(vtd_dl::fanDL);
       if (animateSpeed >= 360) {
          animateSpeed = 0;
       }
       
  double dist = sqrt((getX() - cam.getCamX()) * (getX() - cam.getCamX())
     + (getY() - cam.getCamY()) * (getY() - cam.getCamY())
     + (getZ() - cam.getCamZ()) * (getZ() - cam.getCamZ()));

  if (dist <= 8) {
       drawFanDLAnimated(animateSpeed+=5, 3);
  } else if (dist <= 11) {
       drawFanDLAnimated(animateSpeed+=5, 2);
  } else {
       drawFanDLAnimated(animateSpeed+=5, 1);
  }
  
     glPopMatrix();
	 glPushMatrix();
		draw_shadow(4);
	 glPopMatrix();
  glPopMatrix();
}

void FreezeTower::step(float dt){

}

bool FreezeTower::shoot(){
  bool ret = Tower::shoot();
  if(ret){
    ai.target->slow();
  }
  return ret;
}

bool FreezeTower::upgrade(){
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
#include "FastTower.h"
#include "constants.h"
#include "models.h"
#include "Particles.h"
#include "shadow.h"

namespace fs_tower{
  const int MAX_UPGRADES = 3;
  const int MAX_HP[MAX_UPGRADES] = {4, 8, 12};
  const int ATK[MAX_UPGRADES] = {1, 2, 3};
  const int ATK_DT[MAX_UPGRADES] = {500, 500, 300}; //Milleseconds between attacks
  const float RANGE[MAX_UPGRADES] = {2.5, 2.5, 3.0};
  const int BUILD_TIME = 3000;
  char* SOUND = "media/sounds/Lazer.mp3";
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
  sound = SOUND;
  weapon = new Particles(0.3);
  weapon->setWeaponType(particle_texture[1]);
  weapon->setSpeed(1.75);
  weapon->setSpread(2.0);
  // remember that cutoffs are scaled down by however much the towers are scaled down
 // weapon->setCutOffs(250, 7, 250);
  animateSpeed = 0.0;
  increment = 0.025;
}

FastTower::~FastTower(void)
{
  delete weapon;
}

void FastTower::draw(GLuint id, GLenum mode){
  glPushMatrix();

  glTranslatef(x, y, z);
    glPushMatrix();
		if(mode == GL_SELECT) {
			 glLoadName(id);
			 glPushMatrix();
			 glScalef(1.0,0.5,1.0);
			 glTranslatef(0.0,0.6,0.0);
			 glutSolidCube(1.0f);
			 glPopMatrix();
		 }
         glPushMatrix();
            // Scale and orient animation to fit grid
            glTranslatef(0.0, 0.25, 0.0);
            glScaled(0.15, 0.15, 0.15);
            /*if(ai.hasTarget){
               if(ai.last_atk < ai.atk_dt) {
                  weapon->setDirection(ai.target->getX() - x, 0.0, ai.target->getZ() - z, true);
                  weapon->drawParticles();
               }
            } else {
        //       weapon->reset();
            }*/
         glPopMatrix();

       // Scale and orient model to fit grid
       glTranslatef(0.2, 2.0, 1.0);
       // Mini Tower Defense TBQH
       glScaled(0.02, 0.02, 0.02);
       glRotated(90, 0.0, 1.0, 0.0);

       if (animateSpeed >= 1.0) {
          increment = -0.025;
       }
       
       if (animateSpeed <= 0.0) {
          increment = 0.025;
       }

  double dist = sqrt((getX() - cam.getCamX()) * (getX() - cam.getCamX())
     + (getY() - cam.getCamY()) * (getY() - cam.getCamY())
     + (getZ() - cam.getCamZ()) * (getZ() - cam.getCamZ()));

  if(mode == GL_SELECT)
	  glLoadName(id);
  if (dist <= 8) {
     drawBackTrackDLAnimated(animateSpeed+=increment, 3);
  } else if (dist <= 11) {
     drawBackTrackDLAnimated(animateSpeed+=increment, 2);
  } else {
     drawBackTrackDLAnimated(animateSpeed+=increment, 1);
  }
  
  //     glCallList(vtd_dl::backtrackDL);
    glPopMatrix();
	 glPushMatrix();
		if(mode == GL_RENDER)
			draw_shadow(3);
	 glPopMatrix();
  glPopMatrix();
}

void FastTower::step(float dt){

}

bool FastTower::upgrade(){
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
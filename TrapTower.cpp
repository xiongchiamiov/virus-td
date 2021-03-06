#include "TrapTower.h"
#include "constants.h"
#include "models.h"
#include "Particles.h"
#include "shadow.h"

namespace tr_tower{
  const int MAX_UPGRADES = 3;
  const int MAX_HP[MAX_UPGRADES] = {12, 16, 18};
  const int ATK[MAX_UPGRADES] = {1, 3, 5};
  const int ATK_DT[MAX_UPGRADES] = {3000, 3000, 3000}; //Milleseconds between attacks
  const float RANGE[MAX_UPGRADES] = {1.5, 1.5, 1.5};
  const int BUILD_TIME = 3000;
  char* SOUND = "media/sounds/big_laser2.wav";
}

using namespace tr_tower;

TrapTower::TrapTower(float inx, float iny, float inz, int gx, int gy):
   Tower(inx, iny, inz, gx, gy)/*, hp(MAX_HP), max_hp(MAX_HP), atk_dmg(ATK),
type(T_BASIC), build_time(BUILD_TIME), stage(0)*/
{
  hp = MAX_HP[0];
  max_hp = MAX_HP[0];
  ai.atk_dmg = ATK[0];
  ai.atk_dt = ATK_DT[0]; 
  ai.range = RANGE[0];
  type = T_TRAP;
  build_time = BUILD_TIME;
  stage = 0;
  sound = SOUND;
  ai.hasTarget = false;
  weapon = new Particles(0.2);
  weapon->setWeaponType(particle_texture[2]);
  weapon->setSpread(0.0);
  weapon->setDirection(1.0, 0.0, 1.0, false);
  weapon->setAoE(true, true);
  weapon->setSpeed(10.0);
  weapon->setCutOffs(8, 8, 8);
  weapon->reset(); // must call reset before animating to get latest values.
}

TrapTower::~TrapTower(void)
{
}

void TrapTower::draw(GLuint id, GLenum mode){
  glPushMatrix();
  setMaterial(Exp);
  glTranslatef(x, y, z);
  glPushMatrix();
     glPushMatrix();
        glTranslatef(-0.2, 0.25, 0.0);
        glScaled(0.15, 0.15, 0.15);
		if(mode == GL_RENDER)
			weapon->drawParticles();
     glPopMatrix();
   setMaterial(Black);
   glScalef(.5,.5,.5);
   if(mode == GL_SELECT)
	   glLoadName(id);
      
  double dist = sqrt((getX() - cam.getCamX()) * (getX() - cam.getCamX())
     + (getY() - cam.getCamY()) * (getY() - cam.getCamY())
     + (getZ() - cam.getCamZ()) * (getZ() - cam.getCamZ()));

  if (dist <= 8) {
     glCallList(vtd_dl::blkhatL3DL);
  } else if (dist <= 11) {
     glCallList(vtd_dl::blkhatL2DL);
  } else {
     glCallList(vtd_dl::blkhatL1DL);
  }
  
   //glutSolidTorus(0.2, 0.25, 10, 10);
  glPopMatrix();
	 glPushMatrix();
		if(mode == GL_RENDER)
			draw_shadow(6);
	 glPopMatrix();
  glPopMatrix();
}

void TrapTower::step(float dt){

}

bool TrapTower::shoot(){
  bool ret = false;
  std::list<Unit*>::iterator i;
  for(i = ai.targetList->begin(); i != ai.targetList->end(); ++i){
    if(!(*i)->isDead() && ai.range > ai.getDistance(**i)){
      (*i)->takeDamage(ai.atk_dmg);
      ret = true;
    }
  } 
  return ret;
}

bool TrapTower::upgrade(){
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
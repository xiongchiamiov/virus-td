#include "WallTower.h"
#include "constants.h"
#include "lighting.h"
#include "models.h"
#include "shadow.h"

namespace w_tower{
  const int MAX_UPGRADES = 3;
  const int MAX_HP[MAX_UPGRADES] = {30, 50, 70};
  const int ATK[MAX_UPGRADES] = {0, 0, 0};
  const int ATK_DT[MAX_UPGRADES] = {1000, 1000, 1000}; //Milleseconds between attacks
  const float RANGE[MAX_UPGRADES] = {0.0, 0.0, 0.0};
  const int BUILD_TIME = 3000;
  char* SOUND = "media/sounds/basic_t.mp3";
}
using namespace w_tower;

WallTower::WallTower(float inx, float iny, float inz, int gx, int gy):
Tower(inx, iny, inz, gx, gy)
{
  hp = MAX_HP[0];
  max_hp = MAX_HP[0];
  ai.atk_dmg = ATK[0];
  ai.atk_dt = ATK_DT[0]; 
  ai.range = RANGE[0];
  type = T_WALL;
  build_time = BUILD_TIME;
  stage = 0;
  sound = SOUND;
  weapon = new Particles(0.7);
  weapon->setDirection(0.0, 1.0, 0.0, false);
  weapon->setCutOffs(20, 9, 20);
  weapon->setSpread(9);
  weapon->reset();
}

WallTower::~WallTower(void)
{
  delete weapon;
}

void WallTower::draw(GLuint id, GLenum mode){
  glPushMatrix();
  glTranslatef(x, y, z);
     glPushMatrix();
        // Scale and orient model to fit grid
      //  glTranslatef(0.0, 0.50, 0.0);
        // Mini Tower Defense TBQH
      //  glScaled(0.75, 0.75, 0.75);
      //  glRotated(83, 0.0, 1.0, 0.0);
      //  glCallList(vtd_dl::shieldDL);
     //   glCallList(vtd_dl::lockDL);
	 if(mode == GL_SELECT) {
		 glLoadName(id);
		 glPushMatrix();
		 glScalef(1.0,0.5,1.0);
		 glTranslatef(0.0,0.6,0.0);
		 glutSolidCube(1.0f);
		 glPopMatrix();
	 }

     glPushMatrix();
        glTranslatef(-0.2, 0.25, 0.0);
        glScaled(0.15, 0.15, 0.15);
		if(mode == GL_RENDER)
			weapon->drawParticles();
     glPopMatrix();

    glPopMatrix();
	 glPushMatrix();
	//	draw_shadow(5);
	 glPopMatrix();
  glPopMatrix();
}

void WallTower::step(float dt){

}

bool WallTower::upgrade(){
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
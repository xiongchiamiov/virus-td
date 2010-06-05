#include "Tower.h"
#include "GameSounds.h"
#include "Projectile.h"

Tower::Tower(float inx, float iny, float inz, int gx, int gy):
GameObject(inx, iny, inz), grid_x(gx), grid_y(gy), ai(x, y, z)
{
  
}

Tower::~Tower(void)
{
}
bool Tower::shoot(){
  bool ret = ai.shoot();
  if(ret){
    gamesounds::playSound(sound, x, y, z);
  }
  return ret;
}
bool Tower::operator==(const Tower& other){ 
  return (this->grid_x == other.grid_x) && (this->grid_y == other.grid_y);
}
bool Tower::operator==(const g_elem& other){ 
  return (this->grid_x == other.x) && (this->grid_y == other.y);
}
void Tower::step(int dt){
  if(ai.last_atk <= ai.atk_dt){
    ai.last_atk += dt;
  }
  if(ai.atk_dt < ai.last_atk){
    if(shoot()){
      ai.last_atk = 0;
      //addProjectile(0.3, ai.target, x, y, z);
    }
  }
}

int Tower::getKill(){
  if(ai.hasKill){
    ai.hasKill = false;
    return ai.target->getValue();
  }
  return 0;
}

int Tower::takeDamage(int damage)
{
	hp = hp - damage;
	if(hp <= 0)
	{
		return 0;
	}
	else
	return hp;
}
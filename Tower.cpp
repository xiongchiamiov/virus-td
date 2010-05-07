#include "Tower.h"


Tower::Tower(float inx, float iny, float inz, int gx, int gy):
GameObject(inx, iny, inz), grid_x(gx), grid_y(gy), ai(x, y, z)
{
  
}

Tower::~Tower(void)
{
}
bool Tower::shoot(){
  return ai.shoot();
}
bool Tower::operator==(const Tower& other){ 
  return (this->grid_x == other.grid_x) && (this->grid_y == other.grid_y);
}
bool Tower::operator==(const g_elem& other){ 
  return (this->grid_x == other.x) && (this->grid_y == other.y);
}
void Tower::step(int dt){
  ai.last_atk += dt;
  if(ai.atk_dt < ai.last_atk){
    if(shoot()){
      ai.last_atk = 0;
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
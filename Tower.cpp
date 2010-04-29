#include "Tower.h"


Tower::Tower(float inx, float iny, float inz, int gx, int gy):
GameObject(inx, iny, inz), grid_x(gx), grid_y(gy), ai(x, y, z)
{
  
}

Tower::~Tower(void)
{
}
void Tower::shoot(){
  ai.shoot();
}
bool Tower::operator==(const Tower& other){ 
  return (this->grid_x == other.grid_x) && (this->grid_y == other.grid_y);
}
bool Tower::operator==(const g_elem& other){ 
  return (this->grid_x == other.x) && (this->grid_y == other.y);
}

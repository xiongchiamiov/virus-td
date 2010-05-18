#include "Unit.h"
#include "Tower.h"

float x_extents = 0.5*GRID_SIZE;
float z_extents = 0.5*GRID_SIZE;
class Tower;
Unit::Unit(float inx, float iny, float inz):
GameObject(inx, iny, inz), last_atk(0)
{
  foundGoal = false;
}

Unit::~Unit(void)
{
}

void Unit::attack(GameObject* other){
  if(other == NULL){
    return;
  }
  Tower *target = (Tower*)other;
  if(last_atk >= atk_dt){
    std::cout << target->takeDamage(atk_dmg) << std::endl;
  }
}
int Unit::takeDamage(int damage)
{
	hp = hp - damage;
	if(hp <= 0)
	{
		return 0;
	}
	else
	return hp;
}

void Unit::step(int dt) {
  if(last_atk <= atk_dt){
    last_atk += dt;
  }
	if(foundGoal)
		return;
	float nextX = 0;
	float nextZ = 0;
	float dirI = dir.getI();
	float dirK = dir.getK();
	float approx = 0.001;
	bool next = false;
	grid2loc(path.top(), &nextX, &nextZ);

	if(dirI < approx && dirI > -approx) {
		if((dirK >= 0 && z >= nextZ) ||
		   (dirK <= 0 && z <= nextZ))
		   next = true;
	} else if(dirK < approx && dirK > -approx) {
		if((dirI >= 0 && x >= nextX) ||
		   (dirI <= 0 && x <= nextX))
		   next = true;
	} else {
		if((dirI >= 0 && dirK >= 0 && x >= nextX && z >= nextZ) ||
		   (dirI <= 0 && dirK >= 0 && x <= nextX && z >= nextZ) ||
		   (dirI >= 0 && dirK <= 0 && x >= nextX && z <= nextZ) ||
		   (dirI <= 0 && dirK <= 0 && x <= nextX && z <= nextZ))
		   next = true;
	}
	
	//std::cout << dirI << " " << dirK << " " << x << " " << z << " " << nextX << " " << nextZ << " " << next << std::endl;
	if(next && !path.empty()) {
		path.pop();
		
		if(nextX == GOAL_X && nextZ == GOAL_Z)
			foundGoal = true;
		else {
			grid2loc(path.top(), &nextX, &nextZ);
			//std::cout << "next " << nextX << " " << nextZ << std::endl;
			dir.setVector(nextX - x, 0.0, nextZ - z);
			dir.normalize();
		}
	}

	x += speed * dt * dir.getI();
	y += speed * dt * dir.getJ();
	z += speed * dt * dir.getK();
}
float uXExt = 0.3;
float uZExt = 0.3;

inline bool checkBounds(float top, float bottom, float left, float right, float checkY, float checkX){
  return (top > checkY && bottom < checkY && left < checkX && right > checkX); 
}

bool Unit::checkCollison(GameObject* other){
  float uTop = z + uZExt,
        uBottom = z - uZExt,
        uLeft = x - uXExt,
        uRight = x + uXExt,
        tTop = other->getZ() + GRID_SIZE*2.0,
        tBottom = other->getZ() - GRID_SIZE*2.0,
        tLeft = other->getX() - GRID_SIZE*2.0,
        tRight = other->getX() + GRID_SIZE*2.0;
  
  return checkBounds(tTop, tBottom, tLeft, tRight, uTop, uLeft) || //Top left corner 
         checkBounds(tTop, tBottom, tLeft, tRight, uTop, uRight) || //Top right corner
         checkBounds(tTop, tBottom, tLeft, tRight, uBottom, uLeft) || //Bottom left corner
         checkBounds(tTop, tBottom, tLeft, tRight, uBottom, uRight); //Bottom right corner
}

//void Unit::moveToWaypoint(){
//}
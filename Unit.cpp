#include "Unit.h"

float x_extents = 0.5*GRID_SIZE;
float z_extents = 0.5*GRID_SIZE;

Unit::Unit(float inx, float iny, float inz):
GameObject(inx, iny, inz)
{
  foundGoal = false;
}

Unit::~Unit(void)
{
}

void Unit::attack(){
}
int Unit::takeDamage(int damage)
{
	hp = hp - damage;
	if(hp <= 0)
	{
		return(0);
	}
	else
	return(hp);
}

void Unit::step(int dt) {
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

bool Unit::checkCollison(GameObject* other){
  return false;
}

//void Unit::moveToWaypoint(){
//}
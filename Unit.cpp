#include "Unit.h"

Unit::Unit(float inx, float iny, float inz):
GameObject(inx, iny, inz)
{
  
}

Unit::~Unit(void)
{
}

void Unit::attack(){
}
int Unit::takeDamage(int damage)
{
	hp = hp;// - damage;
	if(hp <= 0)
	{
		return(0);
	}
	else
	return(hp);
}

void Unit::step(int dt) {
	float nextX;
	float nextZ;
	grid2loc(path.top(), &nextX, &nextZ);
	
	std::cout << "cur " << x << " " << z << " " << nextX << " " << nextZ << std::endl;
	if(abs(nextX - x) < 0.2 && abs(nextZ - z) < 0.2) {
		path.pop();
		grid2loc(path.top(), &nextX, &nextZ);
		std::cout << "next " << nextX << " " << nextZ << std::endl;
		dir.setVector(nextX - x, 0.0, nextZ - z);
		dir.normalize();
	}

	x += speed * dt * dir.getI();
	y += speed * dt * dir.getJ();
	z += speed * dt * dir.getK();
}

//void Unit::moveToWaypoint(){
//}
//UnitList::UnitList(){
//}
//
//UnitList::~UnitList(){
//}
//
//std::list<Unit*>::iterator UnitList::begin(){
//}
//
//std::list<Unit*>::iterator UnitList::end(){
//}
//
//void UnitList::remove(std::list<Unit*>::iterator& iter){
//}
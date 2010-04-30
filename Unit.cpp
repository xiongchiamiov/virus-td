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
	hp = hp - damage;
	if(hp <= 0)
	{
		return(0);
	}
	else
	return(hp);
}

void Unit::step(int dt) {
	int curX = 0;
	int curZ = 0;

	
	if(true) {

	} else {
		x += speed * dt * dir.getI();
		y += speed * dt * dir.getJ();
		z += speed * dt * dir.getK();
	}
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
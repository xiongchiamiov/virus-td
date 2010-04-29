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
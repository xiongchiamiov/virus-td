#include "Unit.h"

Unit::Unit(float inx, float iny, float inz, int gx, int gy):
GameObject(inx, iny, inz), grid_x(gx), grid_y(gy)/*, ai(x, y, z)*/
{
  
}

Unit::~Unit(void)
{
}

void Unit::attack(){
}

int Unit::takeDamage(int damage)
{
	int new_hp = hp - damage;
	if(new_hp <= 0)
	{
		
		return(0);
	}
	else
	return(new_hp);
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
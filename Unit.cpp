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
#include "BasicUnit.h"

namespace b_unit{
  const int MAX_HP = 10;
  const int ATK = 3;
  const float SPD = 0.5;
}
using namespace b_unit;

BasicUnit::BasicUnit(void)
{
  hp = MAX_HP;
  max_hp = MAX_HP;
  atk_dmg = ATK;
  speed = SPD;
  type = U_BASIC;
}

BasicUnit::~BasicUnit(void)
{
}

void BasicUnit::draw(){}

void BasicUnit::step(float dt){}
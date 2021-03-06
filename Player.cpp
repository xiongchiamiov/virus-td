#include "Player.h"
#include "GameSounds.h"
namespace vtd_player{
  const int START_LIVES = 5;
  const int START_INCOME = 10;
  const int START_RESOURCES = 15;//00000; /* originally 10, but 100000 for debug */
}
const int cleanup_dt = 500;
int last_cleanup = 0;

using namespace vtd_player;
Player::Player(void):
lives(START_LIVES), resources(START_RESOURCES), income(START_INCOME), uCooldown(0),
pGrid(GameGrid("maingrid.grid")), uai(pGrid, tList), opponent(this)
{
}

Player::~Player(void)
{
}

ReturnCode Player::placeTower(int x, int y, int towerID){
  Tower* nTower = NULL;
  int cost = 0;
  float wx = float(x)*GRID_SIZE*2.0 + GRID_SIZE, 
    wz = float(y)*GRID_SIZE*2.0 + GRID_SIZE;
  switch(towerID){
    case 17:
      nTower = new BasicTower(wx, 0.0, wz, x, y);
      cost = tower_cost::BASIC;
      break;
    case 16:
      nTower = new FreezeTower(wx, 0.0, wz, x, y);
      cost = tower_cost::FREEZE;
      break;
    case 15:
      nTower = new FastTower(wx, 0.0, wz, x, y);
      cost = tower_cost::FAST;
      break;
    case 14:
      nTower = new SlowTower(wx, 0.0, wz, x, y);
      cost = tower_cost::SLOW;
      break;
    case 13:
      nTower = new TrapTower(wx, 0.0, wz, x, y);
      cost = tower_cost::TRAP;
      break;
    case 12:
      nTower = new WallTower(wx, 0.0, wz, x, y);
      cost = tower_cost::WALL;
      break;
    case 11:
      break;
    case 10:
      break;
    case 9:
      break;
  }
  
  ReturnCode returnCode = (nTower == NULL) ? INVALID_TOWER
                        : (resources < cost) ? INSUFFICIENT_BYTES
                        : (!pGrid.setTower(x, y)) ? INVALID_LOCATION
                        : SUCCESS;
  if (returnCode == SUCCESS) {
    nTower->setEnemyUnitList(opponent->uai.uList);
    nTower->setProjectileManager(&projectiles);
    tList.push_back(nTower);
    pGrid.setTowerGrid(x, y, nTower);
    resources -= cost;
    opponent->uai.determineUnitsPaths();
  } else {
    delete nTower;
    gamesounds::playSound("media/sounds/buzzer.wav", 0.0, 0.0, 0.0);
  }
  
  return returnCode;
}

ReturnCode Player::spawnUnit(int unitID){
  Unit* nUnit = NULL;
  int cost, bonus;

  switch(unitID){
    case 8:
      nUnit = new FastUnit2(START_X, 0.0, START_Z);
      cost = unit_cost::FAST2;
      bonus = unit_bonus::FAST2;
      break;
    case 7:
      nUnit = new BasicUnit(START_X, 0.0, START_Z);
      cost = unit_cost::BASIC;
      bonus = unit_bonus::BASIC;
      break;
    case 6:
      nUnit = new FastUnit(START_X, 0.0, START_Z);
      cost = unit_cost::FAST;
      bonus = unit_bonus::FAST;
      break;
    case 5:
      nUnit = new StrongUnit(START_X, 0.0, START_Z);
      cost = unit_cost::STRONG;
      bonus = unit_bonus::STRONG;
      break;
    case 4:
      nUnit = new StrongUnit2(START_X, 0.0, START_Z);
      cost = unit_cost::STRONG2;
      bonus = unit_bonus::STRONG2;
      break;
    case 3:
      nUnit = new StrongUnit3(START_X, 0.0, START_Z);
      cost = unit_cost::STRONG3;
      bonus = unit_bonus::STRONG3;
      break;
    case 2:
      break;
    case 1:
      break;
    case 0:      
      nUnit = new BossUnit(START_X, 0.0, START_Z);
      cost = unit_cost::BOSS;
      bonus = unit_bonus::BOSS;
      break;
  }
  
  ReturnCode returnCode = (nUnit == NULL) ? INVALID_UNIT
                        : (resources < cost) ? INSUFFICIENT_BYTES
                        : (uCooldown > 0) ? NEED_COOLDOWN
                        : (uai.uList.size() > UNIT_MAX) ? UNIT_LIMIT_REACHED
                        : SUCCESS;
  if(returnCode == SUCCESS){
    uai.uList.push_back(nUnit);
    resources -= cost;
    income += bonus;
    uCooldown = UNIT_COOLDOWN;
    uai.determineUnitPath(nUnit);
  } else {
    delete nUnit;
  }
  
  return returnCode;
}

void Player::update(int dt){
  if(uCooldown > 0){
    uCooldown -= dt;
  }
  pGrid.update(dt);
  projectiles.stepProjectiles(dt);
  std::list<Unit*>::iterator i;
  std::list<Tower*>::iterator t;
  for(t = tList.begin(); t != tList.end(); ++t){
    (*t)->step(dt);
    int k =  (*t)->getKill();
    if(k){
      resources += k;
      Particles part(0.7);
      part.setAoE(true, true);
      part.setWeaponType((*t)->getWeaponType());
      Unit* dTarget = (*t)->getTarget();
      
      projectiles.addProjectile(&part, NULL, dTarget->getX(), dTarget->getY(), dTarget->getZ());
    }
  }
  for(t = tList.begin(); t != tList.end(); ++t){
    (*t)->retarget();
  }

  for(i = uai.uList.begin(); i != uai.uList.end(); ++i){
    (*i)->step(dt);
    if(!(*i)->hasPath()){
      Tower* targ = opponent->pGrid.checkCollision(*i);
      (*i)->attack(targ);
      if(targ != NULL && targ->isDead()){
        pGrid.destroyTower(targ->getGridX(), targ->getGridY());
        uai.determineUnitsPaths();
      }
    }
  }

  //Remove dead units
  while(delStack.size() > 0){
    delete delStack.top();
    delStack.pop();
  }
  //Get the new dead units
  last_cleanup += dt;
  if(last_cleanup > cleanup_dt){
    Tower* curT;
    Unit* cur;
    for(t = tList.begin(); t != tList.end(); ){
      curT = *t;
      if(curT->isDead()){
        pGrid.destroyTower(curT->getGridX(), curT->getGridY());
        delStack.push(curT);
        t = tList.erase(t);
      } else {
        ++t;
      }
    }
    for(i= uai.uList.begin(); i != uai.uList.end(); ){
      cur = *i;
      if(cur->isDead() || cur->foundGoal){
        delStack.push(cur);
        i = uai.uList.erase(i);
        if(cur->foundGoal){
          --opponent->lives;
        }
      } else {
        ++i;
      }
    }
    last_cleanup = 0;
  }
}

void Player::upgradeTower(int x, int y){
  Tower* t = pGrid.getTowerAt(x, y);
  int cost;
  if(t != NULL){
    switch(t->getType()){
    case T_BASIC:
      cost = tower_cost::BASIC;
      break;
    case T_FREEZE:
      cost = tower_cost::FREEZE;
      break;
    case T_FAST:
      cost = tower_cost::FAST;
      break;
    case T_SLOW:
      cost = tower_cost::SLOW;
      break;
    case T_TRAP:
      cost = tower_cost::TRAP;
      break;
    case T_WALL:
      cost = tower_cost::WALL;
      break;
    }
    if(resources >= cost && t->upgrade()){
      resources -= cost;
    }
  }
}

void Player::changeTowerMode(int x, int y, target_mode mode){
  Tower* t = pGrid.getTowerAt(x, y);
  if(t != NULL){
    t->setTargetMode(mode);
  }
}

void Player::destroyTower(int x, int y){
  pGrid.removeTower(x, y, tList);
  uai.determineUnitsPaths();
}

void Player::sellTower(int x, int y){
  Tower* t = pGrid.getTowerAt(x, y);
  int sellValue(0);
  if(t != NULL){
    switch(t->getType()){
      case T_BASIC:
        sellValue = tower_cost::BASIC;
        break;
      case T_FREEZE:
        sellValue = tower_cost::FREEZE;
        break;
      case T_FAST:
        sellValue = tower_cost::FAST;
        break;
      case T_SLOW:
        sellValue = tower_cost::SLOW;
        break;
      case T_TRAP:
        sellValue = tower_cost::TRAP;
        break;
      case T_WALL:
        sellValue = tower_cost::WALL;
        break;
    }
    sellValue = (sellValue * (t->getStage()+1))/2;
  }
  resources += sellValue;
  pGrid.removeTower(x, y, tList);
  uai.determineUnitsPaths();
}

void Player::draw(bool isPlacing){
  glPushMatrix();
  glTranslatef(pos.getX(), pos.getY(), pos.getZ());
  pGrid.draw(isPlacing, GL_RENDER);

  std::list<Unit*>::iterator p; 
  for(p = opponent->uai.uList.begin(); p != opponent->uai.uList.end(); ++p){
    if(!(*p)->isDead() && !cull(*p)){
      (*p)->draw();
    }
  }
  std::list<Tower*>::iterator i; 
  for(i = tList.begin(); i != tList.end(); ++i){
    if(!(*i)->isDead() && !cull(*i)){
      (*i)->draw();
    }
  }
  projectiles.drawProjectiles();
  glPopMatrix();
}

std::list<Tower*> Player::getTowerList()
{
	return this->tList;
}

bool Player::cull(GameObject* obj){
  MyVector temp(0.0, 0.0, 0.0, 
    obj->getX() + pos.getX(),
    obj->getY() + pos.getY(),
    obj->getZ() + pos.getZ());
  return !vfc::viewFrustumCull(vfc::planes, &temp);
}

int Player::getIncome(){
  return income;
}
int Player::getResources(){
  return resources;
}
int Player::getLives() {
	return lives;
}
MyVector Player::getPosition() {
	return pos;
}
int Player::calcResources(){
  resources += income;
  return resources;
}

void Player::setOpponent(Player* newOpp){
  opponent = newOpp;
  opponent->opponent = this;
  this->uai.setGrid(opponent->pGrid);
  opponent->uai.setGrid(pGrid);
  this->uai.setTowers(opponent->tList);
  opponent->uai.setTowers(tList);
}

void Player::reset(){
  lives = START_LIVES;
  resources = START_RESOURCES;
  income = START_INCOME;
  uCooldown = 0;
  uai.uList.clear();
  Tower* tPtr;
  while(!tList.empty()){
    tPtr = tList.front();
    destroyTower(tPtr->getGridX(), tPtr->getGridY());
  }
}

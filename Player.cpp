#include "Player.h"
namespace vtd_player{
  const int START_LIVES = 5;
  const int START_RESOURCES = 100000; /* originally 10, but 100000 for debug */
}
const int cleanup_dt = 500;
int last_cleanup = 0;

using namespace vtd_player;
Player::Player(void):
lives(START_LIVES), resources(START_RESOURCES), income(0),
uai(pGrid, tList), opponent(this)
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
    case 8:
      break;
  }
  
  ReturnCode returnCode = (nTower == NULL) ? INVALID_TOWER
                        : (resources < cost) ? INSUFFICIENT_BYTES
                        : (!pGrid.setTower(x, y)) ? INVALID_LOCATION
                        : SUCCESS;
  if (returnCode == SUCCESS) {
    nTower->setEnemyUnitList(opponent->uai.uList);
    tList.push_back(nTower);
    pGrid.setTowerGrid(x, y, nTower);
    resources -= cost;
    opponent->uai.determineUnitsPaths();
  } else {
    delete nTower;
  }
  
  return returnCode;
}

void Player::spawnUnit(int unitID){
  Unit* nUnit = NULL;
  int cost, bonus;

  switch(unitID){
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
      break;
    case 4:
      break;
    case 3:
      break;
    case 2:
      break;
    case 1:
      break;
    case 0:
      break;
  }
  if(nUnit != NULL && resources >= cost){
    uai.uList.push_back(nUnit);
    resources -= cost;
    income += bonus;
    uai.determineUnitsPaths();
  } else {
    delete nUnit;
  }
}

void Player::update(int dt){
  std::list<Unit*>::iterator i;
  std::list<Tower*>::iterator t;
  for(t = tList.begin(); t != tList.end(); ++t){
    (*t)->step(dt);
    resources += (*t)->getKill();
  }

  for(i = uai.uList.begin(); i != uai.uList.end(); ++i){
    (*i)->step(dt);
    if(!(*i)->hasPath()){
      Tower* targ = pGrid.checkCollision(*i);
      (*i)->attack(targ);
      if(targ != NULL && targ->isDead()){
        pGrid.destroyTower(targ->getGridX(), targ->getGridY());
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
          --lives;
        }
      } else {
        ++i;
      }
    }
    last_cleanup = 0;
  }
}

void Player::moveUnits(float dt)
{
  float xdir, zdir, trad, urad;
  float u_xmin,u_xmax,u_zmin,u_zmax;
  float t_xmin,t_xmax,t_zmin,t_zmax;
  zdir = dt;
  xdir = 0;
  trad = .5;
  urad = .5;
  std::list<Unit*>::iterator p;
  std::list<Tower*>::iterator t;
  for(p = uai.uList.begin(); p != uai.uList.end(); ++p)
  {
    u_xmin = ((*p)->getX()) - urad;
    u_xmax = ((*p)->getX()) + urad;
    u_zmin = ((*p)->getZ()) - urad;
    u_zmax = ((*p)->getZ()) + urad;
    bool collision = false;
    if(tList.empty())
    {
      //printf("grid heith = %d, u_xmax = %d\n", GRID_HEIGHT, u_xmax);
      if(u_zmax <= (GRID_HEIGHT/2))
      {
        (*p)->step(dt);
      }
    }
    else
    {
      for(t = tList.begin(); t != tList.end(); ++t)
      { 
        t_xmin = ((*t)->getX()) - trad;
        t_xmax = ((*t)->getX()) + trad;
        t_zmin = ((*t)->getZ()) - trad;
        t_zmax = ((*t)->getZ()) + trad;
        if((u_zmax > t_zmin) && (u_xmax > t_xmin) && (u_xmin < t_xmax) && (u_zmin < t_zmax))
        {
          collision = true;
          break;
        }
        //else if(()) // check for collisions along other paths, will implement, once object has xmin,ect.
        else
        {
          collision = false;
        }
      }
      if(!collision)
      {
        if(u_zmax <= (GRID_HEIGHT/2))
        {
          (*p)->step(dt);

        }
      }
    }
  }	
}

void Player::upgradeTower(){
}

void Player::destroyTower(int x, int y){
  pGrid.removeTower(x, y, tList);
  uai.determineUnitsPaths();
}

void Player::draw(){
  glPushMatrix();
  glTranslatef(-GRID_SIZE*float(GRID_WIDTH) + GRID_SIZE, 0.0, -GRID_SIZE*float(GRID_HEIGHT) + GRID_SIZE);
  pGrid.draw();
  std::list<Tower*>::iterator i; 
  for(i = tList.begin(); i != tList.end(); ++i){
    if(!(*i)->isDead()){
      (*i)->draw();
    }
  }

  //glScalef(-1.0, 1.0, -1.0);
  //glTranslatef(0.0, 0.0, GRID_SIZE*(GRID_HEIGHT + 4)*2.0);
  std::list<Unit*>::iterator p; 
  for(p = opponent->uai.uList.begin(); p != opponent->uai.uList.end(); ++p){
    if(!(*p)->isDead()){
      (*p)->draw();
      //(*p)->attack( pGrid.checkCollision(*p)); ){
        /*std::cout << "Hit" << std::endl;
        setMaterial(RedFlat);
        glPushMatrix();
        glTranslatef((*p)->getX(), (*p)->getY(), (*p)->getZ());
        glutSolidSphere(GRID_SIZE*3.0, 4, 4); 
        glPopMatrix();
      }*/
    }
  }
  glPopMatrix();
}

int Player::getIncome(){
  return income;
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

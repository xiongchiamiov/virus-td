#include "Player.h"
namespace vtd_player{
  const int START_LIVES = 5;
  const int START_RESOURCES = 10;
}
const int cleanup_dt = 3000;
int last_cleanup = 0;

using namespace vtd_player;
Player::Player(void):
lives(START_LIVES), resources(START_RESOURCES), income(0),uai(pGrid)
{
}

Player::~Player(void)
{
}

void Player::placeTower(int x, int y, int towerID){
  if(pGrid.setTower(x, y)){
    if (towerID == 17) {
      tList.push_back(new BasicTower(float(x)*GRID_SIZE*2.0 + GRID_SIZE, 
                                     0.0, 
                                     float(y)*GRID_SIZE*2.0 + GRID_SIZE, 
                                     x, y));
    } else if (towerID == 16) {
      tList.push_back(new FreezeTower(float(x)*GRID_SIZE*2.0 + GRID_SIZE, 
                                     0.0, 
                                     float(y)*GRID_SIZE*2.0 + GRID_SIZE, 
                                     x, y));
    } else if (towerID == 15) {
      tList.push_back(new FastTower(float(x)*GRID_SIZE*2.0 + GRID_SIZE, 
                                     0.0, 
                                     float(y)*GRID_SIZE*2.0 + GRID_SIZE, 
                                     x, y));
    } else if (towerID == 14) {
      tList.push_back(new SlowTower(float(x)*GRID_SIZE*2.0 + GRID_SIZE, 
                                     0.0, 
                                     float(y)*GRID_SIZE*2.0 + GRID_SIZE, 
                                     x, y));
    } else if (towerID == 13) {
      tList.push_back(new TrapTower(float(x)*GRID_SIZE*2.0 + GRID_SIZE, 
                                     0.0, 
                                     float(y)*GRID_SIZE*2.0 + GRID_SIZE, 
                                     x, y));
    } else if (towerID == 12) {
      tList.push_back(new WallTower(float(x)*GRID_SIZE*2.0 + GRID_SIZE, 
                                     0.0, 
                                     float(y)*GRID_SIZE*2.0 + GRID_SIZE, 
                                     x, y));
    } else if (towerID == 11) {
       
    } else if (towerID == 10) {
       
    } else if (towerID == 9) {
       
    } else if (towerID == 8) {
       
    }
    tList.back()->setEnemyUnitList(uai.uList);
  }
  uai.determineUnitsPaths();
}

void Player::spawnUnit(int unitID){

  if (unitID == 7) {
    uai.uList.push_back(new BasicUnit(0.0,//GRID_WIDTH*GRID_SIZE, 
      0.0, 
      0.0//-4*GRID_SIZE*2.0
	  ));

  } else if (unitID == 6) {

  } else if (unitID == 5) {

  } else if (unitID == 4) {

  } else if (unitID == 3) {

  } else if (unitID == 2) {

  } else if (unitID == 1) {

  } else if (unitID == 0) {

  }
  uai.determineUnitsPaths();
}

void Player::update(int dt){
  moveUnits(dt);
  std::list<Tower*>::iterator t;
  for(t = tList.begin(); t != tList.end(); ++t){
    (*t)->step(dt);
  }

  //Remove dead units
  while(delStack.size() > 0){
    delete delStack.top();
    delStack.pop();
  }
  //Get the new dead units
  last_cleanup += dt;
  if(last_cleanup > cleanup_dt){
    std::list<Unit*>::iterator i;
    Unit* cur;
    for(i = uai.uList.begin(); i != uai.uList.end(); ){
      cur = *i;
      if(cur->isDead()){
        delStack.push(cur);
        i = uai.uList.erase(i);
      } else {
        ++i;
      }
    }
    lastCleanup = 0;
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
    (*i)->draw();
  }
  
  std::list<Unit*>::iterator p; 
  for(p = uai.uList.begin(); p != uai.uList.end(); ++p){
    if(!(*p)->isDead()){
      (*p)->draw();
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
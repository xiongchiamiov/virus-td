#include "Player.h"

Player::Player(void)
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
  }
}

void Player::spawnUnit(int unitID){

  if (unitID == 7) {
    uList.push_back(new BasicUnit(GRID_WIDTH*GRID_SIZE, 
      0.0, 
      -4*GRID_SIZE*2.0));

  } else if (unitID == 6) {

  } else if (unitID == 5) {

  } else if (unitID == 4) {

  } else if (unitID == 3) {

  } else if (unitID == 2) {

  } else if (unitID == 1) {

  } else if (unitID == 0) {

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
  for(p = uList.begin(); p != uList.end(); ++p)
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
  for(p = uList.begin(); p != uList.end(); ++p){
    (*p)->draw();
  }
  glPopMatrix();
}
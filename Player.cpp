#include "Player.h"

Player::Player(void)
{
}

Player::~Player(void)
{
}

void Player::placeTower(int x, int y){
  if(pGrid.setTower(x, y)){
    tList.push_back(new BasicTower(float(x)*GRID_SIZE*2.0 + GRID_SIZE, 
                                   0.0, 
                                   float(y)*GRID_SIZE*2.0 + GRID_SIZE, 
                                   x, y));
  }
}

void Player::spawnUnit(){
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
  glPopMatrix();
}
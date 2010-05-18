#include "GameGrid.h"

GameGrid::GameGrid(void):
x(0.0), y(0.0)
{
  //grid = new bool[16][32];
  for(int i = 0; i < GRID_WIDTH; ++i){
    for(int j = 0; j < GRID_HEIGHT; ++j){
      grid[i][j] = true;
      tGrid[i][j] = NULL;
    }
  }
}

GameGrid::~GameGrid(void)
{
  //delete[] grid;
}

void GameGrid::draw(){
  glPushMatrix();
  glNormal3f(0.0, 1.0, 0.0);
  float posX = 0.0;
  float posZ = 0.0;
  for(int i = 0; i < GRID_WIDTH; i++){
    for(int j = 0; j < GRID_HEIGHT; j++){
      if(grid[i][j]){
        glLineWidth(2.0);
        glColor3f(0.3, 0.7, 0.3);
        setMaterial(Exp);
        glBegin(GL_POLYGON);{
          glVertex3f(posX - GRID_SIZE, 0.0, posZ - GRID_SIZE);
          glVertex3f(posX - GRID_SIZE, 0.0, posZ + GRID_SIZE);
          glVertex3f(posX + GRID_SIZE, 0.0, posZ + GRID_SIZE);
        }
        glEnd();
        glBegin(GL_POLYGON);{
          glVertex3f(posX + GRID_SIZE, 0.0, posZ + GRID_SIZE);
          glVertex3f(posX + GRID_SIZE, 0.0, posZ - GRID_SIZE);
          glVertex3f(posX - GRID_SIZE, 0.0, posZ - GRID_SIZE);
        }
        glEnd();
        setMaterial(Teal);
        glColor3f(0.3, 0.7, 0.7);
        glBegin(GL_LINE_LOOP);{
          glVertex3f(posX - GRID_SIZE, 0.001, posZ - GRID_SIZE);
          glVertex3f(posX - GRID_SIZE, 0.001, posZ + GRID_SIZE);
          glVertex3f(posX + GRID_SIZE, 0.001, posZ + GRID_SIZE);
        }
        glEnd();
        glBegin(GL_LINE_LOOP);{
          glVertex3f(posX + GRID_SIZE, 0.001, posZ + GRID_SIZE);
          glVertex3f(posX + GRID_SIZE, 0.001, posZ - GRID_SIZE);
          glVertex3f(posX - GRID_SIZE, 0.001, posZ - GRID_SIZE);
        }
        glEnd();
      }
      posZ += GRID_SIZE*2.0;
    }
    posZ = 0.0;
    posX += GRID_SIZE*2.0;
  }
  glPopMatrix();
}

bool GameGrid::setTower(int x, int y){
  bool retVal;
  if(x < GRID_WIDTH - 1  && x >= 0 &&
    y < GRID_HEIGHT - 1 && y >= 0){
      if(retVal = grid[x][y] && grid[x + 1][y] &&//Tricky, remember the assignment
                  grid[x + 1][y + 1] && grid[x][y + 1]){
        grid[x][y] = false;
        grid[x + 1][y] = false;
        grid[x + 1][y + 1] = false;
        grid[x][y + 1] = false;
      }

      return retVal;
  }
  return false;
}

void GameGrid::setTowerGrid(int x, int y, Tower* tPtr){
  std::cout << "Tower set at " << x << " " << y << std::endl;
  if(tPtr != NULL){
    std::cout << "Tower not null" << std::endl;
  } else {
    std::cout << "Tower null" << std::endl;
  }
  if(x < GRID_WIDTH - 1  && x >= 0 &&
    y < GRID_HEIGHT - 1 && y >= 0){
      tGrid[x][y] = tPtr;
      tGrid[x + 1][y] = tPtr;
      tGrid[x + 1][y + 1] = tPtr;
      tGrid[x][y + 1] = tPtr;
  }
  if(tGrid[x][y] != tPtr ||
      tGrid[x + 1][y] != tPtr ||
      tGrid[x + 1][y + 1] != tPtr ||
      tGrid[x][y + 1] != tPtr){
        std::cout << "Something's wrong" << std::endl;
  }
}

bool GameGrid::removeTower(int x, int y, std::list<Tower*>& towers){
  std::list<Tower*>::iterator i;
  g_elem t(x, y);
  for(i = towers.begin(); i != towers.end(); ++i){
    if( *(*i) == t){
      grid[x][y] = true; 
      grid[x + 1][y] = true;
      grid[x + 1][y + 1] = true;
      grid[x][y + 1] = true;
      tGrid[x][y] = NULL;
      tGrid[x + 1][y] = NULL;
      tGrid[x + 1][y + 1] = NULL;
      tGrid[x][y + 1] = NULL;
      delete (*i); 
      towers.erase(i);
      return true;
    }
  }
  return false;
}
bool GameGrid::destroyTower(int x, int y){
  if(x >= 0 && x < GRID_WIDTH - 1 &&
    y >= 0 && y < GRID_HEIGHT - 1){
    grid[x][y] = true; 
    grid[x + 1][y] = true;
    grid[x + 1][y + 1] = true;
    grid[x][y + 1] = true;
    tGrid[x][y] = NULL;
    tGrid[x + 1][y] = NULL;
    tGrid[x + 1][y + 1] = NULL;
    tGrid[x][y + 1] = NULL;
    return true;
  }
  return false;
}

bool GameGrid::setUnit(int x, int y){
  bool retVal;
  if(x < GRID_WIDTH - 1  && x >= 0 &&
    y < GRID_HEIGHT - 1 && y >= 0){
      retVal = grid[x][y] && grid[x + 1][y] &&
                  grid[x + 1][y + 1] && grid[x][y + 1];

      return retVal;
  }
  return false;
}

bool GameGrid::isWall(g_elem cur) {
	if(cur.x >= GRID_WIDTH || cur.x < 0 || cur.y >= GRID_HEIGHT + 8 || cur.y < 0)
		return true;
	else if(cur.y < 4 || cur.y > 35)
		return false;
	else
		return !grid[cur.x][cur.y - 4];
}

Tower* GameGrid::checkCollision(Unit* unit){
  Tower* retTower = NULL;
  g_elem spot = loc2grid(unit->getX(), unit->getZ());
  spot.y -= 4;
  if(unit->dir.getK() < 0.0 && spot.y > 0){
    retTower = tGrid[spot.x][spot.y - 1];
  }else if(spot.y < GRID_HEIGHT - 1 && retTower == NULL){
    retTower = tGrid[spot.x][spot.y + 1];
  }
  if(unit->dir.getI() < 0.0 && spot.x > 0 && retTower == NULL){
    retTower = tGrid[spot.x - 1][spot.y]; 
  } else if(spot.x < GRID_WIDTH - 1 && retTower == NULL){
    retTower = tGrid[spot.x + 1][spot.y];
  }
  if(retTower != NULL && !unit->checkCollison(retTower)){
    retTower = NULL;
  }
  return retTower;
}
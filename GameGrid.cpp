#include "GameGrid.h"
const int GRID_WIDTH = 16;
const int GRID_HEIGHT = 32;
const float GRID_SIZE = 0.25;
GameGrid::GameGrid(void):
x(0.0), y(0.0)
{
  //grid = new bool[16][32];
  for(int i = 0; i < GRID_WIDTH; ++i){
    for(int j = 0; j < GRID_HEIGHT; ++j){
      grid[i][j] = true;
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
  float gSize = 0.25;
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

bool GameGrid::removeTower(int x, int y, std::list<Tower*>& towers){
  std::list<Tower*>::iterator i;
  g_elem t(x, y);
  for(i = towers.begin(); i != towers.end(); ++i){
    if( *(*i) == t){
      grid[x][y] = true; 
      grid[x + 1][y] = true;
      grid[x + 1][y + 1] = true;
      grid[x][y + 1] = true;
      delete (*i); 
      towers.erase(i);
      return true;
    }
  }
  return false;
}

bool GameGrid::setUnit(int x, int y){
  bool retVal;
  if(x < GRID_WIDTH - 1  && x >= 0 &&
    y < GRID_HEIGHT - 1 && y >= 0){
      retVal = grid[x][y] && grid[x + 1][y] &&//Tricky, remember the assignment
                  grid[x + 1][y + 1] && grid[x][y + 1];

      return retVal;
  }
  return false;
}

bool GameGrid::isWall(g_elem cur) {
	if(cur.x >= GRID_WIDTH || cur.x < 0 || cur.y >= GRID_HEIGHT || cur.y < 0)
		return true;
	else
		return grid[cur.x][cur.y];
}
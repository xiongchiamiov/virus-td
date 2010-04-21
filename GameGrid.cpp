#include "GameGrid.h"
materialStruct RedFlat = {
  {0.3, 0.0, 0.0, 1.0},
  {0.9, 0.0, 0.0, 1.0},
  {0.0, 0.0, 0.0, 1.0},
  {0.0}
};

materialStruct GreenShiny = {
  {0.0, 0.3, 0.0, 1.0},
  {0.0, 0.9, 0.0, 1.0},
  {0.2, 1.0, 0.2, 1.0},
  {8.0}
};

materialStruct Exp = {
  {0.0, 0.0, 0.5, 1.0}, 
  {0.2, 0.2, 0.7, 1.0},
  {0.6, 0.4, 0.9, 1.0},
  {120.0}
};
//materialStruct Exp2 = {
//  {1.0, 0.0, 0.0, 1.0}, 
//  {0.2, 1.0, 0.2, 1.0},
//  {0.0, 0.2, 1.0, 1.0},
//  {20.0}
//};
materialStruct Grey = {
  {0.2, 0.2, 0.2, 1.0}, 
  {0.2, 0.2, 0.2, 1.0},
  {0.3, 0.3, 0.3, 1.0},
  {2.0}
};
materialStruct Black = {
  {0.08, 0.08, 0.08, 1.0}, 
  {0.08, 0.08, 0.08, 1.0},
  {0.08, 0.08, 0.08, 1.0},
  {0.0}
};
materialStruct Teal = {
  {0.15, 0.3, 0.33, 1.0}, 
  {0.5, 0.8, 0.89, 1.0},
  {0.4, 0.87, 0.95, 1.0},
  {3.0}
};
materialStruct Purple = {
  {0.4, 0.1, 0.4, 1.0}, 
  {0.5, 0.6, 0.05, 1.0},
  {0.8, 0.8, 0.2, 1.0},
  {4.0}
};
materialStruct Fuschia = {
  {0.7, 0.4, 0.55, 1.0}, 
  {0.8, 0.3, 0.7, 1.0},
  {0.9, 0.5, 0.9, 1.0},
  {3.0}
};
materialStruct FieryOrange = {
  {0.43, 0.2, 0.0, 1.0}, 
  {0.73, 0.36, 0.3, 1.0},
  {0.93, 0.45, 0.1, 1.0},
  {3.0}
};
materialStruct White = {
  {1.0, 1.0, 1.0, 1.0}, 
  {1.0, 1.0, 1.0, 1.0},
  {1.0, 1.0, 1.0, 1.0},
  {0.0}
};

GameGrid::GameGrid(void):
x(0.0), y(0.0)
{
  for(int i = 0; i < GRID_WIDTH; ++i){
    for(int j = 0; j < GRID_HEIGHT; ++j){
      grid[i][j] = true;
    }
  }
}

GameGrid::~GameGrid(void)
{
}

void GameGrid::draw(){
  glPushMatrix();
  glNormal3f(0.0, 1.0, 0.0);
  float gSize = 0.25;
  float posX = 0.0;
  float posZ = 0.0;
  glTranslatef(-GRID_SIZE*float(GRID_WIDTH) + GRID_SIZE, 0.0, -GRID_SIZE*float(GRID_HEIGHT) + GRID_SIZE);
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

bool GameGrid::removeTower(int x, int y, std::list<g_elem>& towers){
  std::list<g_elem>::iterator i = towers.begin();
  g_elem rTower(x, y);
  while(i != towers.end()){
    if(*i == rTower){
      grid[x][y] = true; 
      grid[x + 1][y] = true;
      grid[x + 1][y + 1] = true;
      grid[x][y + 1] = true;
      towers.erase(i);
      return true;
    } else {
      ++i;
    }
  }

  return false;
}
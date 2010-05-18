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

GameGrid::GameGrid(char *filename):
x(0.0), y(0.0)
{
	std::ifstream file;
	file.open(filename);
	if(file.is_open())
	{
		for(int j = 0; j < GRID_HEIGHT; ++j){
			for(int i = 0; i < GRID_WIDTH; ++i){
				char val;
				do {
					file.read(&val,sizeof(char));
				}
				while (val == '\n');
				val = val-48; //Convert to # values
				if(val == 0)
					grid[i][j] = true;
				else
					grid[i][j] = false;
				tGrid[i][j] = NULL;
			}
		}
		file.close();
		createFractals();
		printf("Loaded grid file\n");
	}
	else
	{
		printf("Error loading grid file\n");
		//grid = new bool[16][32];
		for(int i = 0; i < GRID_WIDTH; ++i){
			for(int j = 0; j < GRID_HEIGHT; ++j){
				grid[i][j] = true;
				tGrid[i][j] = NULL;
			}
		}
	}
}

int my_test = 1;
void GameGrid::createFractals()
{
	//int c_val[G_WIDTH][G_HEIGHT];
	bool assigned[G_WIDTH][G_HEIGHT];
	int tests[G_WIDTH][G_HEIGHT];
	//Initial pass to assign corner values
	for(int j = 0; j < GRID_HEIGHT; ++j){
		for(int i = 0; i < GRID_WIDTH; ++i){
			//c_val[i][j] = 0;
			assigned[i][j] = false;
			tests[i][j] = 0;
			/*if(grid[i][j] != true){
				//Check the left for open space
				if(i-1 < 0 || grid[i-1][j] == true)
					c_val[i][j] = c_val[i][j] | G_L;
				//Check the right for open space
				if(i+1 >= G_WIDTH || grid[i+1][j] == true)
					c_val[i][j] = c_val[i][j] | G_R;
				//Check the top for open space
				if(j-1 < 0 || grid[i][j-1] == true)
					c_val[i][j] = c_val[i][j] | G_T;
				//Check the bottom for open space
				if(j+1 >= G_HEIGHT || grid[i][j+1] == true)
					c_val[i][j] = c_val[i][j] | G_B;
			}*/
		}
	}
	//Now group the empty spots together
	for(int j = 0; j < GRID_HEIGHT; ++j){
		for(int i = 0; i < GRID_WIDTH; ++i){
			if(grid[i][j] != true && assigned[i][j] != true) {
				//Create a new fractal set
				int r = i + 1;
				int b = j + 1;
				assigned[i][j] = true;
				while(r < GRID_WIDTH && grid[r][j] != true && assigned[r][j] != true) {
					assigned[r][j] = true;
					r++;
				}
				r--;
				bool line_clear = true;
				while(b < GRID_HEIGHT && line_clear == true) {
					for(int x = i; x <= r; x++) {
						if(grid[x][b] == true || assigned[x][b] == true) {
							line_clear = false;
							break;
						}
					}
					if(line_clear == true) {
						for(int x = i; x <= r; x++) {
							assigned[x][b] = true;
						}
						b++;
					}
				}
				b--;
				for(int u = i; u <= r; u++)
					for(int v = j; v <= b; v++)
						tests[u][v] = my_test;
				my_test++;
				FractalSet *f_s = new FractalSet(i,r,j,b);
				f_sets.push_back(f_s);
			}
		}
	}

	std::list<FractalSet*>::iterator i;
	for(i = f_sets.begin(); i != f_sets.end(); ++i){
		
	}

	//Print out the setup
	for(int j = 0; j < GRID_HEIGHT; ++j){
		for(int i = 0; i < GRID_WIDTH; ++i){
			printf("%1d",tests[i][j]);
		}
		printf("\n");
	}
}

FractalSet::FractalSet(int s_i,int e_i,int s_j,int e_j):
		start_i(s_i),end_i(e_i),start_j(s_j),end_j(e_j)
{
	int h_cnt = FRACTAL_DEPTH * ((e_i-s_i)+1);
	int v_cnt = FRACTAL_DEPTH * ((e_j-s_j)+1);
	for(int i = 0; i < h_cnt+1; ++i) {
		zVals.push_back(std::vector<GLfloat>());
		for(int j = 0; j < v_cnt+1; ++j)
			zVals[i].push_back(0.0);
	}
	int start_i = 1;
	h_cnt -= 2;
	v_cnt -= 2;
	createFractals(start_i,h_cnt,v_cnt);
}

void FractalSet::createFractals(int start_i, int h_cnt, int v_cnt)
{

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
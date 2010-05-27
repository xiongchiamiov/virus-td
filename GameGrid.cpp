#include "GameGrid.h"

const int FRACTAL_DEPTH = 2;
const float FRACTAL_VAR = 0.75;
const int BOUNDRY_SPAWN_RATE = 350;
const float BOUNDRY_HEIGHT = 0.8;

GameGrid::GameGrid(void):
x(0.0), y(0.0), boundry_cntdown(BOUNDRY_SPAWN_RATE)
{
	bound_lines.insert(bound_lines.begin(),0.0);
	gridColor = PlayerGrid;
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
x(0.0), y(0.0), boundry_cntdown(BOUNDRY_SPAWN_RATE)
{
	//bound_lines.push_front(0.0);
	bound_lines.insert(bound_lines.begin(),0.0);
	//Set the grid's color
	gridColor = PlayerGrid;

	if(!RAND_SEEDED){
		srand(time(NULL));
		RAND_SEEDED = true;
	}
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
				while (val == '\n' || val == '\r');
				val = val-48; //Convert to # values
				if(val == 0) {
					grid[i][j] = true;
					oGrid[i][j] = true;
					frac[i][j] = false;
				}
				else {
					grid[i][j] = false;
					oGrid[i][j] = false;
					frac[i][j] = true;
				}
				tGrid[i][j] = NULL;
			}
		}
		file.close();
		createFractals();
		printf("Loaded grid file\n");
	}
	else
	{
		printf("Error loading grid file: %s\n", filename);
		//grid = new bool[16][32];
		for(int i = 0; i < GRID_WIDTH; ++i){
			for(int j = 0; j < GRID_HEIGHT; ++j){
				grid[i][j] = true;
				oGrid[i][j] = true;
				tGrid[i][j] = NULL;
			}
		}
	}
}

void GameGrid::initialize()
{
	//grid_text = LoadTexture("grid.bmp");
}

void GameGrid::createFractals()
{
	bool assigned[G_WIDTH][G_HEIGHT];
	//Initial pass to assign corner values
	for(int j = 0; j < GRID_HEIGHT; ++j){
		for(int i = 0; i < GRID_WIDTH; ++i){
			assigned[i][j] = false;
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
				FractalSet *f_s = new FractalSet(i,r,j,b);
				f_sets.push_back(f_s);
			}
		}
	}

	/*std::list<FractalSet*>::iterator i;
	for(i = f_sets.begin(); i != f_sets.end(); ++i){
		
	}*/

	//Print out the setup
	/*for(int j = 0; j < GRID_HEIGHT; ++j){
		for(int i = 0; i < GRID_WIDTH; ++i){
			printf("%1d",tests[i][j]);
		}
		printf("\n");
	}*/
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
	/*for(int y = 0; y < zVals[0].size(); y++) {
		for(int x = 0; x < zVals.size(); x++)
			printf("%2.3f ",zVals[x][y]);
		printf("\n");
	}*/
}

void FractalSet::createFractals(int start_i, int h_cnt, int v_cnt)
{
	GLfloat val;
	if(start_i % 2 == 1) {
		if(start_i != 1)
			val =  this->zVals[start_i-1][start_i-1] + (FRACTAL_VAR * (2.0*((float)rand()/RAND_MAX) - 1.0));
		else{
			float v = ((float)rand()/RAND_MAX);
			if(v < 0.5)
				val = 0.5; //+ FRACTAL_VAR * ((float)rand()/RAND_MAX);
			else
				val = -0.5;// + FRACTAL_VAR * ((float)rand()/RAND_MAX);
		}
	}
	else
		val = this->zVals[start_i-1][start_i-1];
	for(int x = start_i; x <= (start_i+h_cnt) && h_cnt > 0; ++x)
		this->zVals[x][start_i] = zVals[x][start_i + v_cnt] = val;
	for(int y = start_i; y <= (start_i + v_cnt) && v_cnt > 0; ++y)
		this->zVals[start_i][y] = zVals[start_i + h_cnt][y] = val;
	if(v_cnt == 0 && h_cnt == 0)
		this->zVals[start_i][start_i] = val;
	if(v_cnt > 0 && h_cnt > 0) {
		v_cnt -= 2;
		h_cnt -= 2;
		start_i++;
		createFractals(start_i,h_cnt,v_cnt);
	}
}

void normalize(float v[3]) {
   // normalize v[] and return the result in v[]
   // from OpenGL Programming Guide, p. 58
   GLfloat d = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
   if (d == 0.0) {
      printf("zero length vector");
      return;
   }
   v[0] = v[0]/d; v[1] = v[1]/d; v[2] = v[2]/d;
}

void normCrossProd(float v1[3], float v2[3], float out[3]) {
   // cross v1[] and v2[] and return the result in out[]
   // from OpenGL Programming Guide, p. 58
   out[0] = v1[1]*v2[2] - v1[2]*v2[1];
   out[1] = v1[2]*v2[0] - v1[0]*v2[2];
   out[2] = v1[0]*v2[1] - v1[1]*v2[0];
   normalize(out);
}

void FractalSet::draw()
{
	glPushMatrix();
	setMaterial(Grid);
	float v1[3];
	float v2[3];
	float n[3];
	GLfloat inc = ((float)1/FRACTAL_DEPTH) * GRID_SIZE;
	glTranslatef(0.0,0.0,this->start_j * GRID_SIZE * 2.0 - inc);
	int x_size = zVals.size() - 1;
	int y_size = zVals[0].size() - 1;

	for(int y = 0; y < y_size; ++y) {
		glPushMatrix();
		glTranslatef(this->start_i* GRID_SIZE * 2.0 - inc,0.0,0.0);
		for(int x = 0; x < x_size; ++x) {
			if((x < x_size/2 && y < y_size/2) || (x >= x_size/2 && y >= y_size/2)) {
				v1[0] = 1.0 - 0.0;
				v1[1] = zVals[x+1][y+1] - zVals[x][y];
				v1[2] = 1.0 - 0.0;

				v2[0] = 1.0 - 0.0;
				v2[1] = zVals[x+1][y+1] - zVals[x][y+1];
				v2[2] = 0.0;				
				normCrossProd(v1,v2,n);
				glNormal3f(n[0], n[1], n[2]);
				glBegin(GL_TRIANGLES);
				glVertex3f(-inc, zVals[x][y],-inc);
				glVertex3f(-inc, zVals[x][y+1],inc);
				glVertex3f(inc, zVals[x+1][y+1],inc);
				glEnd();

				v1[0] = 1.0 - 0.0;
				v1[1] = zVals[x+1][y+1] - zVals[x][y];
				v1[2] = 1.0 - 0.0;

				v2[0] = 1.0 - 0.0;
				v2[1] = zVals[x+1][y] - zVals[x][y];
				v2[2] = 0.0 - 0.0;				
				normCrossProd(v1,v2,n);
				glNormal3f(n[0], n[1], n[2]);
				glBegin(GL_TRIANGLES);
				glVertex3f(inc, zVals[x+1][y+1], inc);
				glVertex3f(inc, zVals[x+1][y], -inc);
				glVertex3f(-inc, zVals[x][y], -inc);
				glEnd();
			}
			else {
				v1[0] = 1.0 - 0.0;
				v1[1] = zVals[x+1][y+1] - zVals[x][y];
				v1[2] = 1.0 - 0.0;

				v2[0] = 1.0 - 0.0;
				v2[1] = zVals[x+1][y+1] - zVals[x][y+1];
				v2[2] = 0.0;				
				normCrossProd(v1,v2,n);
				glNormal3f(n[0], n[1], n[2]);
				glBegin(GL_TRIANGLES);
				glVertex3f(-inc, zVals[x][y], -inc);
				glVertex3f(-inc, zVals[x][y+1], inc);
				glVertex3f(inc, zVals[x+1][y], -inc);
				glEnd();


				v1[0] = 1.0 - 0.0;
				v1[1] = zVals[x+1][y+1] - zVals[x][y];
				v1[2] = 1.0 - 0.0;

				v2[0] = 1.0 - 0.0;
				v2[1] = zVals[x+1][y] - zVals[x][y];
				v2[2] = 0.0 - 0.0;				
				normCrossProd(v1,v2,n);
				glNormal3f(n[0], n[1], n[2]);
				glBegin(GL_TRIANGLES);
				glVertex3f(inc, zVals[x+1][y], -inc);
				glVertex3f(-inc, zVals[x][y+1], inc);
				glVertex3f(inc, zVals[x+1][y+1],inc);
				glEnd();
			}
			glTranslatef(2.0*inc,0.0,0.0);
		}
		glPopMatrix();
		glTranslatef(0.0,0.0,2.0*inc);
	}

	glPopMatrix();
}

void GameGrid::draw(){
  glPushMatrix();
  glNormal3f(0.0, 1.0, 0.0);
  float posX = 0.0;
  float posZ = 0.0;
  //glEnable(GL_TEXTURE_2D);
  //glBindTexture(GL_TEXTURE_2D, grid_text);
  for(int i = 0; i < GRID_WIDTH; i++){
    for(int j = 0; j < GRID_HEIGHT; j++){
      if(!frac[i][j]){
        glLineWidth(2.0);
        glColor3f(0.3, 0.7, 0.3);
     //   setMaterial(Exp);
        setMaterial(Grid);
		//setMaterial(White);
		
        glBegin(GL_POLYGON);{
		  //glTexCoord2f(0.0,1.0);
          glVertex3f(posX - GRID_SIZE, 0.0, posZ - GRID_SIZE);
		  //glTexCoord2f(0.0,0.0);
          glVertex3f(posX - GRID_SIZE, 0.0, posZ + GRID_SIZE);
		  //glTexCoord2f(1.0,0.0);
          glVertex3f(posX + GRID_SIZE, 0.0, posZ + GRID_SIZE);
        }
        glEnd();
        glBegin(GL_POLYGON);{
		  //glTexCoord2f(1.0,0.0);
          glVertex3f(posX + GRID_SIZE, 0.0, posZ + GRID_SIZE);
		  //glTexCoord2f(1.0,1.0);
          glVertex3f(posX + GRID_SIZE, 0.0, posZ - GRID_SIZE);
		  //glTexCoord2f(0.0,1.0);
          glVertex3f(posX - GRID_SIZE, 0.0, posZ - GRID_SIZE);
        }
        glEnd();
		
		if(grid[i][j]){
        setMaterial(gridColor);
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
      }
      posZ += GRID_SIZE*2.0;
    }
    posZ = 0.0;
    posX += GRID_SIZE*2.0;
  }
  //glBindTexture(GL_TEXTURE_2D, 0);
  //glDisable(GL_TEXTURE_2D);
  drawFractals();
  drawBoundry();
  glPopMatrix();
}

void GameGrid::drawFractals()
{
	std::list<FractalSet*>::iterator i;
	for(i = f_sets.begin(); i != f_sets.end(); ++i){
		(*i)->draw();
	}
}

void GameGrid::drawBoundry()
{
	//setMaterial(Teal);
    //glColor3f(0.3, 0.7, 0.7);
	for(int i = 0; i < (int)bound_lines.size(); i++)
	{
		float t = bound_lines[i] / BOUNDRY_HEIGHT;
		GLfloat color[] = { gridColor.diffuse[0] - t*gridColor.diffuse[0],
							gridColor.diffuse[1] - t*gridColor.diffuse[1],
							gridColor.diffuse[2] - t*gridColor.diffuse[2],
							1.0f
						   };
		//GLfloat color[] = {0.0f,0.5f - (t*0.5),0.5f - (t*0.5),1.0f}; //Fade to black
		//GLfloat color[] = {t,0.5f + (t*0.5f),0.5f + (t*0.5f)}; //Fade to white
		glLineWidth(1.0 - (1.0*t));
		glMaterialfv(GL_FRONT,GL_AMBIENT,color);
		glBegin(GL_LINE_LOOP);{
		  glVertex3f(-GRID_SIZE, bound_lines[i], -GRID_SIZE);
		  glVertex3f(GRID_WIDTH * 2.0 * GRID_SIZE - GRID_SIZE, bound_lines[i], -GRID_SIZE);
		  glVertex3f(GRID_WIDTH * 2.0 * GRID_SIZE - GRID_SIZE, bound_lines[i], GRID_HEIGHT * 2.0 * GRID_SIZE - GRID_SIZE);
		  glVertex3f(-GRID_SIZE, bound_lines[i], GRID_HEIGHT * 2.0 * GRID_SIZE - GRID_SIZE);
		}
		glEnd();
	}
}

void GameGrid::update(int dt)
{
	boundry_cntdown -= dt;
	if(boundry_cntdown <= 0)
	{
		bound_lines.insert(bound_lines.begin(),0.0);
		boundry_cntdown += BOUNDRY_SPAWN_RATE;
	}
	for(int i = 0; i < (int)bound_lines.size(); i++)
	{
		float t = bound_lines[i] / BOUNDRY_HEIGHT + 0.1;
		bound_lines[i] += (float)dt * 0.8 * t / 1000;
	}
	if(bound_lines[bound_lines.size()-1] > BOUNDRY_HEIGHT)
		bound_lines.pop_back();
}

void GameGrid::setGridColor(materialStruct color)
{
	this->gridColor = color;
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

bool GameGrid::originalIsWall(g_elem cur) {
	if(cur.x >= GRID_WIDTH || cur.x < 0 || cur.y >= GRID_HEIGHT + 8 || cur.y < 0)
		return true;
	else if(cur.y < 4 || cur.y > 35)
		return false;
	else
		return !oGrid[cur.x][cur.y - 4];
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

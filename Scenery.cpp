#include "Scenery.h"
#include "vfc.h"
//#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

const int SCENE_GRID_SIZE = 2;
const float SCENE_GRID_WIDTH = SCENE_GRID_SIZE * 2.0 * GRID_SIZE;
const float SCENE_GRID_HEIGHT = SCENE_GRID_SIZE * 2.0 * GRID_SIZE;
const float SCENE_UNIT_HEIGHT = 1.0;
const float SCENE_EXPANSE = 200.0;

Scenery::Scenery(char *filename, Player *plyr) :
player(plyr)
{
	std::ifstream file;
	file.open(filename);
	if(file.is_open())
	{
		try
		{
			int w_cnt,h_cnt;
			int game_grid_x[2];
			int game_grid_y;
			int game_grid_w,game_grid_h;
			vector<vector<GLfloat> > h_buffer;
			file >> w_cnt >> h_cnt;
			file >> game_grid_x[0] >> game_grid_x[1] >> game_grid_w;
			file >> game_grid_y >> game_grid_h;
			printf("Creating Scene of size %d x %d\n",w_cnt,h_cnt);
			printf("Play area: (%d,%d)->%d | %d->%d\n",game_grid_x[0],game_grid_x[1],game_grid_w,game_grid_y,game_grid_h);
			game_grid_index[0] = game_grid_x[0];
			game_grid_index[1] = game_grid_y;
			//Initialize vectors to appropriate sizes
			for(int i = 0; i < w_cnt; ++i) {
				grids.push_back(std::vector<SceneryGrid>());
				for(int j = 0; j < h_cnt; ++j)
					grids[i].push_back(SceneryGrid());
			}
			for(int i = 0; i < w_cnt+1; ++i) {
				h_buffer.push_back(std::vector<GLfloat>());
				for(int j = 0; j < h_cnt+1; ++j)
					h_buffer[i].push_back(GLfloat());
			}

			//Fill the h_buffer
			int buffer;
			for(int j = 0; j < h_cnt+1; ++j) {
				for(int i = 0; i < w_cnt+1; ++i) {
					file >> buffer;
					h_buffer[i][j] = -SCENE_UNIT_HEIGHT * (float)buffer;
				}
			}
			GLfloat v1[3];
			GLfloat v2[3];
			GLfloat n[3];
			for(int j = 0; j < h_cnt; ++j) {
				for(int i = 0; i < w_cnt; ++i) {
					if(((i >= game_grid_x[0] && i < game_grid_x[0] + game_grid_w) ||
						(i >= game_grid_x[1] && i < game_grid_x[1] + game_grid_w)) &&
						(j >= game_grid_y && j < game_grid_y + game_grid_h)) {
							grids[i][j].isGameplayGrid = true;
					}
					else {
						grids[i][j].tl = h_buffer[i][j];
						grids[i][j].tr = h_buffer[i+1][j];
						grids[i][j].bl = h_buffer[i][j+1];
						grids[i][j].br = h_buffer[i+1][j+1];

						//Calculate normal
						//1st Vector ---->
						v1[0] = 1.0;
						v1[1] = grids[i][j].tr - grids[i][j].tl;
						v1[2] = 0.0;

						//2nd Vector
						//   |
						//   |
						//   v
						v2[0] = 0.0;
						v2[1] = grids[i][j].tl - grids[i][j].bl;
						v2[2] = -1.0;
						normCrossProd(v1,v2,n);
						grids[i][j].norm[0] = n[0];
						grids[i][j].norm[1] = n[1];
						grids[i][j].norm[2] = n[2];
					}
				}
			}
		}
		catch(exception& e)
		{
			printf("Error while parsing the scenery file (scenery.grid)\nError: %s\n",e.what());
		}
	}
	else {
		printf("Error when opening the scenery file (scenery.grid)\n");
      if(file.rdstate() & ifstream::failbit) {
         cout << "failbit" << endl;
      }
      
      if (file.rdstate() & ifstream::eofbit) {
         cout << "eofbit" << endl;
      }
      
      if (file.rdstate() & ifstream::badbit) {
         cout << "badbit" << endl;
      }
   }
}

Scenery::~Scenery()
{
}

void Scenery::initialize(void)
{
	textures[0] = LoadMipMapTexture("scene_grid0.bmp");
	textures[1] = LoadMipMapTexture("scene_grid1.bmp");
	GLfloat up[] = {0.0,1.0,0.0};
	for(int j = 0; j < (int)grids[0].size(); ++j)
	{
		for(int i = 0; i < (int)grids.size(); ++i)
		{
			GLfloat n[3];
			n[0] = grids[i][j].norm[0];
			n[1] = grids[i][j].norm[1];
			n[2] = grids[i][j].norm[2];
			float dot = grids[i][j].norm[1];//up[0] * grids[i][j].norm[0] + up[1] * grids[i][j].norm[1] + up[2] * grids[i][j].norm[2];
			grids[i][j].texture = textures[1];
			/*if(dot < 0.2 && dot > -0.2) {
				grids[i][j].texture = textures[1];
			}
			else
				grids[i][j].texture = textures[0];*/
		}
	}
}

void Scenery::normalize(float v[3]) {
   // normalize v[] and return the result in v[]
   // from OpenGL Programming Guide, p. 58
   GLfloat d = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
   if (d == 0.0) {
      printf("zero length vector");
      return;
   }
   v[0] = v[0]/d; v[1] = v[1]/d; v[2] = v[2]/d;
}

void Scenery::normCrossProd(float v1[3], float v2[3], float out[3]) {
   // cross v1[] and v2[] and return the result in out[]
   // from OpenGL Programming Guide, p. 58
   out[0] = v1[1]*v2[2] - v1[2]*v2[1];
   out[1] = v1[2]*v2[0] - v1[0]*v2[2];
   out[2] = v1[0]*v2[1] - v1[1]*v2[0];
   normalize(out);
}

void Transform(GLfloat *matrix, GLfloat *in, GLfloat *out)
{
    int ii;

    for (ii=0; ii<4; ii++) {
        out[ii] = 
            in[0] * matrix[0*4+ii] +
            in[1] * matrix[1*4+ii] +
            in[2] * matrix[2*4+ii] +
            in[3] * matrix[3*4+ii];
    }
}

void Scenery::draw()
{
	glPushMatrix();
	glTranslatef(player->getPosition().getX(), player->getPosition().getY(), player->getPosition().getZ());
	glPushMatrix();
	glTranslatef(0.0,0.0,-GRID_SIZE - game_grid_index[1] * SCENE_GRID_HEIGHT);
	GLfloat world_pos[] = {player->getPosition().getX(),player->getPosition().getY(),player->getPosition().getZ() - (GRID_SIZE - game_grid_index[1] * SCENE_GRID_HEIGHT) - 44};
	GLfloat zpos = 0.0;
	for(int j = 0; j < (int)grids[0].size(); ++j) {
		glPushMatrix();
		glTranslatef(-GRID_SIZE - game_grid_index[0] * SCENE_GRID_WIDTH,0.0,0.0);
		world_pos[0] = -GRID_SIZE - game_grid_index[0] * SCENE_GRID_WIDTH - 3;
		for(int i = 0; i < (int)grids.size(); ++i) {
			if(!grids[i][j].isGameplayGrid) {
				world_pos[1] = grids[i][j].bl;
				/*GLfloat n[3];
				n[0] = grids[i][j].norm[0];
				n[1] = grids[i][j].norm[1];
				n[2] = grids[i][j].norm[2];*/
				if(vfc::viewFrustumCull(vfc::planes,world_pos,3*SCENE_GRID_WIDTH))
				{
					glEnable(GL_TEXTURE_2D);
					glBindTexture(GL_TEXTURE_2D, grids[i][j].texture);
					glNormal3f(grids[i][j].norm[0], grids[i][j].norm[1], grids[i][j].norm[2]);
					//setMaterial(SceneGrid);
					setMaterial(TexturedPlayerGrid);
					glBegin(GL_QUADS);

					glTexCoord2f(0.0,0.0);
					glVertex3f(0.0,grids[i][j].tl,0.0);
					glTexCoord2f(0.0,1.0);
					glVertex3f(0.0,grids[i][j].bl,SCENE_GRID_HEIGHT);
					glTexCoord2f(1.0,1.0);
					glVertex3f(SCENE_GRID_WIDTH,grids[i][j].br,SCENE_GRID_HEIGHT);
					glTexCoord2f(1.0,0.0);
					glVertex3f(SCENE_GRID_WIDTH,grids[i][j].tr, 0.0);

					glEnd();
					glDisable(GL_TEXTURE_2D);

					/*setMaterial(SceneLines);
					glPushMatrix();
					glTranslatef(0.0,0.01,0.0);
					glBegin(GL_LINE_LOOP);
						glVertex3f(0.0,grids[i][j].tl,0.0);
						glVertex3f(0.0,grids[i][j].bl,SCENE_GRID_HEIGHT);
						glVertex3f(SCENE_GRID_WIDTH,grids[i][j].br,SCENE_GRID_HEIGHT);
						glVertex3f(SCENE_GRID_WIDTH,grids[i][j].tr, 0.0);
					glEnd();
					glPopMatrix();*/
				}
			}
			glTranslatef(SCENE_GRID_WIDTH,0.0,0.0);
			world_pos[0] += SCENE_GRID_WIDTH;
		}
		glPopMatrix();
		glTranslatef(0.0,0.0,SCENE_GRID_HEIGHT);
		world_pos[2] += SCENE_GRID_HEIGHT;
	}
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);

	//Draw the 4 outskirts
	glTranslatef(0.0,0.0,-GRID_SIZE - game_grid_index[1] * SCENE_GRID_HEIGHT);
	glTranslatef(-GRID_SIZE - game_grid_index[0] * SCENE_GRID_WIDTH,0.0,0.0);
	glNormal3f(0.0,1.0,0.0);
	setMaterial(GridExpanse);

	glPushMatrix();
	glTranslatef(0.0, 0.0, grids[0].size() * SCENE_GRID_HEIGHT);
	glBegin(GL_QUADS);
	glVertex3f(-SCENE_EXPANSE,-SCENE_UNIT_HEIGHT,0.0);
	glVertex3f(-SCENE_EXPANSE,-SCENE_UNIT_HEIGHT,SCENE_EXPANSE);
	glVertex3f(SCENE_EXPANSE,-SCENE_UNIT_HEIGHT,SCENE_EXPANSE);
	glVertex3f(SCENE_EXPANSE,-SCENE_UNIT_HEIGHT, 0.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(-SCENE_EXPANSE,-SCENE_UNIT_HEIGHT,0.0);
	glVertex3f(SCENE_EXPANSE,-SCENE_UNIT_HEIGHT,0.0);
	glVertex3f(SCENE_EXPANSE,-SCENE_UNIT_HEIGHT,-SCENE_EXPANSE);
	glVertex3f(-SCENE_EXPANSE,-SCENE_UNIT_HEIGHT,-SCENE_EXPANSE);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(grids.size() * SCENE_GRID_WIDTH, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.0,-SCENE_UNIT_HEIGHT,0.0);
	glVertex3f(0.0,-SCENE_UNIT_HEIGHT,grids[0].size() * SCENE_GRID_HEIGHT);
	glVertex3f(SCENE_EXPANSE,-SCENE_UNIT_HEIGHT,grids[0].size() * SCENE_GRID_HEIGHT);
	glVertex3f(SCENE_EXPANSE,-SCENE_UNIT_HEIGHT,0.0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(0.0,-SCENE_UNIT_HEIGHT,0.0);
	glVertex3f(-SCENE_EXPANSE,-SCENE_UNIT_HEIGHT,0.0);
	glVertex3f(-SCENE_EXPANSE,-SCENE_UNIT_HEIGHT,grids[0].size() * SCENE_GRID_HEIGHT);
	glVertex3f(0.0,-SCENE_UNIT_HEIGHT,grids[0].size() * SCENE_GRID_HEIGHT);
	glEnd();
	glPopMatrix();


	glPopMatrix();
}
#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <exception>
#include "lighting.h"
#include "constants.h"
#include <math.h>
#include "Player.h"

using namespace std;

extern const int SCENE_GRID_SIZE;
extern const float SCENE_GRID_WIDTH;
extern const float SCENE_GRID_HEIGHT;
extern const float SCENE_UNIT_HEIGHT;

struct SceneryGrid {
	GLfloat tl,tr,bl,br;
	GLfloat norm[3];
	bool isGameplayGrid;
};

class Scenery {
public:
	Scenery(char *filename, Player *plyr);
	~Scenery(void);
	void draw(void);
private:
	vector<vector<SceneryGrid>> grids;
	void normalize(float v[3]);
	void normCrossProd(float v1[3], float v2[3], float out[3]);
	int game_grid_index[2];
	Player *player;
};
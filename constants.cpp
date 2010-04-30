#include "constants.h"
const int GRID_WIDTH = 16;
const int GRID_HEIGHT = 32;
const float GRID_SIZE = 0.25;
const int CYCLE_TIME = 25000;

g_elem loc2grid(float x, float z) {
	return g_elem((int)((x - GRID_SIZE)/(2.0 * GRID_SIZE)), (int)((z - GRID_SIZE)/(2.0 * GRID_SIZE)));
}

void grid2loc(g_elem g, float * x, float * z) {
	*x = GRID_SIZE * 2.0 * g.x + GRID_SIZE;
	*z = GRID_SIZE * 2.0 * g.y + GRID_SIZE;
}
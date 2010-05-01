#include "constants.h"
const int GRID_WIDTH = 16;
const int GRID_HEIGHT = 32;
const float GRID_SIZE = 0.25;
const int CYCLE_TIME = 25000;

namespace unit_cost{
  const int BASIC = 5;
  const int FAST = 10;
  const int STRONG = 20;
}
namespace unit_bonus{
  extern const int BASIC = 1;
  extern const int FAST = 2;
  extern const int STRONG = 5;
}
namespace tower_cost{
  const int BASIC = 5;
  const int FAST = 5;
  const int FREEZE = 10;
  const int SLOW = 25;
  const int TRAP = 15;
  const int WALL = 2;
}

g_elem loc2grid(float x, float z) {
	return g_elem((int)((x)/(2.0 * GRID_SIZE) + 0.5), (int)((z)/(2.0 * GRID_SIZE) + 0.5));
}

void grid2loc(g_elem g, float * x, float * z) {
	*x = GRID_SIZE * 2.0 * g.x;
	*z = GRID_SIZE * 2.0 * g.y;
}
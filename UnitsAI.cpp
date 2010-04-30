#include "UnitsAI.h"

UnitsAI::UnitsAI(void)
{
}

UnitsAI::UnitsAI(GameGrid ingg)
{
	gg = ingg;
}

UnitsAI::~UnitsAI(void)
{
}

void UnitsAI::determineUnitsPaths() {
	std::list<Unit*>::iterator i;
	g_elem goal(GRID_WIDTH - 1, GRID_HEIGHT - 1); // goal location will change

	// find path for every unit
	for(i = uList.begin(); i != uList.end(); ++i) {
		g_elem startLoc = loc2grid((*i)->getX(), (*i)->getY());
		MyNode * cur = &MyNode(startLoc, NULL, 0, heuristic(startLoc, goal));
		std::priority_queue<MyNode, std::vector<MyNode>, CompareMyNode> fringe;
		std::stack<g_elem> path;
		bool visited[16][32]; // note GRID_WIDTH and GRID_HEIGHT might change... stupid constants

		// initialize visited array
		for(int i = 0; i < GRID_WIDTH; ++i){
			for(int j = 0; j < GRID_HEIGHT; ++j){
				visited[i][j] = false;
			}
		}

		// A* search
		while(!(goal == cur->loc)) {
			// left
			g_elem left(cur->loc.x - 1, cur->loc.y);
			if(!gg.isWall(left) && !visited[cur->loc.x - 1][cur->loc.y]) {
				visited[cur->loc.x - 1][cur->loc.y] = true;
				fringe.push(MyNode(left, cur, cur->g + 1, heuristic(left, goal)));
			}

			// right
			g_elem right(cur->loc.x + 1, cur->loc.y);
			if(!gg.isWall(right) && !visited[cur->loc.x + 1][cur->loc.y]) {
				visited[cur->loc.x + 1][cur->loc.y] = true;
				fringe.push(MyNode(right, cur, cur->g + 1, heuristic(right, goal)));
			}

			// up
			g_elem up(cur->loc.x, cur->loc.y - 1);
			if(!gg.isWall(up) && !visited[cur->loc.x][cur->loc.y - 1]) {
				visited[cur->loc.x][cur->loc.y - 1] = true;
				fringe.push(MyNode(up, cur, cur->g + 1, heuristic(up, goal)));
			}

			// down
			g_elem down(cur->loc.x, cur->loc.y + 1);
			if(!gg.isWall(down) && !visited[cur->loc.x][cur->loc.y + 1]) {
				visited[cur->loc.x][cur->loc.y + 1] = true;
				fringe.push(MyNode(down, cur, cur->g + 1, heuristic(down, goal)));
			}

			cur = &fringe.top();
			fringe.pop();
		}

		// roll back and create path
		while(cur != NULL) {
			path.push(cur->loc);
			cur = cur->parent;
		}

		// set units path
		// NEED HELP HERE
	}
}

int heuristic(g_elem cur, g_elem goal) {
	return abs(cur.x - goal.x) + abs(cur.y - goal.y);
}

g_elem loc2grid(float x, float z) {
	return g_elem((int)((x - GRID_SIZE)/(2.0 * GRID_SIZE)), (int)((z - GRID_SIZE)/(2.0 * GRID_SIZE)));
}

void grid2loc(g_elem g, float * x, float * z) {
	*x = GRID_SIZE * 2.0 * g.x + GRID_SIZE;
	*z = GRID_SIZE * 2.0 * g.y + GRID_SIZE;
}
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

	for(i = uList.begin(); i != uList.end(); ++i) {
		g_elem startLoc(0, 0); // start location will need to be calculated
		MyNode * cur = &MyNode(startLoc, NULL, 0, heuristic(startLoc, goal));
		std::priority_queue<MyNode, std::vector<MyNode>, CompareMyNode> fringe;
		std::stack<g_elem> path;
		bool visited[GRID_WIDTH][GRID_HEIGHT];

		for(int i = 0; i < GRID_WIDTH; ++i){
			for(int j = 0; j < GRID_HEIGHT; ++j){
				visited[i][j] = false;
			}
		}

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

			cur = &fringe.pop();
		}

		while(cur != NULL) {
			path.push(cur->loc);
			cur = cur->parent;
		}
	}
}

int heuristic(g_elem cur, g_elem goal) {
	return abs(cur.x - goal.x) + abs(cur.y - goal.y);
}

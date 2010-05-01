#include "UnitsAI.h"

UnitsAI::UnitsAI(GameGrid& ingg):gg(&ingg)
{
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
		//std::cout << "start: " << startLoc.x << startLoc.y << std::endl;
		MyNode* cur = new MyNode(startLoc, NULL, 0, heuristic(startLoc, goal));
		std::priority_queue<MyNode*, std::vector<MyNode*>, CompareMyNode> fringe;
		std::stack<g_elem> path;
		bool visited[16][32]; // note GRID_WIDTH and GRID_HEIGHT might change... stupid constants

		// initialize visited array
		for(int l = 0; l < GRID_WIDTH; ++l){
			for(int j = 0; j < GRID_HEIGHT; ++j){
				visited[l][j] = false;
			}
		}

		// A* search
		while(!(goal == cur->loc)) {
			//std::cout << "cur " << cur->loc.x << " "  << cur->loc.y << " " << cur->f << std::endl;

			// left
			g_elem left(cur->loc.x - 1, cur->loc.y);
			if(!(*gg).isWall(left) && !visited[cur->loc.x - 1][cur->loc.y]) {
				//std::cout << "left " << cur->loc.x - 1 << " "  << cur->loc.y << std::endl;
				visited[cur->loc.x - 1][cur->loc.y] = true;
				fringe.push(new MyNode(left, cur, cur->g + 1, heuristic(left, goal)));
			}

			// right
			g_elem right(cur->loc.x + 1, cur->loc.y);
			if(!(*gg).isWall(right) && !visited[cur->loc.x + 1][cur->loc.y]) {
				//std::cout << "right " << cur->loc.x + 1 << " "  << cur->loc.y << std::endl;
				visited[cur->loc.x + 1][cur->loc.y] = true;
				fringe.push(new MyNode(right, cur, cur->g + 1, heuristic(right, goal)));
			}

			// up
			g_elem up(cur->loc.x, cur->loc.y - 1);
			if(!(*gg).isWall(up) && !visited[cur->loc.x][cur->loc.y - 1]) {
				//std::cout << "up " << cur->loc.x << " " << cur->loc.y - 1 << std::endl;
				visited[cur->loc.x][cur->loc.y - 1] = true;
				fringe.push(new MyNode(up, cur, cur->g + 1, heuristic(up, goal)));
			}

			// down
			g_elem down(cur->loc.x, cur->loc.y + 1);
			if(!(*gg).isWall(down) && !visited[cur->loc.x][cur->loc.y + 1]) {
				//std::cout << "down " << cur->loc.x << " "  << cur->loc.y + 1 << std::endl;
				visited[cur->loc.x][cur->loc.y + 1] = true;
				fringe.push(new MyNode(down, cur, cur->g + 1, heuristic(down, goal)));
			}

			cur = fringe.top();
			fringe.pop();
		}

		// roll back and create path
		while(cur != NULL) {
			//std::cout << cur->loc.x << " " << cur->loc.y << " " << cur->f << std::endl;
			path.push(cur->loc);
			cur = cur->parent;
		}

		// set units path
		(*i)->path = path;
	}
}

int heuristic(g_elem cur, g_elem goal) {
	return abs(cur.x - goal.x) + abs(cur.y - goal.y);
}
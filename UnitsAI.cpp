#include "UnitsAI.h"

UnitsAI::UnitsAI(GameGrid& ingg, std::list<Tower*> &intList):gg(&ingg),tList(&intList)
{
}

UnitsAI::~UnitsAI(void)
{
}

void UnitsAI::determineUnitsPaths() {
	std::list<Unit*>::iterator i;
	std::list<Tower*>::iterator t;
	g_elem goal(GOAL_X * 2, GOAL_Z * 2 + 4); // note MAGIC NUMBERS
	int inRangeGrid[16][40]; // note MAGIC NUMBERS

	// populate inRangeGrid
	for(int m = 0; m < 16; m++) { // note MAGIC NUMBERS
		for(int n = 0; n < 40; n++) { // note MAGIC NUMBERS
			inRangeGrid[m][n] = 0;
			if(!(*gg).isWall(g_elem(m, n))) {
				for(t = tList->begin(); t != tList->end(); ++t) {
					float gX = 0;
					float gZ = 0;
					float tX = (*t)->getX();
					float tZ = (*t)->getZ();
					grid2loc(g_elem(m, n), &gX, &gZ);
					float dist = sqrt((gX - tX)*(gX - tX) + (gZ - tZ)*(gZ - tZ));
					if(dist < (*t)->getRange())
						inRangeGrid[m][n] = inRangeGrid[m][n] + (int)dist;
				}
			}
		}
	}

	/*for(int a = 0; a < 16; a++) { // note MAGIC NUMBERS
		for(int b = 0; b < 40; b++) { // note MAGIC NUMBERS
			if(inRangeGrid[a][b] > 0)
				std::cout << a << " " << b << " " << inRangeGrid[a][b] << std::endl;
		}
	}*/

	// find path for every unit
	for(i = uList.begin(); i != uList.end(); ++i) {
		if((*i)->foundGoal)
			continue;
		g_elem startLoc = loc2grid((*i)->getX(), (*i)->getZ());
		std::list<MyNode*>::iterator m;
		MyNode* cur = new MyNode(startLoc, NULL, inRangeGrid[startLoc.x][startLoc.y], heuristic(startLoc, goal));
		std::priority_queue<MyNode*, std::vector<MyNode*>, CompareMyNode> fringe;
		std::stack<g_elem> path;
		std::list<MyNode*> dList;
		float nextX = 0;
		float nextZ = 0;
		bool attackMode = false;
		bool visited[16][40]; // note MAGIC NUMBERS

		// initialize visited array
		for(int l = 0; l < GRID_WIDTH; ++l){
			for(int j = 0; j < GRID_HEIGHT + 8; ++j){ // note MAGIC NUMBERS
				visited[l][j] = false;
			}
		}

		dList.push_back(cur);

		// A* search
		while(!(goal == cur->loc)) {
			//std::cout << "cur " << cur->loc.x << " "  << cur->loc.y << " " << cur->f << std::endl;

			// left
			g_elem left(cur->loc.x - 1, cur->loc.y);
			if(!(*gg).isWall(left) && !visited[cur->loc.x - 1][cur->loc.y]) {
				//std::cout << "left " << cur->loc.x - 1 << " "  << cur->loc.y << std::endl;
				visited[cur->loc.x - 1][cur->loc.y] = true;
				MyNode* d = new MyNode(left, cur, cur->g + 1 + inRangeGrid[left.x][left.y], heuristic(left, goal));
				fringe.push(d);
				dList.push_back(d);
			}

			// right
			g_elem right(cur->loc.x + 1, cur->loc.y);
			if(!(*gg).isWall(right) && !visited[cur->loc.x + 1][cur->loc.y]) {
				//std::cout << "right " << cur->loc.x + 1 << " "  << cur->loc.y << std::endl;
				visited[cur->loc.x + 1][cur->loc.y] = true;
				MyNode* d = new MyNode(right, cur, cur->g + 1 + inRangeGrid[right.x][right.y], heuristic(right, goal));
				fringe.push(d);
				dList.push_back(d);
			}

			// up
			g_elem up(cur->loc.x, cur->loc.y - 1);
			if(!(*gg).isWall(up) && !visited[cur->loc.x][cur->loc.y - 1]) {
				//std::cout << "up " << cur->loc.x << " " << cur->loc.y - 1 << std::endl;
				visited[cur->loc.x][cur->loc.y - 1] = true;
				MyNode* d = new MyNode(up, cur, cur->g + 1 + inRangeGrid[up.x][up.y], heuristic(up, goal));
				fringe.push(d);
				dList.push_back(d);
			}

			// down
			g_elem down(cur->loc.x, cur->loc.y + 1);
			if(!(*gg).isWall(down) && !visited[cur->loc.x][cur->loc.y + 1]) {
				//std::cout << "down " << cur->loc.x << " "  << cur->loc.y + 1 << std::endl;
				visited[cur->loc.x][cur->loc.y + 1] = true;
				MyNode* d = new MyNode(down, cur, cur->g + 1 + inRangeGrid[down.x][down.y], heuristic(down, goal));
				fringe.push(d);
				dList.push_back(d);
			}

			if(fringe.empty()) {
				attackMode = true;
				break;
			}

			cur = fringe.top();
			fringe.pop();
		}

		if(attackMode) {
			path.push(goal);
			(*i)->path = path;
			(*i)->dir.setVector(GOAL_X - (*i)->getX(), 0.0, GOAL_Z - (*i)->getZ());
			(*i)->dir.normalize();
			(*i)->hasPathB = false;
			continue;
		}

		// roll back and create path
		while(cur != NULL) {
			//std::cout << cur->loc.x << " " << cur->loc.y << " " << cur->f << std::endl;
			path.push(cur->loc);
			cur = cur->parent;
		}

		// delete MyNode's
		for(m = dList.begin(); m != dList.end(); ++m) {
			delete (*m);
		}

		// set units path
		(*i)->path = path;
		grid2loc(path.top(), &nextX, &nextZ);
		if(!(nextX == GOAL_X && nextZ == GOAL_Z)) { 
			path.pop();
			grid2loc(path.top(), &nextX, &nextZ);
			(*i)->dir.setVector(nextX - (*i)->getX(), 0.0, nextZ - (*i)->getZ());
			(*i)->dir.normalize();
		}

		(*i)->hasPathB = true;
	}
}

void UnitsAI::setGrid(GameGrid& inGrid){
  gg = &inGrid;
}

void UnitsAI::setTowers(std::list<Tower*> &intList){
  tList = &intList;
}

int heuristic(g_elem cur, g_elem goal) { // note MAGIC NUMBERS
	return abs(cur.x - goal.x) + abs(cur.y - goal.y);
}
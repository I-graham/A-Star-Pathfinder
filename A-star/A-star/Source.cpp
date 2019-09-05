#include <iostream>
#include <iomanip>
#include "node.h"
using namespace std;

int heuristic(int x[2], int y[2]) {
	int returnx = 0;
	int returny = 0;
	if (x[0] < y[0]) {
		returnx++;
	}
	if (x[0] > y[0]) {
		returnx--;
	}
	if (x[1] < y[1]) {
		returny++;
	}
	if (x[1] > y[1]) {
		returny--;
	}
	int returnlist[2] = {x[0]+returnx, x[1]+returny};
	if (((returnx != 0) || (returny != 0)) && !(returnx && returny)) {
		return heuristic(returnlist, y) + 10;
	}
	if (returnx != 0 && returny != 0) {
		return heuristic(returnlist, y) + 14;
	}
	if (x[0] == y[0] && x[1] == y[1]) {
		return 0;
	}
}

void evaluatenode(node *center, node gridtest[30][30]) {
	(*center).open = false;
	(*center).evaluated = true;
	for (int csx = -1; csx <= 1; csx++) {
		for (int csy = -1; csy <= 1; csy++) {
			if (((*center).space[0] + csy) >= 0 && ((*center).space[0] + csy) < 30 && ((*center).space[0] + csx) >= 0 && ((*center).space[0] + csx) < 30){
				node *testing = &gridtest[(*center).space[0] + csy][(*center).space[1] + csx];
				if (!(csy == 0 && csx == 0)) {
					if ((*testing).open == true) {
						if ((*testing).blocked == false) {
							if ((csy != 0) && (csx != 0) && ((*center).g + 14) < (*testing).g) {
								(*testing).setparent(*center);


								(*testing).g = (*center).g + 14;
							}
							if ((csy == 0 || csx == 0) && ((*center).g + 10) < (*testing).g) {
								(*testing).setparent(*center);
								(*testing).g = (*center).g + 10;
							}
						}
					}
					else {
						if (csy != 0 && csx != 0) {
							(*testing).setparent(*center);
							(*testing).g = (*center).g + 14;
						}
						if (csy == 0 || csx == 0) {
							(*testing).setparent(*center);
							(*testing).g = (*center).g + 10;
						}
					}
					}
					testing->open = true;
				}
			}
		}
	}
int main() {
	int x, y, startx, starty;
	cout << "input start: " << endl << "x=";
	cin >> startx;
	cout << "y=";
	cin >> starty;
	cout << "input goal: " << endl << "x=";
	cin >> x; 
	cout << "y=";
	cin >> y;
	unsigned int minvar = 999999999;
	node grid[30][30];
	node *start = &grid[starty][startx];
	node *goal = &grid[y][x];
	goal->space[0] = y; goal->space[1] = x;
	for (int a = 0; a < 30; a++) {
		for (int b = 0; b < 30; b++) {
			grid[a][b].space[0]  = a;
			grid[a][b].space[1]  = b;
			grid[a][b].heuristic = heuristic(grid[a][b].space, (*goal).space);
			grid[a][b].g         = 1;
			grid[a][b].selected  = false;
		}
	}
	
	(*goal).selected = true;
	(*start).g = 0;
	bool done = false;
	evaluatenode(start, grid);
	while (!done) {
		int nextcheck[2] = { 0,0 };
		minvar = 999999999;
		for (int a = 0; a < 30; a++) {
			for (int b = 0; b < 30; b++) {
				if ((grid[a][b].g + grid[a][b].heuristic) < minvar && (grid[a][b].open == true && grid[a][b].evaluated == false && grid[a][b].blocked == false)) {
					minvar = grid[a][b].g + grid[a][b].heuristic;
					nextcheck[0] = a;
					nextcheck[1] = b;
				}
			}
		}
		evaluatenode(&grid[nextcheck[0]][nextcheck[1]], grid);
		if ((*goal).space[0] == nextcheck[0] && (*goal).space[1] == nextcheck[1]) {
			node *path = &grid[y][x];
			done = true;
			while (path->space[0] != (*start).space[0] || path->space[1] != (*start).space[1]) {
				grid[path->parent[0]][path->parent[1]].selected = true;
				path = &grid[path->parent[0]][path->parent[1]];
			}
		}
	}
	for (int a = 29; a >= 0; a--) {
		for (int b = 0; b < 30; b++) {
			cout << grid[a][b].selected << " ";
		}
		cout << endl;
	}	
}
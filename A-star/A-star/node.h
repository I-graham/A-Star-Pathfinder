#pragma once
class node
{
public:
	node();
	void setparent(node setparent);
	unsigned int g;
	unsigned int heuristic;
	int space[2];
	int parent[2];
	bool open;
	bool selected;
	bool evaluated;
	bool blocked;
};


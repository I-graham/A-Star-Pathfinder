#include "node.h"
#include <iostream>
using namespace std;

node::node()
{
	this->open = false;
	this->blocked = false;
	this->evaluated = false;
}
void node::setparent(node setparent) {
	this->parent[0] = setparent.space[0];
	this->parent[1] = setparent.space[1];
}
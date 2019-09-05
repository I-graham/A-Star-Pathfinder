#include "Square.h"

Square::Square(){}
void Square::set(bool openset, int parentset[2], int gset, int hset) {
	open = openset;
	parent[0] = parentset[0];
	parent[1] = parentset[1];
	g = gset;
	h = hset;
}
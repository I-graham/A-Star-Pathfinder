#ifndef SQUARE_H
#define SQUARE_H

class Square
{
public:
	Square();
	void set(bool openset, int parentset[2], int gset, int hset);
private:
	bool open;
	int parent[2];
	int g;
	int h;
}
#endif

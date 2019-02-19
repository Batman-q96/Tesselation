#pragma once

#include <vector>

struct coord {//2d for now
	float x;
	float y;
};

class shape
{
private:
	std::vector<coord> vertices;
public:
	shape(int);
	~shape();
	void print_info();
};


#pragma once

#include <vector>
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>

struct coord {//2d for now
	float x;
	float y;
};

class shape
{
private:
	std::vector<coord> vertices;
	void rotate_origin(const double angle);
public:
	shape(int);
	shape(int, std::vector<shape*>*);
	~shape();
	void print_info();
	void draw(Gdiplus::Graphics*, Gdiplus::Color pen_color= Gdiplus::Color(255, 0, 0, 0));
	void move(const coord);
	void rotate(const double, const int point = 0);
	void zoom(const int);
};


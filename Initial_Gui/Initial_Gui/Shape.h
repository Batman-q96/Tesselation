#pragma once

#include <vector>
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>

class Shape
{
protected:
	Gdiplus::Graphics* graphics;
	Gdiplus::PointF    center;
	float              radius;
public:
	Shape(float,
		Gdiplus::PointF    center = Gdiplus::PointF::PointF(),
		Gdiplus::Graphics* graphics_def = NULL);
	~Shape();
	void set_graphics(Gdiplus::Graphics* graphics_def);
	virtual void print();
	virtual void draw(Gdiplus::Graphics* graphics,
		Gdiplus::Color                   fill_color = Gdiplus::Color(255, 0, 0, 0),
		Gdiplus::Color                   edge_color = Gdiplus::Color(255, 0, 0, 0),
		int                              line_width = 1) = 0;
	void draw(Gdiplus::Color edge_color = Gdiplus::Color(255, 0, 0, 0),
		Gdiplus::Color       fill_color = Gdiplus::Color(255, 0, 0, 0),
		int                  line_width = 0);
	virtual void move(Gdiplus::PointF);
	virtual void zoom(const int);
};
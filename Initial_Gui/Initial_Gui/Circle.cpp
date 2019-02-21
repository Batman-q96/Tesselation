#include "stdafx.h"
#include "Circle.h"

#include "Debug_prints.h"

Circle::Circle(float size,
	Gdiplus::PointF    center,
	Gdiplus::Graphics* graphics_def) :
	Shape(size, center, graphics_def)
{
}

Circle::~Circle()
{
}

void Circle::draw(Gdiplus::Graphics* graphics,
	Gdiplus::Color           fill_color,
	Gdiplus::Color           edge_color,
	int                      line_width) {
	debug_print(TEXT("\ntest\n"));
	float top_right_x = center.X - radius;
	float top_right_y = center.Y - radius;
	graphics->FillEllipse(new Gdiplus::SolidBrush(fill_color), top_right_x, top_right_y, radius * 2, radius * 2);
	graphics->DrawEllipse(new Gdiplus::Pen(edge_color, line_width), top_right_x, top_right_y, radius * 2, radius * 2);
	debug_print(TEXT("Drwaing circle"));
}

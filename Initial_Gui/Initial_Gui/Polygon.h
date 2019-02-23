#pragma once
#include "Shape.h"
class Polygon_Shape : public Shape
{
protected:
	std::vector<Gdiplus::PointF> vertices;
	int sides;
	double angle;
	void rotate_origin(double);
	void conjug_move(bool, Gdiplus::PointF targ_vec = Gdiplus::PointF());
	void update_vertices();
public:
	Polygon_Shape(int, float,
		Gdiplus::PointF    center = Gdiplus::PointF::PointF(),
		Gdiplus::Graphics* graphics_def = NULL);
	~Polygon_Shape();
	void rotate(double, int point=0);
	void rotate(double, Gdiplus::PointF targ_point = Gdiplus::PointF());
	void draw(Gdiplus::Graphics* graphics,
		Gdiplus::Color           fill_color = Gdiplus::Color(255, 0, 0, 0),
		Gdiplus::Color           edge_color = Gdiplus::Color(255, 0, 0, 0),
		int                      line_width = 0);
	void shrink_to_one();
};


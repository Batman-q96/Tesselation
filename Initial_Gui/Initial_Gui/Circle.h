#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(float,
		Gdiplus::PointF    center = Gdiplus::PointF::PointF(),
		Gdiplus::Graphics* graphics_def = NULL);
	~Circle();
	void draw(Gdiplus::Graphics* graphics,
		Gdiplus::Color           fill_color,
		Gdiplus::Color           edge_color,
		int                      line_width);
};

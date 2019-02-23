#include "stdafx.h"
#include "Shape.h"

#include "Debug_prints.h"


Shape::Shape(float size,
	Gdiplus::PointF    center,
	Gdiplus::Graphics* graphics_def) : 
	radius(size), center(center){
	if (graphics_def) {
		graphics = graphics_def;
	}
	debug_print(TEXT("Shape created\n\n"));
}

Shape::~Shape() {

}

void Shape::set_graphics(Gdiplus::Graphics* graphics_def) {
	graphics = graphics_def;
}

void Shape::print() {
	debug_print(TEXT("\n\nObject is: Shape\n \
		\tcenter is at: (%f, %f)\n \
		\tradius is: %d\n"),
		center.X, center.Y, radius);
}

void Shape::draw(Gdiplus::Color fill_color,
	Gdiplus::Color              edge_color,
	int							line_Width) {
	center.X;
	draw(graphics, fill_color, edge_color, line_Width);
}

void Shape::move(Gdiplus::PointF shift) {
	center = center + shift;
}

void Shape::zoom(const int scale) {
	radius *= scale;
}
#include "stdafx.h"
#include "Polygon.h"

#define _USE_MATH_DEFINES
#include <math.h>

Polygon_Shape::Polygon_Shape(int num_sides, float size,
	Gdiplus::PointF    center,
	Gdiplus::Graphics* graphics_def) :
	Shape(size, center, graphics_def),
	vertices(num_sides),
	angle(0)
{
	sides = num_sides;
	radius = size;
	update_vertices();
}

Polygon_Shape::~Polygon_Shape()
{
}

void Polygon_Shape::update_vertices() {
	std::vector<Gdiplus::PointF>::iterator   ii;
	for (ii = vertices.begin(); ii != vertices.end(); ii++) {
		ii->X = (Gdiplus::REAL) (center.X + radius * cos(angle));
		ii->Y = (Gdiplus::REAL) (center.Y + radius * sin(angle));
		angle += (2 * M_PI / sides);
	}
}

void Polygon_Shape::rotate_origin(double new_angle) {
	//first rotate center
	double rota_matrix[2][2] = { {cos(new_angle), -sin(new_angle)}, {sin(new_angle), cos(new_angle)} };
	Gdiplus::PointF new_center = Gdiplus::PointF(
		(Gdiplus::REAL) (center.X*rota_matrix[0][0] + center.Y*rota_matrix[0][1]),
		(Gdiplus::REAL) (center.X*rota_matrix[1][0] + center.Y*rota_matrix[1][1]));//otherwise we have to rewrite them simultaneously resulting in race conditions
	center.Equals(new_center);
	//then rotate the shape
	angle+= new_angle;
	update_vertices();
}

void Polygon_Shape::conjug_move(bool there_back, Gdiplus::PointF targ_vec){//targ_vec is pointed away from origin, so operations are backwards
	if (there_back) {//true move it back
		center = center + targ_vec;
		update_vertices();
	}
	else {           //false move it away
		center = center - targ_vec;
		update_vertices();
	}
}

void Polygon_Shape::rotate(double new_angle, int point) {
	rotate(new_angle, vertices[point]);
}

void Polygon_Shape::rotate(double new_angle, Gdiplus::PointF move_point) {
	conjug_move(0, move_point);
	rotate_origin(new_angle);
	conjug_move(1, move_point);
}


void Polygon_Shape::draw(Gdiplus::Graphics* graphics,
	Gdiplus::Color                    fill_color,
	Gdiplus::Color                    edge_color,
	int                               line_width) {
	//cool trick to convert vector to array: pass a refrence to the first element
	graphics->FillPolygon(new Gdiplus::SolidBrush(fill_color), &vertices[0], sides);
	graphics->DrawPolygon(new Gdiplus::Pen(edge_color, (Gdiplus::REAL) line_width), &vertices[0], sides);
}
void Polygon_Shape::shrink_to_one() {
	radius = (float) (1 / (2 * sin(M_PI / sides)));
	update_vertices();
}
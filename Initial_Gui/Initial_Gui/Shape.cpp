#include "stdafx.h"
#include "Shape.h"

#define _USE_MATH_DEFINES 
#include <math.h>

#define debug_build
#include "Debug_prints.cpp"

shape::shape(int sides) : vertices(sides, { 0, 0 })
{
	debug_print(TEXT("Creating a %d-angle\n"), vertices.size());
	double external_angle = M_PI * 2 / sides, curr_angle = 0;
	for (int ii = 1; ii < sides; ii++, curr_angle += external_angle) {
		vertices[ii] = { (float) (vertices[ii - 1].x + cos(curr_angle)), (float) (vertices[ii - 1].y + sin(curr_angle)) };
	}
}
shape::shape(int sides, std::vector<shape*>* shape_list) : vertices(sides, { 0, 0 })
{
	debug_print(TEXT("Creating a %d-angle\n"), vertices.size());
	double external_angle = M_PI * 2 / sides, curr_angle = 0;
	for (int ii = 1; ii < sides; ii++, curr_angle += external_angle) {
		vertices[ii] = { (float) (vertices[ii - 1].x + cos(curr_angle)), (float) (vertices[ii - 1].y + sin(curr_angle)) };
	}
	shape_list->push_back(this);
}

void shape::print_info() {
	std::vector<coord>::iterator ii;
	
	debug_print(TEXT("Shape is a %d-angle\n"), vertices.size());
	for (ii = vertices.begin(); ii != vertices.end(); ii++) {//point locations
		debug_print(TEXT("Coordinates are (%f, %f)\n"), (*ii).x, (*ii).y);
	}
	debug_print(TEXT("\n"));
}

shape::~shape()
{
	debug_print(TEXT("Deleting a %d-angle\n"), vertices.size());
}

void shape::draw(Gdiplus::Graphics *graphics, Gdiplus::Color pen_color) {
	std::vector<coord>::iterator    ii;
	Gdiplus::Pen                    pen(pen_color);

	for (ii = vertices.begin(); ii != (vertices.end()-1); ii++) {//iterate over points, skip last one
		graphics->DrawLine(&pen, (*ii).x, (*ii).y, (*(ii+1)).x, (*(ii+1)).y);
		//debug_sleep(2000);//give time to draw each edge
	}
	graphics->DrawLine(&pen, (*vertices.begin()).x, (*vertices.begin()).y, (*(vertices.end() - 1)).x, (*(vertices.end() - 1)).y);//draw last one
}

void shape::move(const coord displacement) {
	std::vector<coord>::iterator ii;
	debug_print(TEXT("Displacing by (%f, %f)\n"), displacement.x, displacement.y);
	for (ii = vertices.begin(); ii != vertices.end(); ii++) {
		(*ii).x += displacement.x;
		(*ii).y += displacement.y;
	}
}
void shape::rotate_origin(const double angle) {
	std::vector<coord>::iterator ii;

	double rota_matrix[2][2] = { {cos(angle), -sin(angle)}, {sin(angle), cos(angle)} };//2d for now

	debug_print(TEXT("Rotating a %d-angle by %f radians\n"), vertices.size(), angle);
	for (ii = vertices.begin(); ii != vertices.end(); ii++) {//point locations
		float new_x = (float) ((*ii).x*rota_matrix[0][0] + (*ii).y*rota_matrix[0][1]);
		float new_y = (float) ((*ii).x*rota_matrix[1][0] + (*ii).y*rota_matrix[1][1]);
		(*ii).x = new_x;
		(*ii).y = new_y;
	}

}
void shape::rotate(const double angle, const int point) {
	coord anti_point = { 0 - vertices[point].x, 0 - vertices[point].y };
	coord orig_point = { vertices[point].x, vertices[point].y };
	move(anti_point);
	rotate_origin(angle);
	move(orig_point);
}
void shape::zoom(const int scale) {
	std::vector<coord>::iterator ii;
	coord anti_point = { 0 - vertices[0].x, 0 - vertices[0].y };
	coord orig_point = { vertices[0].x, vertices[0].y };
	
	move(anti_point);
	debug_print(TEXT("Scaling a %d-angle by %d\n"), vertices.size(), scale);
	for (ii = vertices.begin(); ii != vertices.end(); ii++) {//point locations
		(*ii).x *= scale;
		(*ii).y *= scale;
	}
	move(orig_point);
}
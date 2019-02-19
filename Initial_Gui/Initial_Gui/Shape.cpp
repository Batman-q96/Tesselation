#include "stdafx.h"
#include "Shape.h"

#define _USE_MATH_DEFINES 
#include <math.h>

#define debug_build
#include "Debug_prints.cpp"

shape::shape(int sides) : vertices(sides, { 0, 0 })
{
	double external_angle = M_PI * 2 / sides, curr_angle = 0;
	for (int ii = 1; ii < sides; ii++, curr_angle += external_angle) {
		vertices[ii] = { (float) (vertices[ii - 1].x + cos(curr_angle)), (float) (vertices[ii - 1].y + sin(curr_angle)) };
	}
}

void shape::print_info() {
	std::vector<coord>::iterator ii;
	for (ii = vertices.begin(); ii != vertices.end(); ii++) {
		debug_print(L"Coordinates are (%f, %f)\n", (*ii).x, (*ii).y);
	}
}

shape::~shape()
{
}

#include <iostream>
#include "point.h"
#include <math.h>

void Point::Points(const double x, const double y) {
	this->x = x;
	this->y = y;
}

double Point::CalculateDistance(const Point point1, const Point point2) {
	double p1 = (point1.x - point2.x) * (point1.x - point2.x);
	double p2 = (point1.y - point2.y) * (point1.y - point2.y);
	return sqrt(abs(p1 + p2));
}


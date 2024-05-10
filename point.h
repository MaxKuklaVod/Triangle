#pragma once
#include <iostream>

class Point {
private:
	double x;
	double y;
public:
	void Points(const double x, const double y);
	double CalculateDistance(const Point point1, const Point point2);
};
#pragma once
#include <iostream>
#include "point.h"


class Triangle {
private:
	Point point;
	double side1, side2, side3, area, pol;
	int count = 0;
	double* areas;
	int schet = 1;
public:
	void SetArr();
	double GetTriangleArea(const Point p1, const Point p2, const Point p3);
	void SetAreas(const double area);
	void VivodAreas();
	int countLinesinFiles(const char* filename);
	double readFilesx(const char* filename, double cur_x, double cur_y);
	double readFilesy(const char* filename, double cur_x, double cur_y);
	~Triangle();
};
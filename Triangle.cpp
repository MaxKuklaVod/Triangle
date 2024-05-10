#include <iostream>
#include "point.h"
#include "Triangle.h"
#include <math.h>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void Triangle::SetArr() {
	this->areas = new double[3];
}
double Triangle::GetTriangleArea(const Point p1, const Point p2, const Point p3) {
	side1 = point.CalculateDistance(p1, p2);
	side2 = point.CalculateDistance(p2, p3);
	side3 = point.CalculateDistance(p3, p1);

	pol = (side1 + side2 + side3) / 2;
	area = sqrt(pol * (pol - side1) * (pol - side2) * (pol - side3));
	return area;
}

void Triangle::SetAreas(const double area) {

	if (count != 3) {
		areas[count] = area;
		count++;
	}
	else {
		double min = areas[0];
		int index = 0;
		for (int i = 1; i < count; i++) {
			if (areas[i] < min) {
				index = i;
				min = areas[i];
			}
		}
		if (min < area) {
			areas[index] = area;
		}
	}
}

void Triangle::VivodAreas() {
	areas = this->areas;

	for (int i = 0; i < 3; i++) {
		cout << areas[i] << endl;
	}
}
int Triangle::countLinesinFiles(const char* filename)
{

	string line;
	int count = 0;

	ifstream in(filename);
	if (!in.is_open()) {
		return false;
	}

	while (getline(in, line)) {
		count += 1;
	}
	return count;
	in.close();

}
double Triangle::readFilesx(const char* filename, double cur_x, double cur_y)
{

	ifstream in(filename);
	int _ = 0;

	while (in >> cur_x >> cur_y) {
		_ += 1;
		if (_ == schet) {
			return cur_x;
		}
	}

}
double Triangle::readFilesy(const char* filename, double cur_x, double cur_y)
{
	ifstream in(filename);
	int _ = 0;

	while (in >> cur_x >> cur_y) {
		_ += 1;
		if (_ == schet) {
			schet += 1;
			return cur_y;
		}
	}
}
Triangle::~Triangle() {
	delete[] areas;
}
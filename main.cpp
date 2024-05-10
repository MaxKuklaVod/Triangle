#include <iostream>
#include "Triangle.h"
#include "point.h"
#include <vector>
using namespace std;

int main() {

	setlocale(LC_ALL, "RU");

	int n;
	Triangle triangle;
	Point point;
	n = triangle.countLinesinFiles("test2.txt");

	if (n < 3) {
		cout << "Введено меньше 3 точек, из этого не получится даже 1 треугольник";
		exit(0);
	}

	vector <Point> points(n);
	for (int i = 0; i < n; i++){
		double x = 0, y = 0, cur_x = 0, cur_y = 0;
		x = triangle.readFilesx("test2.txt", cur_x, cur_y);
		y = triangle.readFilesy("test2.txt", cur_x, cur_y);
		point.Points(x, y);
		points[i] = point;
	}
	
	triangle.SetArr();

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int l = j + 1; l < n; l++) {
				triangle.SetAreas(triangle.GetTriangleArea(points[i], points[j], points[l]));
			}
		}
	}

	triangle.VivodAreas();
}
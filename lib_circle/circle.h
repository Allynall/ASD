#pragma once
#include "../lib_point3d/point3d.h"

class Circle {
protected:
	Point _point;
	int _radius;
public:
	Circle(Point point = 0, int radius = 0); // ++

	Point get_point() const;
	int get_radius() const;


	bool operator == (const Circle&) const noexcept; // ++
};
#pragma once
#include "../lib_point/point.h"

class Point3D : public Point {
	int _oz;
public:
	Point3D(int ox = 0, int oy = 0, int oz = 0);
	Point3D(const Point3D&);

	int get_z() const;
	bool operator == (const Point3D& other) const noexcept;
	int DistanceBetweenPoints(const Point3D& other) const;
};
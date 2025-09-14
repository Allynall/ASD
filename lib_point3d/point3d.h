#pragma once
#include "../lib_point/point.h"

class Point3D : public Point {
	int _oz;
public:
	Point3D() = default;
	Point3D(int ox, int oy, int oz);
	Point3D(const Point3D&);

	bool operator == (const Point3D& other) const noexcept;
	int DistanceBetweenPoints(const Point3D& other) const;
};
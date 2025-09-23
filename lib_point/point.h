#pragma once

class Point {
protected:
	int _ox;
	int _oy;
public:
	Point(int ox = 0, int oy = 0);
	Point(const Point&);

	int get_x() const;
	int get_y() const;

	bool operator == (const Point&) const noexcept;
	int DistanceBetweenPoints(const Point& other);
};
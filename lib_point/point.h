#pragma once

class Point {
protected:
	int _ox;
	int _oy;
public:
	Point() = default;
	Point(int ox, int oy);
	Point(const Point&);

	int get_x() const;
	int get_y() const;

	bool operator == (const Point&) const noexcept;
	int DistanceBetweenPoints(const Point& other);
};
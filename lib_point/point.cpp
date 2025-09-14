#include "Point.h"
#include <cmath>

Point::Point(int ox, int oy) {
	_ox = ox;
	_oy = oy;
}
Point::Point(const Point& other) : _ox(other._ox), _oy(other._oy) {}

int Point::get_x() const
{
	return _ox;
}
int Point::get_y() const {
	return _oy;
}

bool Point::operator == (const Point& other) const noexcept {
	return this->_ox == other._ox && this->_oy == other._oy;
}

int Point::DistanceBetweenPoints(const Point& other) {
	return sqrt(pow((other._ox - _ox), 2) + pow((other._oy - _oy), 2));
}

#include "circle.h"
#include <stdexcept>

Circle::Circle(Point point, int radius) {
	if (radius < 0) {
		throw std::invalid_argument("The radius must be greater than zero");
	}

	_point = point;
	_radius = radius;
}
Point Circle::get_point() const {
	return _point;
};
int Circle::get_radius() const {
	return _radius;
};
bool Circle::operator == (const Circle& other) const noexcept {
	return this->_point == other._point && this->_radius == other._radius;
}
#include "point3d.h"
#include <cmath>


Point3D::Point3D(int ox, int oy, int oz) : Point(ox, oy), _oz(oz) {
}

Point3D::Point3D(const Point3D& other) : Point(other), _oz(other._oz) {}

int Point3D::get_z() const {
    return _oz;
}

bool Point3D::operator == (const Point3D& other) const noexcept {
    return this->get_x() == other.get_x() &&
        this->get_y() == other.get_y() &&
        this->_oz == other._oz;
}

int Point3D::DistanceBetweenPoints(const Point3D& other) const {
    return sqrt(pow((other._ox - _ox), 2) + pow((other._oy - _oy), 2) + pow((other._oz - _oz), 2));
}
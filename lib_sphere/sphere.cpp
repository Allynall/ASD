#include "sphere.h"
#include <stdexcept>

Sphere::Sphere(Point3D point3D, int radius) : Circle(point3D, radius), _point3D(point3D) {
    if (radius < 0) {
        throw std::invalid_argument("The radius must be greater than zero");
    }
}


Point3D Sphere::get_point3D() const {
    return _point3D;
}

bool Sphere::operator == (const Sphere& other) const noexcept {
    return Circle::operator==(other);
}
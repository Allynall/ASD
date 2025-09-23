#pragma once

#include "..\lib_circle\circle.h"

class Sphere : public Circle {
    Point3D _point3D;
public:
    Sphere(Point3D point3D = 0, int radius = 0);

    Point3D get_point3D() const;

    bool operator == (const Sphere&) const noexcept;
};
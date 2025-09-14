// Copyright 2024 Marina Usova

#define EASY_EXAMPLE
#ifdef EASY_EXAMPLE

#include <iostream>
#include <iomanip>
#include "../lib_sphere/sphere.h"

enum Status { Coincidence, Touch, Intersecting, NotIntersecting };

Status CheckingCoincidence(Circle first, Circle second) {
    if (first == second) {
        return Coincidence;
    }
    return NotIntersecting;
}
Status CheckingCoincidence(Sphere first, Sphere second) {
    if (first == second) {
        return Coincidence;
    }
    return Intersecting;
}
Status CheckingTouch(Circle first, Circle second) {
    if ((first.get_point().DistanceBetweenPoints(second.get_point())) == (first.get_radius() + second.get_radius())) {
        return Touch;
    }
    else if ((first.get_point().DistanceBetweenPoints(second.get_point())) == (first.get_radius() - second.get_radius())) {
        return Touch;
    }
    return NotIntersecting;
}
Status CheckingTouch(Sphere first, Sphere second) {
    if ((first.get_point3D().DistanceBetweenPoints(second.get_point3D())) == (first.get_radius() + second.get_radius())) {
        return Touch;
    }
    else if ((first.get_point3D().DistanceBetweenPoints(second.get_point3D())) == (first.get_radius() - second.get_radius())) {
        return Touch;
    }
    return Intersecting;
}

Status CheckingIntersecting(Circle first, Circle second) {
    if ((first.get_radius() - second.get_radius()) < (first.get_point().DistanceBetweenPoints(second.get_point()))
        && (first.get_point().DistanceBetweenPoints(second.get_point())) < (first.get_radius() + second.get_radius())) {
        return Intersecting;
    }
    return NotIntersecting;
}
Status CheckingNoIntersecting(Sphere first, Sphere second) {
    if ((first.get_point3D().DistanceBetweenPoints(second.get_point3D())) > (first.get_radius() + second.get_radius())) {
        return NotIntersecting;
    }
    return Intersecting;
}
Status CheckingStatus(Circle first, Circle second) {
    Status status = CheckingCoincidence(first, second);
    if (status == NotIntersecting) {
        status = CheckingTouch(first, second);
        if (status == NotIntersecting) {
            status = CheckingIntersecting(first, second);
        }
        else {
            return status;
        }
    }
    return status;
}
Status CheckingStatus(Sphere first, Sphere second) {
    Status status = CheckingCoincidence(first, second);
    if (status == Intersecting) {
        status = CheckingTouch(first, second);
        if (status == Intersecting) {
            status = CheckingIntersecting(first, second);
        }
        else {
            return status;
        }
    }
    return status;
}

int main() {
    Point a1(0, 0);
    Point a2(10, 0);
    Point a3(5, 0);
    Point a4(4, 0);

    Circle b1(a1, 4);
    Circle b2(a1, 4);
    Circle b3(a2, 6);
    Circle b4(a1, 8);
    Circle b5(a3, 3);
    Circle b6(a1, 5);
    Circle b7(a4, 3);
    Circle b8(a2, 3);
    Circle b9(a1, 2);

    Status CCoincidence = CheckingStatus(b1, b2);
    Status CExternalTouch = CheckingStatus(b1, b3);
    Status CInnerTouch = CheckingStatus(b4, b5);
    Status CIntersecting = CheckingStatus(b6, b7);
    Status CNotIntersecting = CheckingStatus(b8, b9);

    std::cout << "Circle Coincidence: " << CCoincidence << std::endl;
    std::cout << "Circle External Touch: " << CExternalTouch << std::endl;
    std::cout << "Circle Inner Touch: " << CInnerTouch << std::endl;
    std::cout << "Circle Intersecting: " << CIntersecting << std::endl;
    std::cout << "Circle NotIntersecting: " << CNotIntersecting << std::endl;

    Point3D d1(0, 0, 0);
    Point3D d2(12, 0, 0);
    Point3D d3(4, 0, 0);
    Point3D d4(5, 0, 0);
    Point3D d5(10, 0, 0);

    Sphere e1(d1, 4);
    Sphere e2(d1, 4);
    Sphere e3(d1, 5);
    Sphere e4(d2, 7);
    Sphere e5(d1, 10);
    Sphere e6(d3, 6);
    Sphere e7(d1, 6);
    Sphere e8(d4, 4);
    Sphere e9(d1, 3);
    Sphere e10(d5, 4);

    Status SCoincidence = CheckingStatus(e1, e2);
    Status SExternalTouch = CheckingStatus(e3, e4);
    Status SInnerTouch = CheckingStatus(e5, e6);
    Status SIntersecting = CheckingStatus(e7, e8);
    Status SNotIntersecting1 = CheckingStatus(e9, e10);

    std::cout << "Sphere Coincidence: " << SCoincidence << std::endl;
    std::cout << "Sphere External Touch: " << SExternalTouch << std::endl;
    std::cout << "Sphere Inner Touch: " << SInnerTouch << std::endl;
    std::cout << "Sphere Intersecting: " << SIntersecting << std::endl;
    std::cout << "Sphere Not Intersecting: " << SNotIntersecting1 << std::endl;
    return 0;
}

#endif  // EASY_EXAMPLE

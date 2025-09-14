#include <gtest/gtest.h>
#include "../lib_sphere/sphere.h"

#define EPSILON 0.000001

TEST(TestSphereLib, can_construct_true) {
    // Act & Assert
    Point3D point(3, 4, 5);
    ASSERT_NO_THROW(Sphere(point, 4));
}
TEST(TestSphereLib, can_construct_false) {
    // Act & Assert
    Point3D point(3, 4, 5);
    ASSERT_ANY_THROW(Sphere(point, -4));
}
TEST(TestSphereLib, comparison_true) {
    // Arrange
    Point3D point_1(3, 4, 5);
    Sphere sphere_1(point_1, 4);
    // Act
    bool actual_result = (sphere_1 == sphere_1);

    // Assert
    bool expected_result = true;
    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestSphereLib, comparison_false) {
    // Arrange
    Point3D num_1(3, 4, 5);
    Point3D num_2(5, 6, 5);
    Sphere sphere_1(num_1, 5);
    Sphere sphere_2(num_2, 7);

    // Act
    bool actual_result = (sphere_1 == sphere_2);

    // Assert
    bool expected_result = false;
    EXPECT_EQ(expected_result, actual_result);
}

#include <gtest/gtest.h>
#include "../lib_sphere/sphere.h"

#define EPSILON 0.000001

TEST(TestSphereLib, can_construct_default) {
    // Act & Assert
    Sphere sphere;

    // Assert
    EXPECT_EQ(Point3D(0, 0, 0), sphere.get_point3D());
    EXPECT_EQ(0, sphere.get_radius());
}
TEST(TestSphereeLib, can_create_with_init_construct) {
    // Act & Assert
    Point3D point3d(3, 4, 5);
    Sphere sphere(point3d, 7);

    // Assert
    EXPECT_EQ(point3d, sphere.get_point3D());
    EXPECT_EQ(7, sphere.get_radius());
}
TEST(TestSphereLib, throw_when_try_create_with_negative_radius) {
    // Act & Assert
    Point3D point(3, 4, 5);
    ASSERT_ANY_THROW(Sphere(point, -4));
}
TEST(TestSphereLib, can_compare_equals_objects_correctly) {
    // Arrange
    Point3D point_1(3, 4, 5);
    Sphere sphere_1(point_1, 4);

    EXPECT_TRUE(sphere_1 == sphere_1);
}

TEST(TestSphereLib, comparison_false) {
    // Arrange
    Point3D num_1(3, 4, 5);
    Point3D num_2(5, 6, 5);
    Sphere sphere_1(num_1, 5);
    Sphere sphere_2(num_2, 7);

    EXPECT_FALSE(sphere_1 == sphere_2);
}

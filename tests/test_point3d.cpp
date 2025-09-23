#include <gtest/gtest.h>
#include "../lib_point3d/point3d.h"

#define EPSILON 0.000001

TEST(TestPoint3DLib, can_construct_default) {
    // Act & Assert
    Point3D point3d;

    // Assert
    EXPECT_EQ(0, point3d.get_x());
    EXPECT_EQ(0, point3d.get_y());
    EXPECT_EQ(0, point3d.get_z());
}

TEST(TestPoint3DLib, can_create_with_init_construct) {
    // Act & Assert
    Point3D point3d(3, 4, 5);
    EXPECT_EQ(3, point3d.get_x());
    EXPECT_EQ(4, point3d.get_y());
    EXPECT_EQ(5, point3d.get_z());
}
TEST(TestPoint3DLib, can_compare_equals_objects_correctly) {
    // Arrange
    Point3D point3d(3, 4, 5);

    EXPECT_TRUE(point3d == point3d);
}

TEST(TestPoint3DLib, can_compare_not_equals_objects_correctly) {
    // Arrange
    Point3D point3d_1(3, 4, 6);
    Point3D point3d_2(5, 6, 7);

    EXPECT_FALSE(point3d_1 == point3d_2);
}
TEST(TestPoint3DLib, copy_constructor) {
    // Arrange
    Point3D point3d_1(3, 4, 5);
    Point3D point3d_2(point3d_1);

    EXPECT_TRUE(point3d_1 == point3d_2);
}
TEST(TestPoint3DLib, distance_between_points) {
    // Arrange
    Point3D point3d_1(1, 2, 3);
    Point3D point3d_2(3, 5, 9);

   
    EXPECT_EQ(7, point3d_1.DistanceBetweenPoints(point3d_2));
}
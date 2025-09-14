#include <gtest/gtest.h>
#include "../lib_point3d/point3d.h"

#define EPSILON 0.000001

TEST(TestPoint3DLib, can_construct) {
    // Act & Assert
    ASSERT_NO_THROW(Point3D(3, 4, 5));
}
TEST(TestPoint3DLib, comparison_true) {
    // Arrange
    Point3D num_1(3, 4, 5);

    // Act
    bool actual_result = (num_1 == num_1);

    // Assert
    bool expected_result = true;
    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestPoint3DLib, comparison_false) {
    // Arrange
    Point3D num_1(3, 4, 6);
    Point3D num_2(5, 6, 7);

    // Act
    bool actual_result = (num_1 == num_2);

    // Assert
    bool expected_result = false;
    EXPECT_EQ(expected_result, actual_result);
}
TEST(TestPoint3DLib, copy_constructor) {
    // Arrange
    Point3D num_1(3, 4, 5);
    Point3D num_2(num_1);

    // Act
    bool actual_result = (num_1 == num_2);

    // Assert
    bool expected_result = true;
    EXPECT_EQ(expected_result, actual_result);
}
TEST(TestPoint3DLib, distance_between_points) {
    // Arrange
    Point3D num_1(1, 2, 3);
    Point3D num_2(3, 5, 9);

    // Act
    int actual_result = (num_1.DistanceBetweenPoints(num_2));

    // Assert
    int expected_result = 7;
    EXPECT_EQ(expected_result, actual_result);
}
#include <gtest/gtest.h>
#include "../lib_point/point.h"

#define EPSILON 0.000001

TEST(TestPointLib, can_construct_default) {
    // Act & Assert
    Point point;

    // Assert
    EXPECT_EQ(0, point.get_x());
    EXPECT_EQ(0, point.get_y());
}
TEST(TestPointLib, can_create_with_init_construct) {
    // Act & Assert
    Point point(3, 4);
    EXPECT_EQ(3, point.get_x());
    EXPECT_EQ(4, point.get_y());
}
TEST(TestPointLib, can_compare_equals_objects_correctly) {
    // Arrange
    Point num_1(3, 4);

    // Act

    EXPECT_TRUE(num_1 == num_1);
}

TEST(TestPointLib, can_compare_not_equals_objects_correctly) {
    // Arrange
    Point num_1(3, 4);
    Point num_2(5, 6);

    EXPECT_FALSE(num_1 == num_2);
}
TEST(TestPointLib, copy_constructor) {
    // Arrange
    Point num_1(3, 4);
    Point num_2(num_1);

    EXPECT_TRUE(num_1 == num_2);
}
TEST(TestPointLib, distance_between_points) {
    // Arrange
    Point num_1(2, 3);
    Point num_2(5, 7);


    // Assert
    EXPECT_EQ(5, num_1.DistanceBetweenPoints(num_2));
}
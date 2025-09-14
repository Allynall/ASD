#include <gtest/gtest.h>
#include "../lib_point/point.h"

#define EPSILON 0.000001

TEST(TestPointLib, can_construct) {
	// Act & Assert
	ASSERT_NO_THROW(Point(3, 4));
}
TEST(TestPointLib, comparison_true) {
    // Arrange
    Point num_1(3, 4);

    // Act
    bool actual_result = (num_1 == num_1);

    // Assert
    bool expected_result = true;
    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestPointLib, comparison_false) {
    // Arrange
    Point num_1(3, 4);
    Point num_2(5, 6);

    // Act
    bool actual_result = (num_1 == num_2);

    // Assert
    bool expected_result = false;
    EXPECT_EQ(expected_result, actual_result);
}
TEST(TestPointLib, copy_constructor) {
    // Arrange
    Point num_1(3, 4);
    Point num_2(num_1);

    // Act
    bool actual_result = (num_1 == num_2);

    // Assert
    bool expected_result = true;
    EXPECT_EQ(expected_result, actual_result);
}
TEST(TestPointLib, distance_between_points) {
    // Arrange
    Point num_1(2, 3);
    Point num_2(5, 7);

    // Act
    int actual_result = (num_1.DistanceBetweenPoints(num_2));

    // Assert
    int expected_result = 5;
    EXPECT_EQ(expected_result, actual_result);
}
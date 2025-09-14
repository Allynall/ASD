#include <gtest/gtest.h>
#include "../lib_circle/circle.h"

#define EPSILON 0.000001

TEST(TestCircleLib, can_construct_true) {
    // Act & Assert
    Point point(3, 4);
    ASSERT_NO_THROW(Circle(point, 4));
}
TEST(TestCircleLib, can_construct_false) {
    // Act & Assert
    Point point(3, 4);
    ASSERT_ANY_THROW(Circle(point, -4));
}
TEST(TestCircleLib, comparison_true) {
    // Arrange
    Point point_1(3, 4);
    Circle circle_1(point_1, 4);
    // Act
    bool actual_result = (circle_1 == circle_1);

    // Assert
    bool expected_result = true;
    EXPECT_EQ(expected_result, actual_result);
}

TEST(TestCircleLib, comparison_false) {
    // Arrange
    Point num_1(3, 4);
    Point num_2(5, 6);
    Circle circle_1(num_1, 5);
    Circle circle_2(num_2, 7);

    // Act
    bool actual_result = (circle_1 == circle_2);

    // Assert
    bool expected_result = false;
    EXPECT_EQ(expected_result, actual_result);
}

#include <gtest/gtest.h>
#include "../lib_circle/circle.h"

#define EPSILON 0.000001

TEST(TestCircleLib, can_construct_default) {
    // Act & Assert
    Circle circle;
    
    // Assert
    EXPECT_EQ(Point(0, 0), circle.get_point());
    EXPECT_EQ(0, circle.get_radius());
}

TEST(TestCircleLib, can_create_with_init_construct) {
    // Act & Assert
    Point point(3, 4);
    Circle circle(point, 5);

    // Assert
    EXPECT_EQ(point, circle.get_point());
    EXPECT_EQ(5, circle.get_radius());
}
TEST(TestCircleLib, throw_when_try_create_with_negative_radius) 
{
    // Act & Assert
    Point point(3, 4);
    ASSERT_ANY_THROW(Circle(point, -4));
}
TEST(TestCircleLib, can_compare_equals_objects_correctly) {
    // Arrange
    Point point_1(3, 4);
    Circle circle_1(point_1, 4);

    // Act and Assert
    EXPECT_TRUE(circle_1 == circle_1);
}

TEST(TestCircleLib, can_compare_not_equals_objects_correctly) {
    // Arrange
    Point num_1(3, 4);
    Point num_2(5, 6);
    Circle circle_1(num_1, 5);
    Circle circle_2(num_2, 7);

    // Act
    EXPECT_FALSE(circle_1 == circle_2);
}

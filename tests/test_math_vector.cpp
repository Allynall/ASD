#include <gtest/gtest.h>
#include "../lib_math_vector/math_vector.h"

TEST(TestMVectorLib, default_constructor) {
    // Arrange
    MVector<int> vec1;

    // Assert
    EXPECT_TRUE(vec1.is_empty());
    EXPECT_EQ(0, vec1.size());
    EXPECT_EQ(15, vec1.capacity());
}
TEST(TestMVectorLib, constructor_with_parameters) {
    // Arrange
    MVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    // Assert
    EXPECT_FALSE(vec1.is_empty());
    EXPECT_EQ(14, vec1.size());
    EXPECT_EQ(1, vec1.front());
    EXPECT_EQ(14, vec1.back());
}
TEST(TestMVectorLib, size_constructor) {
    // Arrange
    MVector<int> vec1(14);

    // Assert
    EXPECT_TRUE(vec1.is_empty());
    EXPECT_EQ(14, vec1.size());
    EXPECT_EQ(15, vec1.capacity());
}
TEST(TestMVectorLib, mult_with_scalar) {
    // Arrange
    MVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    //Act
    vec1 = vec1 * 5;
    // Assert
    EXPECT_FALSE(vec1.is_empty());
    EXPECT_EQ(14, vec1.size());
    EXPECT_EQ(5, vec1.front());
    EXPECT_EQ(40, vec1[7]);
    EXPECT_EQ(70, vec1.back());
}
TEST(TestMVectorLib, div_with_scalar) {
    // Arrange
    MVector<int> vec1({ 2, 4, 6, 8, 10, 12 });

    //Act
    vec1 = vec1 / 2;
    // Assert
    EXPECT_FALSE(vec1.is_empty());
    EXPECT_EQ(6, vec1.size());
    EXPECT_EQ(1, vec1.front());
    EXPECT_EQ(4, vec1[3]);
    EXPECT_EQ(6, vec1.back());
}
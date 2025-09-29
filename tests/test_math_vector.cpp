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
TEST(TestMVectorLib, copy_constructor) {
    // Arrange
    MVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 }), vec2(vec1);

    // Assert
    EXPECT_FALSE(vec2.is_empty());
    EXPECT_EQ(14, vec2.size());
    EXPECT_EQ(15, vec2.capacity());
    EXPECT_EQ(1, vec2.front());
    EXPECT_EQ(8, vec2[7]);
    EXPECT_EQ(14, vec2.back());
}
TEST(TestMVectorLib, mult_with_scalar_old) {
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
TEST(TestMVectorLib, mult_with_scalar_new) {
    // Arrange
    MVector<int> vec1({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 });

    //Act
    MVector<int> vec2 = vec1 * 5;
    // Assert
    EXPECT_FALSE(vec2.is_empty());
    EXPECT_EQ(14, vec2.size());
    EXPECT_EQ(5, vec2.front());
    EXPECT_EQ(40, vec2[7]);
    EXPECT_EQ(70, vec2.back());
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
TEST(TestMVectorLib, Throw_from_add_vector_any_size) {
    // Arrange
    MVector<int> vec1({ 2, 4, 6, 8, 10, 12 }), vec2({ 1, 2 });

    // Assert
    ASSERT_ANY_THROW(vec1 + vec2);
}
TEST(TestMVectorLib, add_vector_old) {
    // Arrange
    MVector<int> vec1({ 2, 4, 6 }), vec2({ 1, 2, 3});

    //Act
    vec1 = vec1 + vec2;
    // Assert
    EXPECT_FALSE(vec1.is_empty());
    EXPECT_EQ(3, vec1.size());
    EXPECT_EQ(3, vec1.front());
    EXPECT_EQ(6, vec1[1]);
    EXPECT_EQ(9, vec1.back());
}
TEST(TestMVectorLib, add_vector_new) {
    // Arrange
    MVector<int> vec1({ 2, 4, 6 }), vec2({ 1, 2, 3 });

    //Act
    MVector<int> vec3 = vec1 + vec2;
    // Assert
    EXPECT_FALSE(vec3.is_empty());
    EXPECT_EQ(3, vec3.size());
    EXPECT_EQ(3, vec3.front());
    EXPECT_EQ(6, vec3[1]);
    EXPECT_EQ(9, vec3.back());
}
TEST(TestMVectorLib, Throw_from_sub_vector_any_size) {
    // Arrange
    MVector<int> vec1({ 2, 4, 6, 8, 10, 12 }), vec2({ 1, 2 });

    // Assert
    ASSERT_ANY_THROW(vec1 - vec2);
}
TEST(TestMVectorLib, sub_vector_old) {
    // Arrange
    MVector<int> vec1({ 3, 5, 7 }), vec2({ 1, 2, 3 });

    //Act
    vec1 = vec1 - vec2;
    // Assert
    EXPECT_FALSE(vec1.is_empty());
    EXPECT_EQ(3, vec1.size());
    EXPECT_EQ(2, vec1.front());
    EXPECT_EQ(3, vec1[1]);
    EXPECT_EQ(4, vec1.back());
}
TEST(TestMVectorLib, sub_vector_new) {
    // Arrange
    MVector<int> vec1({ 3, 5, 7 }), vec2({ 1, 2, 3 });

    //Act
    MVector<int> vec3 = vec1 - vec2;
    // Assert
    EXPECT_FALSE(vec1.is_empty());
    EXPECT_EQ(3, vec1.size());
    EXPECT_EQ(2, vec1.front());
    EXPECT_EQ(3, vec1[1]);
    EXPECT_EQ(4, vec1.back());
}
TEST(TestMVectorLib, Throw_from_mult_vector_any_size) {
    // Arrange
    MVector<int> vec1({ 2, 4, 6, 8, 10, 12 }), vec2({ 1, 2 });

    // Assert
    ASSERT_ANY_THROW(vec1 * vec2);
}
TEST(TestMVectorLib, mult_vector_with_vector) {
    // Arrange
    MVector<int> vec1({ 3, 5, 7 }), vec2({ 1, 2, 3 });

    //Act
    int res = vec1 * vec2;
    // Assert
    EXPECT_EQ(34, res);
    EXPECT_EQ(3, vec1.front());
    EXPECT_EQ(1, vec2.front());
}

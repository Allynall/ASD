#include <gtest/gtest.h>
#include "../lib_stack/stack.h"

TEST(TestStackLib, default_constructor) {
    // Arrange
    Stack<int> stack;

    ASSERT_NO_THROW(Stack<int> stack);
    EXPECT_EQ(0, stack.get_size());
    EXPECT_EQ(-1, stack.get_top());
}

TEST(TestStackLib, throw_negative_size) {
    // Arrange

    ASSERT_ANY_THROW(Stack<int> stack(-2));
}
TEST(TestStackLib, size_constructor) {
    // Arrange
    Stack<int> stack(2);

    ASSERT_NO_THROW(Stack<int> stack(2));
    EXPECT_EQ(2, stack.get_size());
    EXPECT_EQ(-1, stack.get_top());
}
TEST(TestStackLib, copy_constructor) {
    // Arrange
    Stack<int> stack_1(2), stack_2(stack_1);

    ASSERT_NO_THROW(Stack<int> stack_2(stack_1));
    EXPECT_EQ(2, stack_2.get_size());
    EXPECT_EQ(-1, stack_2.get_top());
}
TEST(TestStackLib, stack_is_empty_true) {
    // Arrange
    Stack<int> stack_1;

    EXPECT_EQ(true, stack_1.is_empty());
}
TEST(TestStackLib, stack_is_empty_false) {
    // Arrange
    Stack<int> stack_1(2);
    stack_1.push(2);

    EXPECT_EQ(false, stack_1.is_empty());
}

TEST(TestStackLib, stack_is_full_true) {
    // Arrange
    Stack<int> stack_1(2);
    stack_1.push(2);
    stack_1.push(3);

    EXPECT_EQ(true, stack_1.is_full());
}
TEST(TestStackLib, stack_is_full_false) {
    Stack<int> stack_1(2);
    stack_1.push(2);

    EXPECT_EQ(false, stack_1.is_full());
}
TEST(TestStackLib, top_in_empty_stack) {
    // Arrange
    Stack<int> stack_1(2);

    ASSERT_ANY_THROW(stack_1.top());
}
TEST(TestStackLib, top_in_stack) {
    // Arrange
    Stack<int> stack_1(3);
    stack_1.push(3);
    stack_1.push(7);
    stack_1.pop();
    stack_1.push(8);

    EXPECT_EQ(3, stack_1.get_size());
    EXPECT_EQ(1, stack_1.get_top());
    EXPECT_EQ(8, stack_1.top());
}
TEST(TestStackLib, push_in_full_stack) {
    // Arrange
    Stack<int> stack_1(2);
    stack_1.push(2);
    stack_1.push(2);

    ASSERT_ANY_THROW(stack_1.push(2));
}
TEST(TestStackLib, push_in_stack) {
    // Arrange
    Stack<int> stack_1(3);
    stack_1.push(3);
    stack_1.push(7);

    EXPECT_EQ(3, stack_1.get_size());
    EXPECT_EQ(1, stack_1.get_top());
    EXPECT_EQ(7, stack_1.top());
}
TEST(TestStackLib, pop_in_empty_stack) {
    // Arrange
    Stack<int> stack_1(2);

    ASSERT_ANY_THROW(stack_1.pop());
}
TEST(TestStackLib, pop_in_stack) {
    // Arrange
    Stack<int> stack_1(3);
    stack_1.push(3);
    stack_1.push(7);
    stack_1.pop();

    EXPECT_EQ(3, stack_1.get_size());
    EXPECT_EQ(0, stack_1.get_top());
    EXPECT_EQ(3, stack_1.top());
}
TEST(TestStackLib, clear_stack) {
    // Arrange
    Stack<int> stack_1(3);
    stack_1.push(3);
    stack_1.push(7);
    stack_1.clear();

    EXPECT_EQ(3, stack_1.get_size());
    EXPECT_EQ(-1, stack_1.get_top());
    ASSERT_ANY_THROW(stack_1.top());
}
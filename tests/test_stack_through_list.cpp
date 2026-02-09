#include <gtest/gtest.h>
#include "../lib_stack_through_list/stack_through_list .h"

TEST(TestStackThroughListLib, default_constructor) {
    // Arrange
    StackThroughList<int> stack;

    ASSERT_NO_THROW(StackThroughList<int> stack);
    EXPECT_EQ(0, stack.get_size());
    EXPECT_EQ(-1, stack.get_top());
}

TEST(TestStackThroughListLib, copy_constructor) {
    // Arrange
    StackThroughList<int> stack_1;
    stack_1.push(2);
    stack_1.push(3);
    StackThroughList<int> stack_2(stack_1);

    ASSERT_NO_THROW(StackThroughList<int> stack_2(stack_1));
    EXPECT_EQ(2, stack_2.get_size());
    EXPECT_EQ(1, stack_2.get_top());
}
TEST(TestStackThroughListLib, stack_is_empty_true) {
    // Arrange
    StackThroughList<int> stack_1;

    EXPECT_EQ(true, stack_1.is_empty());
}
TEST(TestStackThroughListLib, stack_is_empty_false) {
    // Arrange
    StackThroughList<int> stack_1;
    stack_1.push(2);

    EXPECT_EQ(false, stack_1.is_empty());
}

TEST(TestStackThroughListLib, top_in_empty_stack) {
    // Arrange
    StackThroughList<int> stack_1;

    ASSERT_ANY_THROW(stack_1.top());
}
TEST(TestStackThroughListLib, top_in_stack) {
    // Arrange
    StackThroughList<int> stack_1;
    stack_1.push(3);
    stack_1.push(7);
    stack_1.pop();
    stack_1.push(8);

    EXPECT_EQ(2, stack_1.get_size());
    EXPECT_EQ(1, stack_1.get_top());
    EXPECT_EQ(8, stack_1.top());
}
TEST(TestStackThroughListLib, push_in_stack) {
    // Arrange
    StackThroughList<int> stack_1;
    stack_1.push(3);
    stack_1.push(7);

    EXPECT_EQ(2, stack_1.get_size());
    EXPECT_EQ(1, stack_1.get_top());
    EXPECT_EQ(7, stack_1.top());
}
TEST(TestStackThroughListLib, pop_in_empty_stack) {
    // Arrange
    StackThroughList<int> stack_1;

    ASSERT_ANY_THROW(stack_1.pop());
}
TEST(TestStackThroughListLib, pop_in_stack) {
    // Arrange
    StackThroughList<int> stack_1;
    stack_1.push(3);
    stack_1.push(7);
    stack_1.pop();

    EXPECT_EQ(1, stack_1.get_size());
    EXPECT_EQ(0, stack_1.get_top());
    EXPECT_EQ(3, stack_1.top());
}
TEST(TestStackThroughListLib, clear_stack) {
    // Arrange
    StackThroughList<int> stack_1;
    stack_1.push(3);
    stack_1.push(7);
    stack_1.clear();

    EXPECT_EQ(0, stack_1.get_size());
    EXPECT_EQ(-1, stack_1.get_top());
    ASSERT_ANY_THROW(stack_1.top());
}
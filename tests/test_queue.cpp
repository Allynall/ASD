#include <gtest/gtest.h>
#include "../lib_queue/queue.h"

TEST(TestQueueLib, default_constructor) {
    // Arrange
    Queue<int> queue;

    ASSERT_NO_THROW(Queue<int> queue);
    EXPECT_EQ(0, queue.get_size());
    EXPECT_EQ(0, queue.get_head());
    EXPECT_EQ(0, queue.get_count());
}

TEST(TestQueueLib, throw_negative_size) {
    // Arrange

    ASSERT_ANY_THROW(Queue<int> queue(-2));
}
TEST(TestQueueLib, size_constructor) {
    // Arrange
    Queue<int> queue(2);

    ASSERT_NO_THROW(Queue<int> queue(2));
    EXPECT_EQ(2, queue.get_size());
    EXPECT_EQ(0, queue.get_head());
    EXPECT_EQ(0, queue.get_count());
}
TEST(TestQueueLib, copy_constructor) {
    // Arrange
    Queue<int> queue_1(2), queue_2(queue_1);

    ASSERT_NO_THROW(Queue<int> queue_2(queue_1));
    EXPECT_EQ(2, queue_2.get_size());
    EXPECT_EQ(0, queue_2.get_head());
    EXPECT_EQ(0, queue_2.get_count());
}
TEST(TestQueueLib, queue_is_empty_true) {
    // Arrange
    Queue<int> queue_1;

    EXPECT_EQ(true, queue_1.is_empty());
}
TEST(TestQueueLib, stack_is_empty_false) {
    // Arrange
    Queue<int> queue_1(2);
    queue_1.push(2);

    EXPECT_EQ(false, queue_1.is_empty());
}
TEST(TestQueueLib, queue_is_empty_true_after_pop) {
    // Arrange
    Queue<int> queue_1(2);
    queue_1.push(2);
    queue_1.pop();

    EXPECT_EQ(true, queue_1.is_empty());
}
TEST(TestQueueLib, stack_is_full_true) {
    // Arrange
    Queue<int> queue_1(2);
    queue_1.push(2);
    queue_1.push(3);

    EXPECT_EQ(true, queue_1.is_full());
}
TEST(TestQueueLib, stack_is_full_false) {
    Queue<int> queue_1(2);
    queue_1.push(2);

    EXPECT_EQ(false, queue_1.is_full());
}
TEST(TestQueueLib,  head_in_empty_queue) {
    // Arrange
    Queue<int> queue_1(2);

    ASSERT_ANY_THROW(queue_1.head());
}
TEST(TestQueueLib, head_in_queue) {
    // Arrange
    Queue<int> queue_1(3);
    queue_1.push(3);    //78
    queue_1.push(7);
    queue_1.pop();
    queue_1.push(8);

    EXPECT_EQ(7, queue_1.head());
    EXPECT_EQ(8, queue_1.tail());
    EXPECT_EQ(2, queue_1.get_count());
}
TEST(TestQueueLib, push_in_full_queue) {
    // Arrange
    Queue<int> queue_1(2);
    queue_1.push(2);
    queue_1.push(2);

    ASSERT_ANY_THROW(queue_1.push(2));
}
TEST(TestQueueLib, push_in_queue) {
    // Arrange
    Queue<int> queue_1(2);
    queue_1.push(3);
    queue_1.push(8);

    EXPECT_EQ(2, queue_1.get_size());
    EXPECT_EQ(3, queue_1.head());
    EXPECT_EQ(8, queue_1.tail());
    EXPECT_EQ(2, queue_1.get_count());
}
TEST(TestQueueLib, pop_in_empty_queue) {
    // Arrange
    Queue<int> queue_1(2);
    queue_1.push(3);
    queue_1.push(8);
    queue_1.pop();
    queue_1.pop();

    ASSERT_ANY_THROW(queue_1.pop());
}
TEST(TestQueueLib, pop_in_queue) {
    // Arrange
    Queue<int> queue_1(5);
    queue_1.push(3);
    queue_1.push(8); 
    queue_1.pop();
    queue_1.push(9);
    queue_1.push(7);


    EXPECT_EQ(5, queue_1.get_size());
    EXPECT_EQ(8, queue_1.head());
    EXPECT_EQ(7, queue_1.tail());
    EXPECT_EQ(3, queue_1.get_count());
}
TEST(TestQueueLib, clear_stack) {
    // Arrange
    Queue<int> queue_1(3);
    queue_1.push(3);
    queue_1.push(7);
    queue_1.clear();

    EXPECT_EQ(3, queue_1.get_size());
    EXPECT_EQ(0, queue_1.get_count());
    ASSERT_ANY_THROW(queue_1.head());
    ASSERT_ANY_THROW(queue_1.tail());
}
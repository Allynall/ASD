#include <gtest/gtest.h>
#include "../lib_queue_through_list/queue_through_list.h"

TEST(TestQueueThroughListLib, default_constructor) {
    // Arrange
    QueueThroughList<int> queue;

    ASSERT_NO_THROW(QueueThroughList<int> queue);
    EXPECT_EQ(0, queue.get_size());
    EXPECT_EQ(0, queue.get_head());
    EXPECT_EQ(0, queue.get_count());
}
TEST(TestQueueThroughListLib, copy_constructor) {
    // Arrange
    QueueThroughList<int> queue_1, queue_2(queue_1);

    ASSERT_NO_THROW(QueueThroughList<int> queue_2(queue_1));
    EXPECT_EQ(0, queue_2.get_size());
    EXPECT_EQ(0, queue_2.get_head());
    EXPECT_EQ(0, queue_2.get_count());
}
TEST(TestQueueThroughListLib, queue_is_empty_true) {
    // Arrange
    QueueThroughList<int> queue_1;

    EXPECT_EQ(true, queue_1.is_empty());
}
TEST(TestQueueThroughListLib, stack_is_empty_false) {
    // Arrange
    QueueThroughList<int> queue_1;
    queue_1.push(2);

    EXPECT_EQ(false, queue_1.is_empty());
}
TEST(TestQueueThroughListLib, queue_is_empty_true_after_pop) {
    // Arrange
    QueueThroughList<int> queue_1;
    queue_1.push(2);
    queue_1.pop();

    EXPECT_EQ(true, queue_1.is_empty());
}

TEST(TestQueueThroughListLib, head_in_empty_queue) {
    // Arrange
    QueueThroughList<int> queue_1;

    ASSERT_ANY_THROW(queue_1.head());
}
TEST(TestQueueThroughListLib, head_in_queue) {
    // Arrange
    QueueThroughList<int> queue_1;
    queue_1.push(3);    //78
    queue_1.push(7);
    queue_1.pop();
    queue_1.push(8);

    EXPECT_EQ(7, queue_1.head());
    /*EXPECT_EQ(8, queue_1.tail());*/
    EXPECT_EQ(2, queue_1.get_count());
}
TEST(TestQueueThroughListLib, tail_in_empty_queue) {
    // Arrange
    QueueThroughList<int> queue_1;

    ASSERT_ANY_THROW(queue_1.tail());
}
TEST(TestQueueThroughListLib, tail_in_queue) {
    // Arrange
    QueueThroughList<int> queue_1;
    queue_1.push(3);    //78
    queue_1.push(7);
    queue_1.pop();
    queue_1.push(8);

    /*EXPECT_EQ(7, queue_1.head());*/
    EXPECT_EQ(8, queue_1.tail());
    EXPECT_EQ(2, queue_1.get_count());
}
TEST(TestQueueThroughListLib, push_in_queue) {
    // Arrange
    QueueThroughList<int> queue_1;
    queue_1.push(3);
    queue_1.push(8);

    EXPECT_EQ(2, queue_1.get_size());
    EXPECT_EQ(3, queue_1.head());
    EXPECT_EQ(8, queue_1.tail());
    EXPECT_EQ(2, queue_1.get_count());
}
TEST(TestQueueThroughListLib, pop_in_queue) {
    // Arrange
    QueueThroughList<int> queue_1;
    queue_1.push(3);
    queue_1.push(8);
    queue_1.pop();
    queue_1.push(9);
    queue_1.push(7);


    EXPECT_EQ(3, queue_1.get_size());
    EXPECT_EQ(8, queue_1.head());
    EXPECT_EQ(7, queue_1.tail());
    EXPECT_EQ(3, queue_1.get_count());
}
TEST(TestQueueThroughListLib, clear_stack) {
    // Arrange
    QueueThroughList<int> queue_1;
    queue_1.push(3);
    queue_1.push(7);
    queue_1.clear();

    EXPECT_EQ(0, queue_1.get_size());
    EXPECT_EQ(0, queue_1.get_count());
    ASSERT_ANY_THROW(queue_1.head());
    ASSERT_ANY_THROW(queue_1.tail());
}
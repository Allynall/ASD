#include <gtest/gtest.h>
#include "../lib_doubly_linked_list/doubly_linked_list.h"
#include "../lib_tvector/tvector.h"

TEST(TestDoublyLinkedListLib, default_constructor) {
    // Arrange
    DoublyLinkedList<int> list;

    EXPECT_EQ(0, list.count());
    EXPECT_EQ(nullptr, list.head());
    EXPECT_EQ(nullptr, list.tail());
}
TEST(TestDoublyLinkedListLib, copy_constructor) {
    // Arrange
    DoublyLinkedList<int> list_1;
    list_1.push_front(5);
    list_1.push_front(6);
    DoublyLinkedList<int> list_2(list_1);

    EXPECT_EQ(2, list_2.count());
    EXPECT_EQ(6, list_2.head()->value);
    EXPECT_EQ(6, list_2.tail()->prev->value);
    EXPECT_EQ(5, list_2.tail()->value);
}

TEST(TestDoublyLinkedListLib, is_empty_true) {
    // Arrange
    DoublyLinkedList<int> list;

    EXPECT_TRUE(list.is_empty());
}

TEST(TestDoublyLinkedListLib, is_empty_false) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_front(5);

    EXPECT_FALSE(list.is_empty());
}

TEST(TestDoublyLinkedListLib, clear) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_front(5);
    list.clear();

    EXPECT_TRUE(list.is_empty());
}
TEST(TestDoublyLinkedListLib, count) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_front(5);
    list.push_front(7);

    EXPECT_EQ(2, list.count());
}
TEST(TestDoublyLinkedListLib, count_empty) {
    // Arrange
    DoublyLinkedList<int> list;

    EXPECT_EQ(0, list.count());
}
TEST(TestDoublyLinkedListLib, count_after_clear) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_front(5);
    list.clear();

    EXPECT_EQ(0, list.count());
}

TEST(TestDoublyLinkedListLib, head) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_front(5);
    list.push_front(7);

    EXPECT_EQ(7, list.head()->value);
}

TEST(TestDoublyLinkedListLib, tail) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_front(5);
    list.push_front(7);

    EXPECT_EQ(5, list.tail()->value);
    EXPECT_EQ(7, list.tail()->prev->value);
}
TEST(TestDoublyLinkedListLib, push_front) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_front(5);
    list.push_front(6);

    EXPECT_EQ(2, list.count());
    EXPECT_EQ(6, list.head()->value);
    EXPECT_EQ(5, list.tail()->value);
    EXPECT_EQ(6, list.tail()->prev->value);
}

TEST(TestDoublyLinkedListLib, push_back) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_back(5);
    list.push_back(6);

    EXPECT_EQ(2, list.count());
    EXPECT_EQ(5, list.head()->value);
    EXPECT_EQ(6, list.tail()->value);
    EXPECT_EQ(5, list.tail()->prev->value);
}

TEST(TestDoublyLinkedListLib, push_front_back) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_back(5);
    list.push_front(7);

    EXPECT_EQ(2, list.count());
    EXPECT_EQ(7, list.head()->value);
    EXPECT_EQ(5, list.tail()->value);
    EXPECT_EQ(7, list.tail()->prev->value);
}
TEST(TestDoublyLinkedListLib, insert_adress_throw) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_back(5);
    ASSERT_ANY_THROW(list.insert(list.head()->next, 8););
}

TEST(TestDoublyLinkedListLib, insert_adress) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_front(9);
    list.push_back(5);
    list.push_back(6);
    list.insert(list.head()->next, 8);

    EXPECT_EQ(4, list.count());
    EXPECT_EQ(9, list.head()->value);
    EXPECT_EQ(6, list.tail()->value);
    EXPECT_EQ(5, list.tail()->prev->value);
}

TEST(TestDoublyLinkedListLib, insert_pos_throw) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_back(5);
    ASSERT_ANY_THROW(list.insert(5, 8));
}

TEST(TestDoublyLinkedListLib, insert_pos) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_front(9);
    list.push_back(5);
    list.push_back(6);
    list.insert(2, 8);

    EXPECT_EQ(4, list.count());
    EXPECT_EQ(9, list.head()->value);
    EXPECT_EQ(6, list.tail()->value);
    EXPECT_EQ(5, list.tail()->prev->value);
}

TEST(TestDoublyLinkedListLib, pop_front) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_back(5);
    list.push_back(7);
    list.push_back(8);
    list.pop_front();

    EXPECT_EQ(2, list.count());
    EXPECT_EQ(7, list.head()->value);
    EXPECT_EQ(8, list.tail()->value);
    EXPECT_EQ(nullptr, list.head()->prev);
}
TEST(TestDoublyLinkedListLib, pop_front_throw) {
    // Arrange
    DoublyLinkedList<int> list;

    ASSERT_ANY_THROW(list.pop_front());
}
TEST(TestDoublyLinkedListLib, pop_back) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_back(5);
    list.push_back(7);
    list.push_back(8);
    list.pop_back();

    EXPECT_EQ(2, list.count());
    EXPECT_EQ(5, list.head()->value);
    EXPECT_EQ(7, list.tail()->value);
    EXPECT_EQ(5, list.tail()->prev->value);
}
TEST(TestDoublyLinkedListLib, pop_back_throw) {
    // Arrange
    DoublyLinkedList<int> list;

    ASSERT_ANY_THROW(list.pop_back());
}
TEST(TestDoublyLinkedListLib, erase_adress) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_front(9);
    list.push_back(5);
    list.push_back(6);
    list.erase(list.head()->next);

    //std::cout << list;
    EXPECT_EQ(2, list.count());
    EXPECT_EQ(9, list.head()->value);
    EXPECT_EQ(6, list.tail()->value);
    EXPECT_EQ(9, list.tail()->prev->value);
}
TEST(TestDoublyLinkedListLib, erase_pos_throw) {
    // Arrange
    DoublyLinkedList<int> list;
    ASSERT_ANY_THROW(list.erase(4));
}

TEST(TestDoublyLinkedListLib, erase_pos) {
    // Arrange
    DoublyLinkedList<int> list;
    list.push_front(9);
    list.push_back(5);
    list.push_back(6);
    list.erase(1);

    EXPECT_EQ(2, list.count());
    EXPECT_EQ(9, list.head()->value);
    EXPECT_EQ(6, list.tail()->value);
    EXPECT_EQ(9, list.tail()->prev->value);
}
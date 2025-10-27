#include <gtest/gtest.h>
#include "../lib_list/list.h"

TEST(TestListLib, default_constructor) {
    // Arrange
    List<int> list;

    EXPECT_EQ(0, list.count());
    EXPECT_EQ(nullptr, list.head());
    EXPECT_EQ(nullptr, list.tail());
}

TEST(TestListLib, copy_constructor) {
    // Arrange
    List<int> list_1;
    list_1.push_front(5);
    list_1.push_front(6);
    List<int> list_2(list_1);

    EXPECT_EQ(2, list_2.count());
    EXPECT_EQ(6, list_2.head()->value);
    EXPECT_EQ(5, list_2.tail()->value);
}

TEST(TestListLib, is_empty_true) {
    // Arrange
    List<int> list;

    EXPECT_TRUE(list.is_empty());
}
TEST(TestListLib, is_empty_false) {
    // Arrange
    List<int> list;
    list.push_front(5);

    EXPECT_FALSE(list.is_empty());
}

TEST(TestListLib, clear) {
    // Arrange
    List<int> list;
    list.push_front(5);
    list.clear();

    EXPECT_TRUE(list.is_empty());
}
TEST(TestListLib, count) {
    // Arrange
    List<int> list;
    list.push_front(5);
    list.push_front(7);

    EXPECT_EQ(2, list.count());
}
TEST(TestListLib, count_empty) {
    // Arrange
    List<int> list;

    EXPECT_EQ(0, list.count());
}
TEST(TestListLib, count_after_clear) {
    // Arrange
    List<int> list;
    list.push_front(5);
    list.clear();

    EXPECT_EQ(0, list.count());
}

TEST(TestListLib, head) {
    // Arrange
    List<int> list;
    list.push_front(5);
    list.push_front(7);

    EXPECT_EQ(7, list.head()->value);
}

TEST(TestListLib, tail) {
    // Arrange
    List<int> list;
    list.push_front(5);
    list.push_front(7);

    EXPECT_EQ(5, list.tail()->value);
}
TEST(TestListLib, push_front) {
    // Arrange
    List<int> list;
    list.push_front(5);
    list.push_front(6);

    EXPECT_EQ(2, list.count());
    EXPECT_EQ(6, list.head()->value);
    EXPECT_EQ(5, list.tail()->value);
}

TEST(TestListLib, push_back) {
    // Arrange
    List<int> list;
    list.push_back(5);
    list.push_back(6);

    EXPECT_EQ(2, list.count());
    EXPECT_EQ(5, list.head()->value);
    EXPECT_EQ(6, list.tail()->value);
}

TEST(TestListLib, push_front_back) {
    // Arrange
    List<int> list;
    list.push_back(5);
    list.push_front(7);

    EXPECT_EQ(2, list.count());
    EXPECT_EQ(7, list.head()->value);
    EXPECT_EQ(5, list.tail()->value);
}
TEST(TestListLib,insert_adress_throw) {
    // Arrange
    List<int> list;
    list.push_back(5);
    ASSERT_ANY_THROW(list.insert(list.head()->next, 8););
}

TEST(TestListLib, insert_adress) {
    // Arrange
    List<int> list;
    list.push_front(9);
    list.push_back(5);
    list.push_back(6);
    list.insert(list.head()->next, 8);

    EXPECT_EQ(4, list.count());
    EXPECT_EQ(9, list.head()->value);
    EXPECT_EQ(6, list.tail()->value);
}

TEST(TestListLib, insert_pos_throw) {
    // Arrange
    List<int> list;
    list.push_back(5);
    ASSERT_ANY_THROW(list.insert(5, 8));
}

TEST(TestListLib, insert_pos) {
    // Arrange
    List<int> list;
    list.push_front(9);
    list.push_back(5);
    list.push_back(6);
    list.insert(2, 8);

    EXPECT_EQ(4, list.count());
    EXPECT_EQ(9, list.head()->value);
    EXPECT_EQ(6, list.tail()->value);
}
TEST(TestListLib, pop_front) {
    // Arrange
    List<int> list;
    list.push_back(5);
    list.push_back(7);
    list.push_back(8);
    list.pop_front();

    EXPECT_EQ(2, list.count());
    EXPECT_EQ(7, list.head()->value);
    EXPECT_EQ(8, list.tail()->value);
}
TEST(TestListLib, pop_front_throw) {
    // Arrange
    List<int> list;

    ASSERT_ANY_THROW(list.pop_front());
}
TEST(TestListLib, pop_back) {
    // Arrange
    List<int> list;
    list.push_back(5);
    list.push_back(7);
    list.push_back(8);
    list.pop_back();

    EXPECT_EQ(2, list.count());
    EXPECT_EQ(5, list.head()->value);
    EXPECT_EQ(7, list.tail()->value);
}
TEST(TestListLib, pop_back_throw) {
    // Arrange
    List<int> list;

    ASSERT_ANY_THROW(list.pop_back());
}
TEST(TestListLib,erase_adress_throw) {
    // Arrange
    List<int> list;
    ASSERT_ANY_THROW(list.erase(list.head()));
}

TEST(TestListLib, erase_adress) {
    // Arrange
    List<int> list;
    list.push_front(9);
    list.push_back(5);
    list.push_back(6);
    list.erase(list.head()->next);

    //std::cout << list;
    EXPECT_EQ(2, list.count());
    EXPECT_EQ(9, list.head()->value);
    EXPECT_EQ(6, list.tail()->value);
}
TEST(TestListLib, erase_pos_throw) {
    // Arrange
    List<int> list;
    ASSERT_ANY_THROW(list.erase(4));
}

TEST(TestListLib, erase_pos) {
    // Arrange
    List<int> list;
    list.push_front(9);
    list.push_back(5);
    list.push_back(6);
    list.erase(1);

    EXPECT_EQ(2, list.count());
    EXPECT_EQ(9, list.head()->value);
    EXPECT_EQ(6, list.tail()->value);
}
#include <gtest/gtest.h>
#include <iostream>
#include "../lib_heap/heap.h"

TEST(TestHeapLib, can_insert_int) {
    Heap<int> heap;

    ASSERT_NO_THROW(heap.insert(5));
}

TEST(TestHeapLib, can_insert_string) {
    Heap<std::string> heap;

    ASSERT_NO_THROW(heap.insert("hello"));
}

TEST(TestHeapLib, is_empty_true) {
    Heap<int> heap;
    EXPECT_TRUE(heap.is_empty());
}

TEST(TestHeapLib, is_empty_false) {
    Heap<int> heap;
    heap.insert(5);
    EXPECT_FALSE(heap.is_empty());
}

TEST(TestHeapLib, not_can_erase_root) {
    Heap<int> heap;
    ASSERT_ANY_THROW(heap.erase_root());
}

TEST(TestHeapLib, can_erase_root) {
    Heap<int> heap;
    heap.insert(5);
    heap.insert(6);
    heap.insert(7);
    heap.insert(8);
    ASSERT_NO_THROW(heap.erase_root());
}

TEST(TestHeapLib, erase_root_returns_min_element) {
    Heap<int> heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(7);
    heap.insert(1);

    int min = heap.erase_root();
    EXPECT_EQ(min, 1);
}

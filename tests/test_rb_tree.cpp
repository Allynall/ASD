#include <gtest/gtest.h>
#include <iostream>
#include "../lib_rb_tree/rb_tree.h"


TEST(TestRBTreeLib, can_insert) {
    RBTree<int, std::string> tree;

    tree.insert(5, ",");
    tree.insert(7, "p");
    tree.insert(6, "t");
    tree.insert(8, "w");

    tree.print();
    EXPECT_EQ(",", *tree.find(5));
    EXPECT_EQ("p", *tree.find(7));
    EXPECT_EQ("t", *tree.find(6));
    EXPECT_EQ("w", *tree.find(8));
}

TEST(TestRBTreeLib, not_can_insert_duplicate_key_throw) {
    RBTree<int, std::string> tree;
    tree.insert(5, ",");

    ASSERT_ANY_THROW(tree.insert(5, "o"));
    EXPECT_EQ(",", *tree.find(5));
}


TEST(TestRBTreeLib, is_empty_true) {
    RBTree<int, std::string> tree;
    EXPECT_TRUE(tree.is_empty());
}

TEST(TestRBTreeLib, is_empty_false) {
    RBTree<int, std::string> tree;
    tree.insert(5, ",");
    EXPECT_FALSE(tree.is_empty());
}


TEST(TestRBTreeLib, clear) {
    RBTree<int, std::string> tree;
    tree.insert(5, ",");
    tree.insert(10, "a");
    tree.insert(3, "b");
    tree.clear();
    EXPECT_TRUE(tree.is_empty());
}

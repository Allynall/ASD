#include <gtest/gtest.h>
#include <iostream>
#include "../lib_tree/tree.h"

TEST(TestUnsortedTreeLib, can_insert_pair) {
	Tree<int, std::string> tree;

	ASSERT_NO_THROW(tree.insert(5, "o"));
}

TEST(TestUnsortedTreeLib, not_can_insert_pair) {
	Tree<int, std::string> tree;
	tree.insert(5, ",");
	tree.insert(7, "ð");
	tree.insert(6, "ò");
	tree.insert(8, "â");
	tree.print_DLCR();
	ASSERT_ANY_THROW(tree.insert(5, "o"));
}

TEST(TestUnsortedTreeLib, is_empty_true) {
	Tree<int, std::string> tree;
	EXPECT_TRUE(tree.is_empty());
}

TEST(TestUnsortedTreeLib, is_empty_false) {
	Tree<int, std::string> tree;
	tree.insert(5, ",");
	EXPECT_FALSE(tree.is_empty());
}

TEST(TestUnsortedTreeLib, clear) {
	Tree<int, std::string> tree;
	tree.insert(5, ",");
	tree.clear();
	EXPECT_TRUE(tree.is_empty());
}
TEST(TestUnsortedTreeLib, found_pair) {
	Tree<int, std::string> tree;
	tree.insert(5, "o");
	std::string* val = tree.find(5);
	ASSERT_NE(val, nullptr);   
	EXPECT_EQ("o", *val);
}

TEST(TestUnsortedTreeLib, not_found_pair) {
	Tree<int, std::string> tree;
	tree.insert(5, "o");
	EXPECT_TRUE(tree.find(6) == nullptr);
}

TEST(TestUnsortedTreeLib, can_erase_pair) {
	Tree<int, std::string> tree;
	tree.insert(5, "h");
	tree.insert(6, "7");
	ASSERT_NO_THROW(tree.erase(6));

}

TEST(TestUnsortedTreeLib, not_can_erase_pair_not_found_key) {
	Tree<int, std::string> tree;
	tree.insert(5, "h");
	ASSERT_ANY_THROW(tree.erase(6));
}

TEST(TestUnsortedTreeLib, not_can_erase_pair_in_empty_table) {
	Tree<int, std::string> tree;
	ASSERT_ANY_THROW(tree.erase(6));
}

TEST(TestUnsortedTreeLib, print) {
	Tree<int, std::string> tree;
	tree.insert(1, "one");
	tree.insert(2, "two");
	tree.insert(3, "three");
	tree.insert(4, "four");
	tree.insert(5, "five");
	tree.print_w();
	tree.print_DCLR();
	tree.print_DLCR();
	tree.print_DLRC();
}

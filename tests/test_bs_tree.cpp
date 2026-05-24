#include <gtest/gtest.h>
#include <iostream>
#include "../lib_bs_tree/bs_tree.h"

TEST(TestBSTreeLib, can_insert_pair) {
	BSTree<int, std::string> tree;

	ASSERT_NO_THROW(tree.insert(5, "o"));
	EXPECT_EQ("o", *tree.find(5));
}

TEST(TestBSTreeLib, not_can_insert_pair) {
	BSTree<int, std::string> tree;
	tree.insert(5, ",");
	tree.insert(7, "p");
	tree.insert(6, "t");
	tree.insert(8, "w");

	EXPECT_EQ(",", *tree.find(5));
	EXPECT_EQ("p", *tree.find(7));
	EXPECT_EQ("t", *tree.find(6));
	EXPECT_EQ("w", *tree.find(8));

	tree.print_pairs();
	ASSERT_ANY_THROW(tree.insert(5, "o"));
}

TEST(TestBSTreeLib, is_empty_true) {
	BSTree<int, std::string> tree;
	EXPECT_TRUE(tree.is_empty());
}

TEST(TestBSTreeLib, is_empty_false) {
	BSTree<int, std::string> tree;
	tree.insert(5, ",");

	EXPECT_EQ(",", *tree.find(5));
	EXPECT_FALSE(tree.is_empty());
}

TEST(TestBSTreeLib, clear) {
	BSTree<int, std::string> tree;
	tree.insert(5, ",");
	tree.clear();
	EXPECT_TRUE(tree.is_empty());
}
TEST(TestBSTreeLib, found_pair) {
	BSTree<int, std::string> tree;
	tree.insert(5, "o");
	std::string* val = tree.find(5);
	ASSERT_NE(val, nullptr);
	EXPECT_EQ("o", *val);
}

TEST(TestBSTreeLib, not_found_pair) {
	BSTree<int, std::string> tree;
	tree.insert(5, "o");
	EXPECT_TRUE(tree.find(6) == nullptr);
}


TEST(TestBSTreeLib, can_erase_pair) {
	BSTree<int, std::string> tree;
	tree.insert(5, "h");
	tree.insert(6, "j");

	ASSERT_NO_THROW(tree.erase(6));
	EXPECT_EQ("h", *tree.find(5));
	EXPECT_EQ(nullptr, tree.find(6));
	tree.print_DLCR();

}

TEST(TestBSTreeLib, not_can_erase_pair_not_found_key) {
	BSTree<int, std::string> tree;
	tree.insert(5, "h");
	ASSERT_ANY_THROW(tree.erase(6));
}

TEST(TestBSTreeLib, not_can_erase_pair_in_empty_table) {
	BSTree<int, std::string> tree;
	ASSERT_ANY_THROW(tree.erase(6));
}

TEST(TestBSTreeLib, can_erase_head) {
	BSTree<int, std::string> tree;
	tree.insert(5, "h");
	tree.insert(6, "7");
	
	ASSERT_NO_THROW(tree.erase(5));
	EXPECT_EQ(nullptr, tree.find(5));
	EXPECT_EQ("7", *tree.find(6));
}

TEST(TestBSTreeLib, erase_leaf) {
	BSTree<int, std::string> tree;

	tree.insert(50, "a");
	tree.insert(30, "b");
	tree.insert(20, "c");  

	ASSERT_NO_THROW(tree.erase(20));
	EXPECT_EQ(nullptr, tree.find(20));
	EXPECT_EQ("a", *tree.find(50));
	EXPECT_EQ("b", *tree.find(30));
}

TEST(TestBSTreeLib, erase_one_child) {
	BSTree<int, std::string> tree;

	tree.insert(50, "a");
	tree.insert(30, "b");  
	tree.insert(20, "c");  

	ASSERT_NO_THROW(tree.erase(30));
	EXPECT_EQ(nullptr, tree.find(30));
	EXPECT_EQ("a", *tree.find(50));
	EXPECT_EQ("c", *tree.find(20));
}

TEST(TestBSTreeLib, erase_two_children) {
	BSTree<int, std::string> tree;

	tree.insert(50, "a"); 
	tree.insert(30, "b");
	tree.insert(70, "c");

	ASSERT_NO_THROW(tree.erase(50));
	EXPECT_EQ(nullptr, tree.find(50));
	EXPECT_EQ("b", *tree.find(30));
	EXPECT_EQ("c", *tree.find(70));
}

TEST(TestBSTreeLib, erase_root) {
	BSTree<int, std::string> tree;

	tree.insert(10, "x");

	ASSERT_NO_THROW(tree.erase(10));
	EXPECT_EQ(nullptr, tree.find(10));
	EXPECT_TRUE(tree.is_empty());
}

TEST(TestBSTreeLib, erase_k) {
	BSTree<int, std::string> tree;

	tree.insert(50, "x");
	tree.insert(30, "g");
	tree.insert(70, "r");
	tree.insert(20, "s");
	tree.insert(45, "n");
	tree.insert(40, "t");
	tree.insert(48, "p");

	ASSERT_NO_THROW(tree.erase(50));
	EXPECT_EQ(nullptr, tree.find(50));
	EXPECT_EQ("g", *tree.find(30));
	EXPECT_EQ("r", *tree.find(70));
	EXPECT_EQ("s", *tree.find(20));
	EXPECT_EQ("t", *tree.find(40));
	EXPECT_EQ("n", *tree.find(45));
	EXPECT_EQ("p", *tree.find(48));

	EXPECT_FALSE(tree.is_empty());
}

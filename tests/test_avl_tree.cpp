#include <gtest/gtest.h>
#include <iostream>
#include "../lib_avl_tree/avl_tree.h"  

TEST(TestAVLTreeLib, can_insert) {
	AVLTree<int, std::string> tree;

	tree.insert(5, ",");
	tree.insert(7, "p");
	tree.insert(6, "t");
	tree.insert(8, "w");

	EXPECT_EQ(",", *tree.find(5));
	EXPECT_EQ("p", *tree.find(7));
	EXPECT_EQ("t", *tree.find(6));
	EXPECT_EQ("w", *tree.find(8));
	tree.print_DLCR();
}

TEST(TestAVLTreeLib, not_can_insert_duplicate_key_throw) {
	AVLTree<int, std::string> tree;
	tree.insert(5, ",");

	ASSERT_ANY_THROW(tree.insert(5, "o"));
	EXPECT_EQ(",", *tree.find(5));
}

TEST(TestAVLTreeLib, is_empty_true) {
	AVLTree<int, std::string> tree;
	EXPECT_TRUE(tree.is_empty());
}

TEST(TestAVLTreeLib, is_empty_false) {
	AVLTree<int, std::string> tree;
	tree.insert(5, ",");
	EXPECT_FALSE(tree.is_empty());
}

TEST(TestAVLTreeLib, clear) {
	AVLTree<int, std::string> tree;
	tree.insert(5, ",");
	tree.insert(10, "a");
	tree.insert(3, "b");
	tree.clear();
	EXPECT_TRUE(tree.is_empty());
}

TEST(TestAVLTreeLib, found_pair) {
	AVLTree<int, std::string> tree;
	tree.insert(5, "o");
	std::string* val = tree.find(5);
	ASSERT_NE(val, nullptr);
	EXPECT_EQ("o", *val);
}

TEST(TestAVLTreeLib, not_found_pair) {
	AVLTree<int, std::string> tree;
	tree.insert(5, "o");
	EXPECT_TRUE(tree.find(6) == nullptr);
}

TEST(TestAVLTreeLib, find_in_empty_tree) {
	AVLTree<int, std::string> tree;
	EXPECT_TRUE(tree.find(10) == nullptr);
}

TEST(TestAVLTreeLib, erase_not_key) {
	AVLTree<int, std::string> tree;
	tree.insert(5, "h");
	ASSERT_ANY_THROW(tree.erase(6));
}

TEST(TestAVLTreeLib, erase_from_empty_tree) {
	AVLTree<int, std::string> tree;
	ASSERT_ANY_THROW(tree.erase(6));
}

TEST(TestAVLTreeLib, can_erase_leaf) {
	AVLTree<int, std::string> tree;
	tree.insert(5, "h");
	tree.insert(6, "j");

	ASSERT_NO_THROW(tree.erase(6));
	EXPECT_EQ("h", *tree.find(5));
	EXPECT_EQ(nullptr, tree.find(6));
}

TEST(TestAVLTreeLib, erase_leaf) {
	AVLTree<int, std::string> tree;
	tree.insert(5, "h");
	tree.insert(6, "j");

	tree.erase(6);
	EXPECT_EQ(nullptr, tree.find(6));
	EXPECT_EQ("h", *tree.find(5));
}

TEST(TestAVLTreeLib, erase_root) {
	AVLTree<int, std::string> tree;
	tree.insert(5, "h");

	tree.erase(5);
	EXPECT_EQ(nullptr, tree.find(5));
	EXPECT_TRUE(tree.is_empty());
}

TEST(TestAVLTreeLib, erase_node_with_one_child) {
	AVLTree<int, std::string> tree;
	tree.insert(5, "h");
	tree.insert(3, "c");

	tree.erase(5);
	EXPECT_EQ(nullptr, tree.find(5));
	EXPECT_EQ("c", *tree.find(3));
}

TEST(TestAVLTreeLib, erase_node_with_two_children) {
	AVLTree<int, std::string> tree;
	tree.insert(50, "a");
	tree.insert(30, "b");
	tree.insert(70, "c");

	tree.erase(50);
	EXPECT_EQ(nullptr, tree.find(50));
	EXPECT_EQ("b", *tree.find(30));
	EXPECT_EQ("c", *tree.find(70));
}

//TEST(TestAVLTreeLib, erase_node_with_cycle) {
//	AVLTree<int, std::string> tree;
//	tree.insert(5, "a");
//	tree.insert(75, "b");
//	tree.insert(45, "c");
//	tree.insert(55, "d");
//	tree.insert(65, "e");
//	tree.insert(80, "f");
//	tree.insert(15, "g");
//	tree.insert(25, "k");
//	tree.insert(50, "l");
//	tree.insert(70, "m");
//	tree.insert(20, "n");
//	tree.insert(60, "o");
//	tree.insert(40, "p");
//	
//
//	tree.erase(25);
//	EXPECT_EQ(nullptr, tree.find(25));
//	EXPECT_EQ("a", *tree.find(5));
//	EXPECT_EQ("b", *tree.find(75));
//	EXPECT_EQ("c", *tree.find(45));
//	EXPECT_EQ("d", *tree.find(55));
//	EXPECT_EQ("e", *tree.find(65));
//	EXPECT_EQ("f", *tree.find(80));
//	EXPECT_EQ("g", *tree.find(15));
//	EXPECT_EQ("l", *tree.find(50));
//	EXPECT_EQ("m", *tree.find(70));
//	EXPECT_EQ("n", *tree.find(20));
//	EXPECT_EQ("o", *tree.find(60));
//	EXPECT_EQ("p", *tree.find(40));
//	
//	tree.print_pairs();
//}

TEST(TestAVLTreeLib, RL_and_LL_rotations) {
	AVLTree<int, std::string> tree;

	tree.insert(50, "50");
	tree.insert(30, "30");
	tree.insert(70, "70");
	tree.insert(20, "20");
	tree.insert(40, "40");
	tree.insert(45, "45");
	tree.insert(35, "35");
	tree.insert(33, "33");

	EXPECT_NE(tree.find(45), nullptr);
	EXPECT_NE(tree.find(40), nullptr);
	EXPECT_EQ("50", *tree.find(50));
	EXPECT_EQ("30", *tree.find(30));
	EXPECT_EQ("70", *tree.find(70));
	EXPECT_EQ("20", *tree.find(20));
	EXPECT_EQ("40", *tree.find(40));
	EXPECT_EQ("45", *tree.find(45)); //RL
	EXPECT_EQ("35", *tree.find(35));
	EXPECT_EQ("33", *tree.find(33)); //LL

	tree.print_pairs();
}
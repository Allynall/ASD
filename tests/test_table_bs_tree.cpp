#include <gtest/gtest.h>
#include <iostream>
#include "../lib_table_bs_tree/table_bs_tree.h"


TEST(TestTableBSTree, can_insert_pair) {
	TableBSTree<int, std::string> table;
	std::pair<int, std::string> expected_result = std::make_pair(5, "0");

	ASSERT_NO_THROW(table.insert(5, "o"));

}

TEST(TestTableBSTree, not_can_insert_pair) {
	TableBSTree<int, std::string> table;
	table.insert(5, ",");
	ASSERT_ANY_THROW(table.insert(5, "o"));

}

TEST(TestTableBSTree, can_erase_pair) {
	TableBSTree<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "7");
	table.print();
	ASSERT_NO_THROW(table.erase(6));

}

TEST(TestTableBSTree, not_can_erase_pair_not_found_key) {
	TableBSTree<int, std::string> table;
	table.insert(5, "h");
	ASSERT_ANY_THROW(table.erase(6));
}

TEST(TestTableBSTree, not_can_erase_pair_in_empty_table) {
	TableBSTree<int, std::string> table;
	ASSERT_ANY_THROW(table.erase(6));
}

TEST(TestTableBSTree, empty_pair_true) {
	TableBSTree<int, std::string> table;
	EXPECT_TRUE(table.isEmpty());
}

TEST(TestTableBSTree, empty_pair_false) {
	TableBSTree<int, std::string> table;
	table.insert(5, "h");
	EXPECT_FALSE(table.isEmpty());
}

TEST(TestTableBSTree, empty_pair_true_after_erase) {
	TableBSTree<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "h");
	table.erase(5);
	table.erase(6);
	EXPECT_TRUE(table.isEmpty());
}

TEST(TestTableBSTree, found_pair) {
	TableBSTree<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "a");
	table.insert(7, "s");
	EXPECT_EQ("h", table.found(5));
	EXPECT_EQ("a", table.found(6));
	EXPECT_EQ("s", table.found(7));
}

TEST(TestTableBSTree, found_pair_after_erase) {
	TableBSTree<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "a");
	table.insert(7, "s");
	table.erase(7);
	table.print();
	EXPECT_EQ("h", table.found(5));
	EXPECT_EQ("a", table.found(6));
	EXPECT_ANY_THROW(table.found(7));
}

TEST(TestTableBSTree, found_pair_throw) {
	TableBSTree<int, std::string> table;
	table.insert(5, "h");
	EXPECT_EQ("h", table.found(5));
}

TEST(TestTableBSTree, found_pair_in_empty_table) {
	TableBSTree<int, std::string> table;
	EXPECT_ANY_THROW(table.found(3));
}

TEST(TestTableBSTree, erase) {
	TableBSTree<int, std::string> table;
	table.insert(5, "a");
	table.insert(3, "b");
	table.insert(7, "c");
	table.erase(3);
	EXPECT_ANY_THROW(table.found(3));
	EXPECT_EQ("a", table.found(5));
	EXPECT_EQ("c", table.found(7));
}


TEST(TestTableBSTree, erase_throw_empty) {
	TableBSTree<int, std::string> table;
	ASSERT_ANY_THROW(table.erase(5));
}

TEST(TestTableBSTree, erase_throw_not_found) {
	TableBSTree<int, std::string> table;
	table.insert(5, "a");
	table.insert(3, "b");
	table.insert(7, "c");;
	ASSERT_ANY_THROW(table.erase(6));
}
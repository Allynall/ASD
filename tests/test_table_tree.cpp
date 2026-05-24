#include <gtest/gtest.h>
#include <iostream>
#include "../lib_table_tree/table_tree.h"


TEST(TestTableTree, can_insert_pair) {
	TableTree<int, std::string> table;
	std::pair<int, std::string> expected_result = std::make_pair(5, "0");

	ASSERT_NO_THROW(table.insert(5, "o"));

}

TEST(TestTableTree, not_can_insert_pair) {
	TableTree<int, std::string> table;
	table.insert(5, ",");
	ASSERT_ANY_THROW(table.insert(5, "o"));

}

TEST(TestTableTree, can_erase_pair) {
	TableTree<int, std::string> table;
	table.insert(5, "h");
	table.print();
	ASSERT_NO_THROW(table.erase(5));

}

TEST(TestTableTree, not_can_erase_pair_not_found_key) {
	TableTree<int, std::string> table;
	table.insert(5, "h");
	ASSERT_ANY_THROW(table.erase(6));
}

TEST(TestTableTree, not_can_erase_pair_in_empty_table) {
	TableTree<int, std::string> table;
	ASSERT_ANY_THROW(table.erase(6));
}

TEST(TestTableTree, empty_pair_true) {
	TableTree<int, std::string> table;
	EXPECT_TRUE(table.isEmpty());
}

TEST(TestTableTree, empty_pair_false) {
	TableTree<int, std::string> table;
	table.insert(5, "h");
	EXPECT_FALSE(table.isEmpty());
}

TEST(TestTableTree, empty_pair_true_after_erase) {
	TableTree<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "h");
	table.erase(5);
	table.erase(6);
	EXPECT_TRUE(table.isEmpty());
}

TEST(TestTableTree, found_pair) {
	TableTree<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "a");
	table.insert(7, "s");
	EXPECT_EQ("h", table.found(5));
	EXPECT_EQ("a", table.found(6));
	EXPECT_EQ("s", table.found(7));
}

TEST(TestTableTree, found_pair_after_erase) {
	TableTree<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "a");
	table.insert(7, "s");
	table.erase(7);
	table.print();
	EXPECT_EQ("h", table.found(5));
	EXPECT_EQ("a", table.found(6));
	EXPECT_ANY_THROW(table.found(7));
}

TEST(TestTableTree, found_pair_throw) {
	TableTree<int, std::string> table;
	table.insert(5, "h");
	EXPECT_ANY_THROW(table.found(7));
}

TEST(TestTableTree, found_pair_in_empty_table) {
	TableTree<int, std::string> table;
	EXPECT_ANY_THROW(table.found(3));
}
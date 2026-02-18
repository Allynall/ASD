#include <gtest/gtest.h>
#include <iostream>
#include "../lib_unsorted_tablel/unsorted_tablel.h"

TEST(TestUnsortedTableLibL, can_insert_pair) {
	UnsortedTableL<int, std::string> table;
	std::pair<int, std::string> expected_result = std::make_pair(5, "0");

	ASSERT_NO_THROW(table.insert(5, "o"));

}
TEST(TestUnsortedTableLiL, not_can_insert_pair) {
	UnsortedTableL<int, std::string> table;
	table.insert(5, ",");
	ASSERT_ANY_THROW(table.insert(5, "o"));
}
TEST(TestUnsortedTableLibL, not_can_insert_pair) {
	UnsortedTableL<int, std::string> table;
	table.insert(5, ",");
	ASSERT_ANY_THROW(table.insert(5, "o"));

}
TEST(TestUnsortedTableLibL, can_erase_pair) {
	UnsortedTableL<int, std::string> table;
	table.insert(5, "h");
	ASSERT_NO_THROW(table.erase(5));

}

TEST(TestUnsortedTableLibL, not_can_erase_pair_not_found_key) {
	UnsortedTableL<int, std::string> table;
	table.insert(5, "h");
	ASSERT_ANY_THROW(table.erase(6));
}

TEST(TestUnsortedTableLibL, not_can_erase_pair_in_empty_table) {
	UnsortedTableL<int, std::string> table;
	ASSERT_ANY_THROW(table.erase(6));
}
TEST(TestUnsortedTableLibL, empty_pair_true) {
	UnsortedTableL<int, std::string> table;
	EXPECT_TRUE(table.isEmpty());
}

TEST(TestUnsortedTableLibL, empty_pair_false) {
	UnsortedTableL<int, std::string> table;
	table.insert(5, "h");
	EXPECT_FALSE(table.isEmpty());
}

TEST(TestUnsortedTableLibL, empty_pair_true_after_erase) {
	UnsortedTableL<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "h");
	table.erase(5);
	table.erase(6);
	EXPECT_TRUE(table.isEmpty());
}
TEST(TestUnsortedTableLibL, found_pair) {
	UnsortedTableL<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "a");
	table.insert(7, "s");
	EXPECT_EQ("h", table.found(5));
	EXPECT_EQ("a", table.found(6));
	EXPECT_EQ("s", table.found(7));
}

TEST(TestUnsortedTableLibL, found_pair_after_erase) {
	UnsortedTableL<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "a");
	table.insert(7, "s");
	table.erase(7);
	EXPECT_EQ("h", table.found(5));
	EXPECT_EQ("a", table.found(6));
	EXPECT_ANY_THROW(table.found(7));
}

TEST(TestUnsortedTableLibL, found_pair_throw) {
	UnsortedTableL<int, std::string> table;
	table.insert(5, "h");
	EXPECT_ANY_THROW(table.found(7));
}

TEST(TestUnsortedTableLibL, found_pair_in_empty_table) {
	UnsortedTableL<int, std::string> table;
	EXPECT_ANY_THROW(table.found(3));
}
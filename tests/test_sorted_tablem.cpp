#include <gtest/gtest.h>
#include <iostream>
#include "../lib_sorted_tablem/sorted_tablem.h"

TEST(TestSortedTableLibM, can_insert_pair) {
	SortedTableM<int, std::string> table;
	std::pair<int, std::string> expected_result = std::make_pair(5, "0");

	ASSERT_NO_THROW(table.insert(5, "o"));

}
TEST(TestSortedTableLibM, not_can_insert_pair) {
	SortedTableM<int, std::string> table;
	table.insert(5, ",");
	ASSERT_ANY_THROW(table.insert(5, "o"));
}

TEST(TestSortedTableLibM, can_erase_pair) {
	SortedTableM<int, std::string> table;
	table.insert(5, "h");
	ASSERT_NO_THROW(table.erase(5));

}

TEST(TestSortedTableLibM, not_can_erase_pair_not_found_key) {
	SortedTableM<int, std::string> table;
	table.insert(5, "h");
	ASSERT_ANY_THROW(table.erase(6));
}

TEST(TestSortedTableLibM, not_can_erase_pair_in_empty_table) {
	SortedTableM<int, std::string> table;
	ASSERT_ANY_THROW(table.erase(6));
}
TEST(TestSortedTableLibM, empty_pair_true) {
	SortedTableM<int, std::string> table;
	EXPECT_TRUE(table.isEmpty());
}

TEST(TestSortedTableLibM, empty_pair_false) {
	SortedTableM<int, std::string> table;
	table.insert(5, "h");
	EXPECT_FALSE(table.isEmpty());
}

TEST(TestSortedTableLibM, empty_pair_true_after_erase) {
	SortedTableM<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "h");
	table.erase(5);
	table.erase(6);
	EXPECT_TRUE(table.isEmpty());
}
TEST(TestSortedTableLibM, found_pair) {
	SortedTableM<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "a");
	table.insert(7, "s");
	EXPECT_EQ("h", table.found(5));
	EXPECT_EQ("a", table.found(6));
	EXPECT_EQ("s", table.found(7));
}

TEST(TestSortedTableLibM, found_pair_after_erase) {
	SortedTableM<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "a");
	table.insert(7, "s");
	table.erase(7);
	EXPECT_EQ("h", table.found(5));
	EXPECT_EQ("a", table.found(6));
	EXPECT_ANY_THROW(table.found(7));
}

TEST(TestSortedTableLibM, found_pair_throw) {
	SortedTableM<int, std::string> table;
	table.insert(5, "h");
	EXPECT_ANY_THROW(table.found(7));
}

TEST(TestSortedTableLibM, found_pair_in_empty_table) {
	SortedTableM<int, std::string> table;
	EXPECT_ANY_THROW(table.found(3));
}
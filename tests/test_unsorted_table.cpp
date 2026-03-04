#include <gtest/gtest.h>
#include <iostream>
#include "../lib_unsorted_table/unsorted_table.h"

TEST(TestUnsortedTableLib, can_insert_pair) {
	UnsortedTableM<int, std::string> table;
	std::pair<int, std::string> expected_result = std::make_pair(5, "0");
	
	ASSERT_NO_THROW(table.insert(5, "o"));

}
TEST(TestUnsortedTableLib, not_can_insert_pair) {
	UnsortedTableM<int, std::string> table;
	table.insert(5, ",");
	ASSERT_ANY_THROW(table.insert(5, "o"));

}
TEST(TestUnsortedTableLib, can_erase_pair) {
	UnsortedTableM<int, std::string> table;
	table.insert(5, "h");
	ASSERT_NO_THROW(table.erase(5));

}

TEST(TestUnsortedTableLib, not_can_erase_pair_not_found_key) {
	UnsortedTableM<int, std::string> table;
	table.insert(5, "h");
	ASSERT_ANY_THROW(table.erase(6));
}

TEST(TestUnsortedTableLib, not_can_erase_pair_in_empty_table) {
	UnsortedTableM<int, std::string> table;
	ASSERT_ANY_THROW(table.erase(6));
}

TEST(TestUnsortedTableLib, empty_pair_true) {
	UnsortedTableM<int, std::string> table;
	EXPECT_TRUE(table.isEmpty());
}

TEST(TestUnsortedTableLib, empty_pair_false) {
	UnsortedTableM<int, std::string> table;
	table.insert(5, "h");
	EXPECT_FALSE(table.isEmpty());
}

TEST(TestUnsortedTableLib, empty_pair_true_after_erase) {
	UnsortedTableM<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "h");
	table.erase(5);
	table.erase(6);
	EXPECT_TRUE(table.isEmpty());
}

TEST(TestUnsortedTableLib, found_pair) {
	UnsortedTableM<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "a");
	table.insert(7, "s");
	EXPECT_EQ("h", table.found(5));
	EXPECT_EQ("a", table.found(6));
	EXPECT_EQ("s", table.found(7));
}

TEST(TestUnsortedTableLib, found_pair_after_erase) {
	UnsortedTableM<int, std::string> table;
	table.insert(5, "h");
	table.insert(6, "a");
	table.insert(7, "s");
	table.erase(7);
	table.print();
	EXPECT_EQ("h", table.found(5));
	EXPECT_EQ("a", table.found(6));
	EXPECT_ANY_THROW(table.found(7));
}

TEST(TestUnsortedTableLib, found_pair_throw) {
	UnsortedTableM<int, std::string> table;
	table.insert(5, "h");
	EXPECT_ANY_THROW(table.found(7));
}

TEST(TestUnsortedTableLib, found_pair_in_empty_table) {
	UnsortedTableM<int, std::string> table;
	EXPECT_ANY_THROW(table.found(3));
}
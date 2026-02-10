#include <gtest/gtest.h>
#include <iostream>
#include "../lib_unsorted_table/unsorted_table.h"

TEST(TestUnsortedTableLib, can_default_construct) {
	UnsortedTableM<int, std::string> table;
}
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

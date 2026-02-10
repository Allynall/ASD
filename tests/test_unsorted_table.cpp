#include <gtest/gtest.h>
#include <iostream>
#include "../lib_unsorted_table/unsorted_table.h"

TEST(TestUnsortedTableLib, can_default_construct) {
	UnsortedTableM<int, std::string> table;
}
#include <gtest/gtest.h>
#include <iostream>
#include "../lib_hash_table_oa/hash_table_oa.h"

TEST(TestHashTableOALib, can_insert) {
    HashTableOA<int> table(10);
    ASSERT_NO_THROW(table.insert("5", 6));
    EXPECT_EQ(6, table.found("5"));
}

TEST(TestHashTableOALib, can_insert_more) {
    HashTableOA<int> table(20);
    ASSERT_NO_THROW(table.insert("5", 6));
    ASSERT_NO_THROW(table.insert("10", 11));
    ASSERT_NO_THROW(table.insert("15", 16));
    ASSERT_NO_THROW(table.insert("51", 17));

    EXPECT_EQ(6, table.found("5"));
    EXPECT_EQ(11, table.found("10"));
    EXPECT_EQ(16, table.found("15"));
    EXPECT_EQ(17, table.found("51"));

    table.print();
}

TEST(TestHashTableOALib, insert_throw) {
    HashTableOA<int> table(10);
    table.insert("5", 6);
    EXPECT_EQ(6, table.found("5"));
    ASSERT_ANY_THROW(table.insert("5", 10));
    EXPECT_EQ(6, table.found("5"));
}

TEST(TestHashTableOALib, can_erase) {
    HashTableOA<int> table(10);
    table.insert("5", 6);
    EXPECT_EQ(6, table.found("5"));
    ASSERT_NO_THROW(table.erase("5"));
    ASSERT_ANY_THROW(table.found("5"));
}

TEST(TestHashTableOALib, cannot_erase_key_throw) {
    HashTableOA<int> table(10);
    table.insert("5", 6);
    EXPECT_EQ(6, table.found("5"));
    ASSERT_ANY_THROW(table.erase("6"));
    EXPECT_EQ(6, table.found("5"));
}

TEST(TestHashTableOALib, cannot_erase_from_empty_table_throw) {
    HashTableOA<int> table(10);
    EXPECT_TRUE(table.isEmpty());
    ASSERT_ANY_THROW(table.erase("6"));
}

TEST(TestHashTableOALib, empty_table_true) {
    HashTableOA<int> table(10);
    EXPECT_TRUE(table.isEmpty());
    ASSERT_ANY_THROW(table.found("5"));
}

TEST(TestHashTableOALib, empty_table_false) {
    HashTableOA<int> table(10);
    table.insert("5", 6);
    EXPECT_FALSE(table.isEmpty());
    EXPECT_EQ(6, table.found("5"));
}

TEST(TestHashTableOALib, empty_table_true_after_erase) {
    HashTableOA<int> table(10);
    table.insert("5", 6);
    table.insert("6", 7);
    EXPECT_EQ(6, table.found("5"));
    EXPECT_EQ(7, table.found("6"));

    table.erase("5");
    table.erase("6");

    ASSERT_ANY_THROW(table.found("5"));
    ASSERT_ANY_THROW(table.found("6"));
    EXPECT_TRUE(table.isEmpty());
    table.print();
}

TEST(TestHashTableOALib, can_find) {
    HashTableOA<int> table(10);
    table.insert("5", 6);
    table.insert("6", 7);
    table.insert("7", 8);

    EXPECT_EQ(6, table.found("5"));
    EXPECT_EQ(7, table.found("6"));
    EXPECT_EQ(8, table.found("7"));
}

TEST(TestHashTableOALib, can_find_after_erase) {
    HashTableOA<int> table(10);
    table.insert("6", 7);
    table.insert("5", 6);
    table.insert("7", 8);

    EXPECT_EQ(6, table.found("5"));
    EXPECT_EQ(7, table.found("6"));
    EXPECT_EQ(8, table.found("7"));

    table.erase("7");

    EXPECT_EQ(6, table.found("5"));
    EXPECT_EQ(7, table.found("6"));
    ASSERT_ANY_THROW(table.found("7"));
}

TEST(TestHashTableOALib, insert_erase_with_collision) {
    HashTableOA<int> table(10);
    table.insert("51", 6);
    table.insert("52", 8);
    table.insert("15", 7);
    table.erase("51");
    EXPECT_EQ(7, table.found("15"));
    EXPECT_EQ(8, table.found("52"));
    ASSERT_ANY_THROW(table.found("51"));
}
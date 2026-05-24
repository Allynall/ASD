#include <gtest/gtest.h>
#include <iostream>
#include "../lib_hash_table/hash_table.h"

TEST(TestHashTableLib, can_insert) {
    HashTable<int> table(10);
    ASSERT_NO_THROW(table.insert("5", 6));
    EXPECT_EQ(6, table.found("5"));
}

TEST(TestHashTableLib, can_insert_more) {
    HashTable<int> table(10);
    ASSERT_NO_THROW(table.insert("10", 11));
    ASSERT_NO_THROW(table.insert("15", 16));

    EXPECT_EQ(11, table.found("10"));
    EXPECT_EQ(16, table.found("15"));

    table.print();
}

TEST(TestHashTableLib, insert_throw) {
    HashTable<int> table(10);
    table.insert("5", 6);
    EXPECT_EQ(6, table.found("5"));
    ASSERT_ANY_THROW(table.insert("5", 10));
    EXPECT_EQ(6, table.found("5"));
}

TEST(TestHashTableLib, can_erase) {
    HashTable<int> table(10);
    table.insert("5", 6);
    EXPECT_EQ(6, table.found("5"));
    ASSERT_NO_THROW(table.erase("5"));
    ASSERT_ANY_THROW(table.found("5"));
}

TEST(TestHashTableLib, cannot_erase_key_throw) {
    HashTable<int> table(10);
    table.insert("5", 6);
    EXPECT_EQ(6, table.found("5"));
    ASSERT_ANY_THROW(table.erase("6"));
    EXPECT_EQ(6, table.found("5"));
}

TEST(TestHashTableLib, cannot_erase_from_empty_table_throw) {
    HashTable<int> table(10);
    EXPECT_TRUE(table.isEmpty());
    ASSERT_ANY_THROW(table.erase("6"));
}

TEST(TestHashTableLib, empty_table_true) {
    HashTable<int> table(10);
    EXPECT_TRUE(table.isEmpty());
    ASSERT_ANY_THROW(table.found("5"));
}

TEST(TestHashTableLib, empty_table_false) {
    HashTable<int> table(10);
    table.insert("5", 6);
    EXPECT_FALSE(table.isEmpty());
    EXPECT_EQ(6, table.found("5"));
}

TEST(TestHashTableLib, empty_table_true_after_erase) {
    HashTable<int> table(10);
    table.insert("5", 6);
    table.insert("6", 7);

    EXPECT_EQ(6, table.found("5"));
    EXPECT_EQ(7, table.found("6"));

    table.erase("5");
    table.erase("6");

    ASSERT_ANY_THROW(table.found("5"));
    ASSERT_ANY_THROW(table.found("6"));
    EXPECT_TRUE(table.isEmpty());
}

TEST(TestHashTableLib, can_find) {
    HashTable<int> table(10);
    table.insert("5", 6);
    table.insert("6", 7);
    table.insert("7", 8);

    EXPECT_EQ(6, table.found("5"));
    EXPECT_EQ(7, table.found("6"));
    EXPECT_EQ(8, table.found("7"));
}

TEST(TestHashTableLib, can_find_after_erase) {
    HashTable<int> table(10);
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

TEST(TestHashTableLib, insert_erase_with_collision) {
    HashTable<int> table(10);
    table.insert("51", 6);
    table.insert("52", 8);
    table.insert("15", 7);
    table.erase("51");
    EXPECT_EQ(7, table.found("15"));
    EXPECT_EQ(8, table.found("52"));
    ASSERT_ANY_THROW(table.found("51"));
}
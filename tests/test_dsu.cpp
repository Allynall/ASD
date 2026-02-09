#include <gtest/gtest.h>
#include "../lib_dsu/dsu.h"

TEST(TestDSULib, default_constructor) {
    // Arrange
    DSU dsu(2);

    EXPECT_EQ(2, dsu.size());
    EXPECT_EQ(0, dsu.parent()[0]);
    EXPECT_EQ(1, dsu.parent()[1]);
    EXPECT_EQ(0, dsu.rank()[0]);
    EXPECT_EQ(0, dsu.rank()[1]);
}

TEST(TestDSULib, copy_constructor) {
    // Arrange
    DSU dsu_1(2), dsu_2(dsu_1);

    EXPECT_EQ(2, dsu_2.size());
    EXPECT_EQ(0, dsu_2.parent()[0]);
    EXPECT_EQ(1, dsu_2.parent()[1]);
    EXPECT_EQ(0, dsu_2.rank()[0]);
    EXPECT_EQ(0, dsu_2.rank()[1]);
}

TEST(TestDSULib, unionn_transitivity) {
    // Arrange
    DSU dsu(4);

    dsu.unionn(0, 1);
    dsu.unionn(1, 2);

    EXPECT_EQ(0, dsu.find(0));  
    EXPECT_EQ(0, dsu.find(1));
    EXPECT_EQ(0, dsu.find(2));
    EXPECT_EQ(3, dsu.find(3));
    EXPECT_EQ(1, dsu.rank()[0]);
}
TEST(TestDSULib, unionn_rank) {
    // Arrange
    DSU dsu(4);

    dsu.unionn(0, 1);
    dsu.unionn(2, 3);
    dsu.unionn(0, 2);

    EXPECT_EQ(0, dsu.find(0));
    EXPECT_EQ(0, dsu.find(1));
    EXPECT_EQ(0, dsu.find(2));
    EXPECT_EQ(0, dsu.find(3));
    EXPECT_EQ(2, dsu.rank()[0]);
}
TEST(TestDSULib, unionn_repeated_union) {
    DSU dsu(4);

    dsu.unionn(0, 1); 
    dsu.unionn(1, 0); 
    dsu.unionn(1, 2);

    EXPECT_EQ(0, dsu.find(0));
    EXPECT_EQ(0, dsu.find(1));
    EXPECT_EQ(0, dsu.find(2));
}
TEST(TestDSULib, unionn_self) {
    DSU dsu(4);

    dsu.unionn(0, 0);
    dsu.unionn(1, 1);

    EXPECT_EQ(0, dsu.find(0));
    EXPECT_EQ(1, dsu.find(1));
    EXPECT_EQ(2, dsu.find(2));
}

TEST(TestDSULib, unionn_throw) {
    DSU dsu(4);

    EXPECT_ANY_THROW(dsu.unionn(-1, 3));
    EXPECT_ANY_THROW(dsu.unionn(3, 5));
}
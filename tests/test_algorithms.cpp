#include <gtest/gtest.h>
#include "../lib_algorithms/algorithms.cpp"

TEST(TestAlgorithmsLib, throw_min) {
    // Arrange
    Matrix<int> a(4, 5);

    ASSERT_ANY_THROW(search_local_minimum_in_matrix(a));
}
TEST(TestAlgorithmsLib, min_3_3) {
    // Arrange
    srand(time(0));

    Matrix<int> a(3, 3);
    int count_1 = 1, count_2 = 1, i = 100;
    bool exept = false;
    MVector<int> vec1({ 3, 1, 2 }), vec2({ 5, 8, 4 }), vec3({ 7, 6, 9 });
    a[0] = vec1;
    a[1] = vec2;
    a[2] = vec3;
    int searh_min = search_local_minimum_in_matrix(a);
    while ((count_1 != 0 || count_2 != 0) && i != 0) {
        searh_min = search_local_minimum_in_matrix(a);
        if (searh_min == 1) {
            count_1-=1;
            i-=1;
        }
        if (searh_min == 6) {
            count_2 -= 1;
            i -= 1;
        }
        if (searh_min != 6 && searh_min != 1) {
            exept = false;
            break;
        }
    }
    if (count_1 <= 0 && count_2 <= 0) {

        exept = true;
    }

    EXPECT_TRUE(exept);
}
TEST(TestAlgorithmsLib, min_4_4) {
    // Arrange
    srand(time(0));

    Matrix<int> a(4, 4);
    int count_1 = 1, count_2 = 1, i = 100;
    bool exept = false;
    MVector<int> vec1({ 11, 15, 10, 9 }), vec2({ 6, 16, 3, 8 }), vec3({ 7, 4, 2, 13 }), vec4({14, 12, 1, 5});
    a[0] = vec1;
    a[1] = vec2;
    a[2] = vec3;
    a[3] = vec4;
    int searh_min = search_local_minimum_in_matrix(a);
    while ((count_1 != 0 || count_2 != 0) && i != 0) {
        searh_min = search_local_minimum_in_matrix(a);
        if (searh_min == 6) {
            count_1 -= 1;
            i -= 1;
        }
        if (searh_min == 1) {
            count_2 -= 1;
            i -= 1;
        }
        if (searh_min != 6 && searh_min != 1) {
            exept = false;
            break;
        }
    }
    if (count_1 <= 0 && count_2 <= 0) {
        exept = true;
    }

    EXPECT_TRUE(exept);
}
TEST(TestAlgorithmsLib, min_3_3_corners) {
    // Arrange
    srand(time(0));

    Matrix<int> a(3, 3);
    int count_1 = 1, count_2 = 1, i = 100;
    bool exept = false;
    MVector<int> vec1({ 8, 9, 1 }), vec2({ 7, 4, 3 }), vec3({ 2, 5, 6 });
    a[0] = vec1;
    a[1] = vec2;
    a[2] = vec3;
    int searh_min = search_local_minimum_in_matrix(a);
    while ((count_1 != 0 || count_2 != 0) && i != 0) {
        searh_min = search_local_minimum_in_matrix(a);
        if (searh_min == 1) {
            count_1 -= 1;
            i -= 1;
        }
        if (searh_min == 2) {
            count_2 -= 1;
            i -= 1;
        }
        if (searh_min != 2 && searh_min != 1) {
            exept = false;
            break;
        }
    }
    if (count_1 <= 0 && count_2 <= 0) {

        exept = true;
    }

    EXPECT_TRUE(exept);
}
TEST(TestAlgorithmsLib, min_3_3_zenter) {
    // Arrange
    srand(time(0));

    Matrix<int> a(3, 3);
    int count_1 = 1, count_2 = 1, i = 100;
    bool exept = false;
    MVector<int> vec1({ 9, 8, 7 }), vec2({ 6, 1, 5 }), vec3({ 4, 3, 2 });
    a[0] = vec1;
    a[1] = vec2;
    a[2] = vec3;
    int searh_min = search_local_minimum_in_matrix(a);
    while ((count_1 != 0 || count_2 != 0) && i != 0) {
        searh_min = search_local_minimum_in_matrix(a);
        if (searh_min == 1) {
            count_1 -= 1;
            i -= 1;
        }
        if (searh_min == 2) {
            count_2 -= 1;
            i -= 1;
        }
        if (searh_min != 2 && searh_min != 1) {
            exept = false;
            break;
        }
    }
    if (count_1 <= 0 && count_2 <= 0) {

        exept = true;
    }

    EXPECT_TRUE(exept);
}

TEST(TestAlgorithmsLib, test_1) {
    std::string str = "((";
    EXPECT_FALSE(check_breckets(str));
}

TEST(TestAlgorithmsLib, test_2) {
    std::string str = "()";
    EXPECT_TRUE(check_breckets(str));
}
TEST(TestAlgorithmsLib, test_3) {
    std::string str = "(()";
    EXPECT_FALSE(check_breckets(str));
}
TEST(TestAlgorithmsLib, test_4) {
    std::string str = "())";
    EXPECT_FALSE(check_breckets(str));
}
TEST(TestAlgorithmsLib, test_5) {
    std::string str = "([{}])";
    EXPECT_TRUE(check_breckets(str));
}
TEST(TestAlgorithmsLib, test_6) {
    std::string str = "()({})";
    EXPECT_TRUE(check_breckets(str));
}
TEST(TestAlgorithmsLib, test_7) {
    std::string str = "({}))";
    EXPECT_FALSE(check_breckets(str));
}
TEST(TestAlgorithmsLib, test_2_1) {
    std::string str = "(2 + 3))";
    EXPECT_FALSE(read_expression(str));
}
TEST(TestAlgorithmsLib, test_2_2) {
    std::string str = "((3 + 4)";
    EXPECT_FALSE(read_expression(str));
}
TEST(TestAlgorithmsLib, test_2_3) {
    std::string str = "(a + b)";
    EXPECT_TRUE(read_expression(str));
}
TEST(TestAlgorithmsLib, test_2_4) {
    std::string str = "(a &)";
    EXPECT_FALSE(read_expression(str));
}
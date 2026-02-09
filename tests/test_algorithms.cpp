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
    MVector<int> 
        vec1({ 3, 1, 2 }),
        vec2({ 5, 8, 4 }),
        vec3({ 7, 6, 9 });
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
//TEST(TestAlgorithmsLib, test_2_1) {
//    std::string str = "(2 + 3))";
//    EXPECT_FALSE(read_expression(str));
//}
//TEST(TestAlgorithmsLib, test_2_2) {
//    std::string str = "((3 + 4)";
//    EXPECT_FALSE(read_expression(str));
//}
//TEST(TestAlgorithmsLib, test_2_3) {
//    std::string str = "(a + b)";
//    EXPECT_TRUE(read_expression(str));
//}
//TEST(TestAlgorithmsLib, test_2_4) {
//    std::string str = "(a &)";
//    EXPECT_FALSE(read_expression(str));
//}

TEST(TestListLibIterator, is_looped_first_false) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    EXPECT_FALSE(is_looped_one_test(&list));
};

TEST(TestListLibIterator, is_looped_first_true) {
    List<int> list;
    list.push_back(1);
    Node<int>* cur = list.head();
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    list.tail()->next = cur->next;

    EXPECT_EQ(true, is_looped_one_test(&list));


    list.tail()->next = nullptr;
};

TEST(TestListLibIterator, is_looped_second_true) {
    List<int> list;
    list.push_back(1);
    Node<int>* cur = list.head();
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    list.tail()->next = cur->next;

    EXPECT_EQ(true, is_looped_second_test(&list));


    list.tail()->next = nullptr;
};

TEST(TestListLibIterator, is_looped_second_false) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    EXPECT_FALSE(is_looped_second_test(&list));
};

TEST(TestListLibIterator, is_looped_third_false) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    EXPECT_EQ(nullptr, is_looped_third_test(&list));
};

TEST(TestListLibIterator, is_looped_third_true) {
    List<int> list;
    list.push_back(1);
    Node<int>* cur = list.head();
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    list.tail()->next = cur->next;

    EXPECT_EQ(list.tail()->next, is_looped_third_test(&list));

    list.tail()->next = nullptr;
};


TEST(TestIsland, island) {
    int x = 5, y = 5;
    int** mass = new int* [x];
    for (int i = 0; i < x; i++) {
        mass[i] = new int[y];
    }
    int data[5][5] = {
        {0, 1, 0, 0, 1},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1}
    };

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            mass[i][j] = data[i][j];
        }
    }

    int result = count_islands(mass, x, y);
    EXPECT_EQ(3, result);
};
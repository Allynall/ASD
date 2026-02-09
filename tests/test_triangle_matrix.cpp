#include <gtest/gtest.h>
#include "../lib_triangle_matrix/triangle_matrix.h"


TEST(TestTriangleMatrixLib, default_constructor) {
    TriangleMatrix<int> a;

    EXPECT_TRUE(a.is_empty());
    EXPECT_EQ(0, a.size());
}
TEST(TestTriangleMatrixLib, size_constructor) {
    TriangleMatrix<int> a(6, 6);

    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(6, a.get_M());
    EXPECT_EQ(6, a.get_N());
}

TEST(TestTriangleMatrixLib, size_constructor_throw_with_negative_size) {
    ASSERT_ANY_THROW(TriangleMatrix<int> a(-6, 6));
}

TEST(TestTriangleMatrixLib, size_constructor_throw_with_not_equal_size) {
    ASSERT_ANY_THROW(TriangleMatrix<int> a(6, 5));
}

TEST(TestTriangleMatrixLib, copy_constructor) {
    TriangleMatrix<int> a(6, 6), b(a);

    EXPECT_FALSE(b.is_empty());
    EXPECT_EQ(a.get_M(), b.get_M());
    EXPECT_EQ(a.get_N(), b.get_N());
    for (int i = 0; i < 6; i++) {
        for (int k = 0; k < a[i].size(); k++) {
            EXPECT_EQ(a[i][k], b[i][k]);
        }
    }
}
TEST(TestTriangleMatrixLib, throw_throm_add_matrix) {
    TriangleMatrix<int> a(6, 6), b(5, 5);

    ASSERT_ANY_THROW(a + b);
}
TEST(TestTriangleMatrixLib, add_matrix) {
    TriangleMatrix<int> a(5, 5), b(5, 5);

    for (int i = 0; i < a.get_M(); i++) {
        for (int k = 0; k < a[i].size(); k++) {
            a[i][k] = 1;
            b[i][k] = 2;
        }
    }
    a = a + b;

    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(5, a.get_M());
    EXPECT_EQ(5, a.get_N());
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < a[i].size(); k++) {
            EXPECT_EQ(3, a[i][k]);
        }
    }
}

TEST(TestTriangleMatrixLib, throw_throm_sub_matrix) {
    TriangleMatrix<int> a(6, 6), b(5, 5);

    ASSERT_ANY_THROW(a - b);
}
TEST(TestTriangleMatrixLib, sub_matrix) {
    TriangleMatrix<int> a(5, 5), b(5, 5);

    for (int i = 0; i < a.get_M(); i++) {
        for (int k = 0; k < a[i].size(); k++) {
            a[i][k] = 3;
            b[i][k] = 2;
        }
    }
    a = a - b;
    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(5, a.get_M());
    EXPECT_EQ(5, a.get_N());
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < a[i].size(); k++) {
            EXPECT_EQ(1, a[i][k]);
        }
    }
}

TEST(TestTriangleMatrixLib, mult_matrix_with_number) {
    TriangleMatrix<int> a(5, 5);
    int b = 5;

    for (int i = 0; i < a.get_M(); i++) {
        for (int k = 0; k < a[i].size(); k++) {
            a[i][k] = 2;
        }
    }

    a = a * b;
    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(5, a.get_M());
    EXPECT_EQ(5, a.get_N());
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < a[i].size(); k++) {
            EXPECT_EQ(10, a[i][k]);
        }
    }
}
TEST(TestTriangleMatrixLib, add_and_assign_matrix) {
    TriangleMatrix<int> a(5, 5), b(5, 5);

    for (int i = 0; i < a.get_M(); i++) {
        for (int k = 0; k < a[i].size(); k++) {
            a[i][k] = 1;
            b[i][k] = 2;
        }
    }

    a += b;
    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(5, a.get_M());
    EXPECT_EQ(5, a.get_N());
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < a[i].size(); k++) {
            EXPECT_EQ(3, a[i][k]);
        }
    }
}
TEST(TestTriangleMatrixLib, sub_and_assign_matrix) {
    TriangleMatrix<int> a(5, 5), b(5, 5);

    for (int i = 0; i < a.get_M(); i++) {
        for (int k = 0; k < a[i].size(); k++) {
            a[i][k] = 1;
            b[i][k] = 2;
        }
    }

    a -= b;
    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(5, a.get_M());
    EXPECT_EQ(5, a.get_N());
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < a[i].size(); k++) {
            EXPECT_EQ(-1, a[i][k]);
        }
    }
}
TEST(TestTriangleMatrixLib, mult_with_number_and_assign_matrix) {
    TriangleMatrix<int> a(5, 5);

    for (int i = 0; i < a.get_M(); i++) {
        for (int k = 0; k < a[i].size(); k++) {
            a[i][k] = 2;
        }
    }

    a *= 2;
    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(5, a.get_M());
    EXPECT_EQ(5, a.get_N());
    for (int i = 0; i < 5; i++) {
        for (int k = 0; k < a[i].size(); k++) {
            EXPECT_EQ(4, a[i][k]);
        }
    }
}
TEST(TestTriangleMatrixLib, comparison_matrix_true) {
    TriangleMatrix<int> a(5, 5), b(5, 5);

    for (int i = 0; i < a.get_M(); i++) {
        for (int k = 0; k < a[i].size(); k++) {
            a[i][k] = 2;
            b[i][k] = 2;
        }
    }

    EXPECT_TRUE(a == b);
}
TEST(TestTriangleMatrixLib, comparison_matrix_false_size) {
    TriangleMatrix<int> a(5, 5), b(4, 4);

    for (int i = 0; i < a.get_M(); i++) {
        for (int k = 0; k < a[i].size(); k++) {
            a[i][k] = 2;
            b[i][k] = 2;
        }
    }

    EXPECT_FALSE(a == b);
}
TEST(TestTriangleMatrixLib, comparison_matrix_false_number) {
    TriangleMatrix<int> a(5, 5), b(5, 5);

    for (int i = 0; i < a.get_M(); i++) {
        for (int k = 0; k < a[i].size(); k++) {
            a[i][k] = 2;
            b[i][k] = 3;
        }
    }

    EXPECT_FALSE(a == b);
}
TEST(TestTriangleMatrixLib, not_comparison_matrix_false) {
    TriangleMatrix<int> a(5, 5), b(5, 5);

    for (int i = 0; i < a.get_M(); i++) {
        for (int k = 0; k < a[i].size(); k++) {
            a[i][k] = 2;
            b[i][k] = 2;
        }
    }

    EXPECT_FALSE(a != b);
}
TEST(TestTriangleMatrixLib, not_comparison_matrix_true_size) {
    TriangleMatrix<int> a(5, 5), b(4, 4);

    for (int i = 0; i < a.get_M(); i++) {
        for (int k = 0; k < a[i].size(); k++) {
            a[i][k] = 2;
            b[i][k] = 2;
        }
    }

    EXPECT_TRUE(a != b);
}
TEST(TestTriangleMatrixLib, not_comparison_matrix_true_number) {
    TriangleMatrix<int> a(5, 5), b(5, 5);

    for (int i = 0; i < a.get_M(); i++) {
        for (int k = 0; k < a[i].size(); k++) {
            a[i][k] = 2;
            b[i][k] = 3;
        }
    }

    EXPECT_TRUE(a != b);
}

TEST(TestTriangleMatrixLib, mult_matrix_with_matrix) {
    // Arrange
    TriangleMatrix<int> a(3, 3), b(3, 3), c(3, 3);
    a[0][0] = 1;  
    a[0][1] = 2; 
    a[0][2] = 3; 

    a[1][0] = 4;  
    a[1][1] = 5;
    a[2][0] = 6; 

    for (int i = 0; i < a.get_M(); i++) {
        for (int k = 0; k < a[i].size(); k++) {
            b[i][k] = 10;
        }
    }
   
    c = a * b;

    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(3, c.get_M());
    EXPECT_EQ(3, c.get_N());
    EXPECT_EQ(10, c[0][0]);
    EXPECT_EQ(30, c[0][1]);
    EXPECT_EQ(60, c[0][2]);
    EXPECT_EQ(40, c[1][0]);
    EXPECT_EQ(90, c[1][1]);
    EXPECT_EQ(60, c[2][0]);
}
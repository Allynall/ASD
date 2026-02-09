#include <gtest/gtest.h>
#include "../lib_matrix/matrix.h"

TEST(TestMatrixLib, default_constructor) {
    // Arrange
    Matrix<int> a;
    
    EXPECT_TRUE(a.is_empty());
    EXPECT_EQ(0, a.size());
}
TEST(TestMatrixLib, size_constructor) {
    // Arrange
    Matrix<int> a(5, 6);

    EXPECT_TRUE(a.is_empty());
    EXPECT_EQ(5, a.get_M());
    EXPECT_EQ(6, a.get_N());
}

TEST(TestMatrixLib, size_constructor_throw_with_negative_size) {
    // Arrange
    ASSERT_ANY_THROW(Matrix<int> a(-6, 6));
}

TEST(TestMatrixLib, copy_constructor) {
    // Arrange
    Matrix<int> a(5, 6), b(a);

    EXPECT_TRUE(b.is_empty());
    EXPECT_EQ(a.get_M(), b.get_M());
    EXPECT_EQ(a.get_N(), b.get_N());
    EXPECT_EQ(a[0], b[0]);
    EXPECT_EQ(a[4], b[4]);
}

TEST(TestMatrixLib, throw_add_matrix) {
    // Arrange
    Matrix<int> a(5, 6), b(5, 5);

    ASSERT_ANY_THROW(a + b);
}
TEST(TestMatrixLib, add_matrix) {
    // Arrange
    Matrix<int> a(5, 6), b(5, 6);

    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = 1;
        }
    }
    for (int i = 0; i < b.get_M(); i++) {
        for (int j = 0; j < b.get_N(); j++) {
            b[i][j] = 2;
        }
    }
    a = a + b;
    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(5, a.get_M());
    EXPECT_EQ(6, a.get_N());
    EXPECT_EQ(3, a[0][0]);
    EXPECT_EQ(3, a[4][5]);
}
TEST(TestMatrixLib, throw_throm_sub_matrix) {
    // Arrange
    Matrix<int> a(5, 6), b(5, 5);

    ASSERT_ANY_THROW(a - b);
}
TEST(TestMatrixLib, sub_matrix) {
    // Arrange
    Matrix<int> a(5, 6), b(5, 6);

    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = 1;
        }
    }
    for (int i = 0; i < b.get_M(); i++) {
        for (int j = 0; j < b.get_N(); j++) {
            b[i][j] = 2;
        }
    }
    a = a - b;
    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(5, a.get_M());
    EXPECT_EQ(6, a.get_N());
    EXPECT_EQ(-1, a[0][0]);
    EXPECT_EQ(-1, a[4][5]);
}
TEST(TestMatrixLib, throw_mult_matrix_with_matrix) {
    // Arrange
    Matrix<int> a(5, 6);
    Matrix<int> b(5, 6);

    ASSERT_ANY_THROW(a * b);
}

TEST(TestMatrixLib, mult_matrix_with_matrix) {
    // Arrange
    Matrix<int> a(2, 3);
    Matrix<int> b(3, 2);
    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = 2;
        }
    }
    for (int i = 0; i < b.get_M(); i++) {
        for (int j = 0; j < b.get_N(); j++) {
            b[i][j] = 3;
        }
    }
    a = a * b;
    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(2, a.get_M());
    EXPECT_EQ(2, a.get_N());
    EXPECT_EQ(18, a[0][0]);
    EXPECT_EQ(18, a[a.get_M() - 1][a.get_N() - 1]);
}
TEST(TestMatrixLib, mult_matrix_with_number) {
    // Arrange
    Matrix<int> a(2, 3);
    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = 2;
        }
    }
    a = a * 2;
    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(2, a.get_M());
    EXPECT_EQ(3, a.get_N());
    EXPECT_EQ(4, a[0][0]);
    EXPECT_EQ(4, a[a.get_M() - 1][a.get_N() - 1]);
}
TEST(TestMatrixLib, transport_matrix) {
    // Arrange
    Matrix<int> a(2, 3);
    int count = 1;
    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = count;
            count++;
        }
    }
    a.transport();
    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(3, a.get_M());
    EXPECT_EQ(2, a.get_N());
    EXPECT_EQ(1, a[0][0]);
    EXPECT_EQ(4, a[0][1]);
    EXPECT_EQ(2, a[1][0]);
    EXPECT_EQ(6, a[a.get_M()-1][a.get_N()-1]);
}
TEST(TestMatrixLib, mult_matrix_with_vec) {
    // Arrange
    Matrix<int> a(2, 2);
    MVector<int> b({3, 2}), c({ 3, 2 });
    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = 2;
        }
    }
    c = a * b;
    EXPECT_FALSE(c.is_empty());
    EXPECT_EQ(a.get_N(), c.size());
    EXPECT_EQ(10, c[0]);
    EXPECT_EQ(10, c[1]);
}

TEST(TestMatrixLib, throw_add_and_assign_matrix) {
    // Arrange
    Matrix<int> a(5, 6), b(5, 5);

    ASSERT_ANY_THROW(a += b);
}

TEST(TestMatrixLib, add_and_assign_matrix) {
    // Arrange
    Matrix<int> a(5, 6), b(5, 6);

    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = 1;
        }
    }
    for (int i = 0; i < b.get_M(); i++) {
        for (int j = 0; j < b.get_N(); j++) {
            b[i][j] = 2;
        }
    }
    a += b;
    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(5, a.get_M());
    EXPECT_EQ(6, a.get_N());
    EXPECT_EQ(3, a[0][0]);
    EXPECT_EQ(3, a[4][5]);
}

TEST(TestMatrixLib, throw_sub_and_assign_matrix) {
    // Arrange
    Matrix<int> a(5, 6), b(5, 5);

    ASSERT_ANY_THROW(a -= b);
}

TEST(TestMatrixLib, sub_and_assign_matrix) {
    // Arrange
    Matrix<int> a(5, 6), b(5, 6);

    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = 1;
        }
    }
    for (int i = 0; i < b.get_M(); i++) {
        for (int j = 0; j < b.get_N(); j++) {
            b[i][j] = 2;
        }
    }
    a -= b;
    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(5, a.get_M());
    EXPECT_EQ(6, a.get_N());
    EXPECT_EQ(-1, a[0][0]);
    EXPECT_EQ(-1, a[4][5]);
}
TEST(TestMatrixLib, throw_mult_and_assign_matrix_with_matrix) {
    // Arrange
    Matrix<int> a(5, 6);
    Matrix<int> b(5, 6);

    ASSERT_ANY_THROW(a *= b);
}

TEST(TestMatrixLib, mult_and_assign_matrix_with_matrix) {
    // Arrange
    Matrix<int> a(2, 3);
    Matrix<int> b(3, 2);
    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = 2;
        }
    }
    for (int i = 0; i < b.get_M(); i++) {
        for (int j = 0; j < b.get_N(); j++) {
            b[i][j] = 3;
        }
    }
    a *= b;
    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(2, a.get_M());
    EXPECT_EQ(2, a.get_N());
    EXPECT_EQ(18, a[0][0]);
    EXPECT_EQ(18, a[a.get_M() - 1][a.get_N() - 1]);
}

TEST(TestMatrixLib, mult_and_assign_matrix_with_number) {
    // Arrange
    Matrix<int> a(2, 3);
    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = 2;
        }
    }
    a *= 2;
    EXPECT_FALSE(a.is_empty());
    EXPECT_EQ(2, a.get_M());
    EXPECT_EQ(3, a.get_N());
    EXPECT_EQ(4, a[0][0]);
    EXPECT_EQ(4, a[a.get_M() - 1][a.get_N() - 1]);
}

TEST(TestMatrixLib, comparison_matrix_true) {
    // Arrange
    Matrix<int> a(2, 3);
    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = 2;
        }
    }
    Matrix<int> b(a);
    EXPECT_TRUE(a == b);
}

TEST(TestMatrixLib, comparison_matrix_false_size) {
    // Arrange
    Matrix<int> a(2, 3);
    Matrix<int> b(3, 2);
    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = 2;
        }
    }
    for (int i = 0; i < b.get_M(); i++) {
        for (int j = 0; j < b.get_N(); j++) {
            b[i][j] = 3;
        }
    }
    EXPECT_FALSE(a == b);
}

TEST(TestMatrixLib, comparison_matrix_false_num) {
    // Arrange
    Matrix<int> a(2, 3);
    Matrix<int> b(2, 3);
    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = 2;
        }
    }
    for (int i = 0; i < b.get_M(); i++) {
        for (int j = 0; j < b.get_N(); j++) {
            b[i][j] = 3;
        }
    }
    EXPECT_FALSE(a == b);
}


TEST(TestMatrixLib, not_comparison_matrix_true_size) {
    // Arrange
    Matrix<int> a(2, 3);
    Matrix<int> b(3, 2);
    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = 2;
        }
    }
    for (int i = 0; i < b.get_M(); i++) {
        for (int j = 0; j < b.get_N(); j++) {
            b[i][j] = 3;
        }
    }
    EXPECT_TRUE(a != b);
}

TEST(TestMatrixLib, not_comparison_matrix_true_num) {
    // Arrange
    Matrix<int> a(2, 3);
    Matrix<int> b(2, 3);
    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = 2;
        }
    }
    for (int i = 0; i < b.get_M(); i++) {
        for (int j = 0; j < b.get_N(); j++) {
            b[i][j] = 3;
        }
    }
    EXPECT_TRUE(a != b);
}
TEST(TestMatrixLib, not_comparison_matrix_false) {
    // Arrange
    Matrix<int> a(2, 3);
    for (int i = 0; i < a.get_M(); i++) {
        for (int j = 0; j < a.get_N(); j++) {
            a[i][j] = 2;
        }
    }
    Matrix<int> b(a);
    EXPECT_FALSE(a != b);
}
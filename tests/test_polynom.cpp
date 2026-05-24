#include <gtest/gtest.h>
#include <iostream>
#include "../lib_polynom/polynom.h"

TEST(TestPolynomLib, construct_polynom) {
	Polynom polynom;
	List<Monom> monoms = polynom.Monoms();

	EXPECT_TRUE(monoms.is_empty());
}

TEST(TestPolynomLib, construct_polynom_with_monom) {
	int powers[VARS_COUNT] = { 0, 1, 2 };
	Monom monom(5.0, powers);
	Polynom polynom(monom);

    List<Monom> monoms = polynom.Monoms();
    Monom monom_in_polynom = *monoms.begin();


    EXPECT_EQ(5.0, monom_in_polynom.Coeff());
    for (size_t i = 0; i < VARS_COUNT; i++) {
        EXPECT_EQ(i, monom_in_polynom.Power(i));  
    }
}

TEST(TestPolynomLib, ñopy_construct_polynom) {
    Polynom polynom1("5yz^2 + 7yz^2");
    Polynom polynom2(polynom1);

    List<Monom> monoms = polynom2.Monoms();
    Monom monom_in_polynom = *monoms.begin();

    EXPECT_EQ(12.0, monom_in_polynom.Coeff());
    for (size_t i = 0; i < VARS_COUNT; i++) {
        EXPECT_EQ(i, monom_in_polynom.Power(i));
    }
}

TEST(TestPolynomLib, construct_polynom_with_str) {
    Polynom polynom("5x^3+4y^2+6z");

    double point[3] = { 2, 3, 4 };
    EXPECT_EQ(100.0, polynom.evaluate(point));
}

TEST(TestPolynomLib, assignment_polynom) {
    Polynom polynom1("5yz^2 + 7yz^2");
    Polynom polynom2 = polynom1;

    List<Monom> monoms = polynom2.Monoms();
    Monom monom_in_polynom = *monoms.begin();

    EXPECT_EQ(12.0, monom_in_polynom.Coeff());
    for (size_t i = 0; i < VARS_COUNT; i++) {
        EXPECT_EQ(i, monom_in_polynom.Power(i));
    }
}

TEST(TestPolynomLib, unary_minus_sign_polynom) {
    Polynom polynom1("5yz^2 + 7yz^2");
    Polynom polynom2 = -polynom1;

    List<Monom> monoms = polynom2.Monoms();
    Monom monom_in_polynom = *monoms.begin();

    EXPECT_EQ(-12.0, monom_in_polynom.Coeff());
    for (size_t i = 0; i < VARS_COUNT; i++) {
        EXPECT_EQ(i, monom_in_polynom.Power(i));
    }
}

TEST(TestPolynomLib, add_polynom_with_polynom) {
    Polynom polynom1("5x^3+4y^2");
    Polynom polynom2("6x^2+7y^2");
    Polynom polynom3 = polynom1 + polynom2;

    std::stringstream out;
    out << polynom3;

    EXPECT_EQ(out.str(), "5x^3 + 6x^2 + 11y^2");
}

TEST(TestPolynomLib, sub_polynom_with_polynom) {
    Polynom polynom1("5x^3+4y^2");
    Polynom polynom2("6x^2+7y^2");
    Polynom polynom3 = polynom1 - polynom2;

    std::stringstream out;
    out << polynom3;

    EXPECT_EQ(out.str(), "5x^3 - 6x^2 - 3y^2");
}
TEST(TestPolynomLib, mult_polynom_with_polynom) {
    Polynom polynom1("5x^2");
    Polynom polynom2("6x^2+7y^2");
    Polynom polynom3 = polynom1 * polynom2;

    std::stringstream out;
    out << polynom3;

    EXPECT_EQ(out.str(), "30x^4 + 35x^2y^2");
}


TEST(TestPolynomLib, add_and_assignment_polynom_wirh_polynom) {
    Polynom polynom1("5x^3+4y^2");
    Polynom polynom2("6x^2+7y^2");
    polynom2 += polynom1;

    std::stringstream out;
    out << polynom2;

    EXPECT_EQ(out.str(), "5x^3 + 6x^2 + 11y^2");
}

TEST(TestPolynomLib, sub_and_assignment_polynom_wirh_polynom) {
    Polynom polynom1("5x^3+4y^2");
    Polynom polynom2("6x^2+7y^2");
    polynom1 -= polynom2;

    std::stringstream out;
    out << polynom1;
    EXPECT_EQ(out.str(), "5x^3 - 6x^2 - 3y^2");
}
TEST(TestPolynomLib, mult_and_assignment_polynom_wirh_polynom) {
    Polynom polynom1("5x^2");
    Polynom polynom2("6x^2+7y^2");
    polynom2 *= polynom1;

    std::stringstream out;
    out << polynom2;
    EXPECT_EQ(out.str(), "30x^4 + 35x^2y^2");
} 
TEST(TestPolynomLib, mult_polynom_wirh_num) {
    Polynom polynom1("5x^3+4y^2+6z");
    Polynom polynom2 = polynom1 * 3;
    std::stringstream out;
    out << polynom2;
    EXPECT_EQ(out.str(), "15x^3 + 12y^2 + 18z");
}
TEST(TestPolynomLib, div_polynom_wirh_num) {
    Polynom polynom1("5x^3+4y^2+6z");
    Polynom polynom2 = polynom1 / 2;
    std::stringstream out;
    out << polynom2;
    EXPECT_EQ(out.str(), "2.5x^3 + 2y^2 + 3z");
}

TEST(TestPolynomLib, div_polynom_wirh_num_throw) {
    Polynom polynom1("5x^3+4y^2+6z");
    EXPECT_ANY_THROW(Polynom polynom2 = polynom1 / 0);
}

TEST(TestPolynomLib, mult_and_assignment_polynom_wirh_num) {
    Polynom polynom1("5x^3+4y^2+6z");
    polynom1 *= 3;
    std::stringstream out;
    out << polynom1;
    EXPECT_EQ(out.str(), "15x^3 + 12y^2 + 18z");
}

TEST(TestPolynomLib, div_and_assignment_polynom_wirh_num) {
    Polynom polynom1("5x^3+4y^2+6z");
    polynom1 /= 2;
    std::stringstream out;
    out << polynom1;
    EXPECT_EQ(out.str(), "2.5x^3 + 2y^2 + 3z");
}

TEST(TestPolynomLib, add_polynom_with_monom) {
    Polynom polynom1("5x^3+4y^2+6z");
    int powers[VARS_COUNT] = { 2, 4, 2 };
    Monom monom(6.0, powers);

    Polynom polynom2 = polynom1 + monom;
    std::stringstream out;
    out << polynom2;
    EXPECT_EQ(out.str(), "5x^3 + 6x^2y^4z^2 + 4y^2 + 6z");
}

TEST(TestPolynomLib, sub_polynom_with_monom) {
    Polynom polynom1("5x^3+4y^2+6z");
    int powers[VARS_COUNT] = { 2, 4, 2 };
    Monom monom(6.0, powers);

    Polynom polynom2 = polynom1 - monom;
    std::stringstream out;
    out << polynom2;
    EXPECT_EQ(out.str(), "5x^3 - 6x^2y^4z^2 + 4y^2 + 6z");
}

TEST(TestPolynomLib, mult_polynom_with_monom) {
    Polynom polynom1("5x^3+6z");
    int powers[VARS_COUNT] = { 2, 4, 2 };
    Monom monom(6.0, powers);

    Polynom polynom2 = polynom1 * monom;
    std::stringstream out;
    out << polynom2;
    EXPECT_EQ(out.str(), "30x^5y^4z^2 + 36x^2y^4z^3");
}

TEST(TestPolynomLib, div_polynom_with_monom) {
    Polynom polynom1("30x^5y^4z^2 + 24x^2y^6z^2");
    int powers[VARS_COUNT] = { 2, 4, 2 };
    Monom monom(6.0, powers);

    Polynom polynom2 = polynom1 / monom;
    std::stringstream out;
    out << polynom2;
    EXPECT_EQ(out.str(), "5x^3 + 4y^2");
}

TEST(TestPolynomLib, add_and_assignment_polynom_with_monom) {
    Polynom polynom("5x^3+4y^2+6z");
    int powers[VARS_COUNT] = { 2, 4, 2 };
    Monom monom(6.0, powers);

    polynom += monom;
    std::stringstream out;
    out << polynom;
    EXPECT_EQ(out.str(), "5x^3 + 6x^2y^4z^2 + 4y^2 + 6z");
}

TEST(TestPolynomLib, sub_and_assignment_polynom_with_monom) {
    Polynom polynom("5x^3+4y^2+6z");
    int powers[VARS_COUNT] = { 2, 4, 2 };
    Monom monom(6.0, powers);

    polynom -= monom;
    std::stringstream out;
    out << polynom;
    EXPECT_EQ(out.str(), "5x^3 - 6x^2y^4z^2 + 4y^2 + 6z");
}

TEST(TestPolynomLib, mult_and_assignment_polynom_with_monom) {
    Polynom polynom("5x^3+6z");
    int powers[VARS_COUNT] = { 2, 4, 2 };
    Monom monom(6.0, powers);

    polynom *= monom;
    std::stringstream out;
    out << polynom;
    EXPECT_EQ(out.str(), "30x^5y^4z^2 + 36x^2y^4z^3");
}

TEST(TestPolynomLib, div_and_assignment_polynom_with_monom) {
    Polynom polynom("30x^5y^4z^2 + 24x^2y^6z^2");
    int powers[VARS_COUNT] = { 2, 4, 2 };
    Monom monom(6.0, powers);

    polynom /= monom;
    std::stringstream out;
    out << polynom;
    EXPECT_EQ(out.str(), "5x^3 + 4y^2");
}

TEST(TestPolynomLib, input_polynom_throw_point) {
    EXPECT_ANY_THROW(Polynom polynom("30x^5y^4z^2 + 2..4x^2y^6z^2"));
}
TEST(TestPolynomLib, input_polynom_throw_coeff) {
    EXPECT_ANY_THROW(Polynom polynom("30x^5y^4z^2 + 24x^2y^6z^2v"));
}
TEST(TestPolynomLib, input_polynom_throw_ends) {
    EXPECT_ANY_THROW(Polynom polynom("30x^5y^4z^2 + 24x^2y^6z^2 +"));
}
TEST(TestPolynomLib, input_polynom_throw_operators) {
    EXPECT_ANY_THROW(Polynom polynom("30x^5y^4z^2 +++ 24x^2y^6z^2"));
}

TEST(TestPolynomLib, input_polynom_throw_) {
    EXPECT_ANY_THROW(Polynom polynom("30x^5y^4z^^2"));
}
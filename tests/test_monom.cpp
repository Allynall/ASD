#include <gtest/gtest.h>
#include <iostream>
#include "../lib_monom/monom.h"

TEST(TestMonomLib, construct_monom) {
	Monom monom;
	
	EXPECT_EQ(0, monom.Coeff());
	for (size_t i = 0; i < VARS_COUNT; i++) {
		EXPECT_EQ(0, monom.Power(i));
	}
}

TEST(TestMonomLib, construct_monom_wirh_param) {
	int powers[VARS_COUNT] = { 0, 1, 2 };
	Monom monom(5.0, powers);

	EXPECT_EQ(5.0, monom.Coeff());
	for (size_t i = 0; i < VARS_COUNT; i++) {
		EXPECT_EQ(i, monom.Power(i));
	}
}

TEST(TestMonomLib, copy_construct_monom) {
	int powers[VARS_COUNT] = { 0, 1, 2 };
	Monom monom1(5.0, powers);
	Monom monom2(monom1);

	EXPECT_EQ(monom1.Coeff(), monom2.Coeff());
	for (size_t i = 0; i < VARS_COUNT; i++) {
		EXPECT_EQ(i, monom2.Power(i));
	}
}

TEST(TestMonomLib, power_monom) {
	int powers[VARS_COUNT] = { 0, 4, 2 };
	Monom monom(5.0, powers);

	
	EXPECT_EQ(4, monom.Power(1));
	
}
TEST(TestMonomLib, similarity_monom_true) {
	int powers1[VARS_COUNT] = { 1, 2, 3 };
	int powers2[VARS_COUNT] = { 1, 2, 3 };
	Monom monom1(5.0, powers1);
	Monom monom2(6.0, powers2);


	EXPECT_TRUE(monom1 == monom2);
}

TEST(TestMonomLib, not_similarity_monom) {
	int powers1[VARS_COUNT] = { 5, 2, 3 };
	int powers2[VARS_COUNT] = { 1, 2, 3 };
	Monom monom1(5.0, powers1);
	Monom monom2(6.0, powers2);


	EXPECT_TRUE(monom1 != monom2);
}

TEST(TestMonomLib,unary_minus_sign_monom) {
	int powers1[VARS_COUNT] = { 0, 1, 2 };
	Monom monom1(5.0, powers1);
	Monom monom2 = -monom1;

	EXPECT_EQ(-5.0, monom2.Coeff());
	for (size_t i = 0; i < VARS_COUNT; i++) {
		EXPECT_EQ(i, monom2.Power(i));
	}
}

TEST(TestMonomLib, add_monom_throw) {
	int powers1[VARS_COUNT] = { 5, 2, 3 };
	int powers2[VARS_COUNT] = { 1, 2, 3 };
	Monom monom1(5.0, powers1);
	Monom monom2(6.0, powers2);


	EXPECT_ANY_THROW(monom1 + monom2);
}

TEST(TestMonomLib, add_monom) {
	int powers1[VARS_COUNT] = { 0, 1, 2 };
	int powers2[VARS_COUNT] = { 0, 1, 2 };
	Monom monom1(5.0, powers1);
	Monom monom2(6.0, powers2);
	Monom monom3 = monom1 + monom2;

	EXPECT_EQ(11.0, monom3.Coeff());
	for (size_t i = 0; i < VARS_COUNT; i++) {
		EXPECT_EQ(i, monom3.Power(i));
	}
}

TEST(TestMonomLib, sub_monom_throw) {
	int powers1[VARS_COUNT] = { 5, 2, 3 };
	int powers2[VARS_COUNT] = { 1, 2, 3 };
	Monom monom1(5.0, powers1);
	Monom monom2(6.0, powers2);


	EXPECT_ANY_THROW(monom1 - monom2);
}

TEST(TestMonomLib, sub_monom) {
	int powers1[VARS_COUNT] = { 0, 1, 2 };
	int powers2[VARS_COUNT] = { 0, 1, 2 };
	Monom monom1(8.0, powers1);
	Monom monom2(6.0, powers2);
	Monom monom3 = monom1 - monom2;

	EXPECT_EQ(2.0, monom3.Coeff());
	for (size_t i = 0; i < VARS_COUNT; i++) {
		EXPECT_EQ(i, monom3.Power(i));
	}
}

TEST(TestMonomLib, mult_monom) {
	int powers1[VARS_COUNT] = { 1, 2, 3 };
	int powers2[VARS_COUNT] = { 2, 4, 5 };
	Monom monom1(8.0, powers1);
	Monom monom2(6.0, powers2);
	Monom monom3 = monom1 * monom2;

	EXPECT_EQ(48.0, monom3.Coeff());
	EXPECT_EQ(3, monom3.Power(0));
	EXPECT_EQ(6, monom3.Power(1));
	EXPECT_EQ(8, monom3.Power(2));
}

TEST(TestMonomLib, div_monom_throw) {
	int powers1[VARS_COUNT] = { 5, 2, 3 };
	int powers2[VARS_COUNT] = { 1, 2, 3 };
	Monom monom1(5.0, powers1);
	Monom monom2(0, powers2);


	EXPECT_ANY_THROW(monom1 / monom2);
}

TEST(TestMonomLib, div_monom) {
	int powers1[VARS_COUNT] = { 1, 2, 3 };
	int powers2[VARS_COUNT] = { 2, 4, 5 };
	Monom monom1(12.0, powers1);
	Monom monom2(6.0, powers2);
	Monom monom3 = monom2 / monom1;

	EXPECT_EQ(0.5, monom3.Coeff());
	EXPECT_EQ(1, monom3.Power(0));
	EXPECT_EQ(2, monom3.Power(1));
	EXPECT_EQ(2, monom3.Power(2));
}

TEST(TestMonomLib, mult_monom_with_num) {
	int powers1[VARS_COUNT] = { 0, 1, 2 };
	Monom monom1(8.0, powers1);
	Monom monom2 = monom1 * 5;

	EXPECT_EQ(40.0, monom2.Coeff());
	for (size_t i = 0; i < VARS_COUNT; i++) {
		EXPECT_EQ(i, monom2.Power(i));
	}
}
TEST(TestMonomLib, div_monom_with_num) {
	int powers1[VARS_COUNT] = { 0, 1, 2 };
	Monom monom1(10.0, powers1);
	Monom monom2 = monom1 / 5;

	EXPECT_EQ(2.0, monom2.Coeff());
	for (size_t i = 0; i < VARS_COUNT; i++) {
		EXPECT_EQ(i, monom2.Power(i));
	}
}
TEST(TestMonomLib, add_and_assignment_monom) {
	int powers1[VARS_COUNT] = { 0, 1, 2 };
	int powers2[VARS_COUNT] = { 0, 1, 2 };
	Monom monom1(5.0, powers1);
	Monom monom2(6.0, powers2);
	monom2 += monom1;

	EXPECT_EQ(11.0, monom2.Coeff());
	for (size_t i = 0; i < VARS_COUNT; i++) {
		EXPECT_EQ(i, monom2.Power(i));
	}
}

TEST(TestMonomLib, sub_and_assignment_monom) {
	int powers1[VARS_COUNT] = { 0, 1, 2 };
	int powers2[VARS_COUNT] = { 0, 1, 2 };
	Monom monom1(5.0, powers1);
	Monom monom2(6.0, powers2);
	monom2 -= monom1;

	EXPECT_EQ(1.0, monom2.Coeff());
	for (size_t i = 0; i < VARS_COUNT; i++) {
		EXPECT_EQ(i, monom2.Power(i));
	}
}

TEST(TestMonomLib, mult_and_assignment_monom) {
	int powers1[VARS_COUNT] = { 1, 2, 2 };
	int powers2[VARS_COUNT] = { 2, 4, 6 };
	Monom monom1(5.0, powers1);
	Monom monom2(6.0, powers2);
	monom2 *= monom1;

	EXPECT_EQ(30.0, monom2.Coeff());
	EXPECT_EQ(3, monom2.Power(0));
	EXPECT_EQ(6, monom2.Power(1));
	EXPECT_EQ(8, monom2.Power(2));
}


TEST(TestMonomLib, div_and_assignment_monom) {
	int powers1[VARS_COUNT] = { 1, 2, 2 };
	int powers2[VARS_COUNT] = { 2, 4, 6 };
	Monom monom1(2.0, powers1);
	Monom monom2(8.0, powers2);
	monom2 /= monom1;

	EXPECT_EQ(4.0, monom2.Coeff());
	EXPECT_EQ(1, monom2.Power(0));
	EXPECT_EQ(2, monom2.Power(1));
	EXPECT_EQ(4, monom2.Power(2));
}

TEST(TestMonomLib, mult_and_assignment_monom_with_num) {
	int powers1[VARS_COUNT] = { 0, 1, 2 };
	Monom monom1(5.0, powers1);
	monom1 *= 2.0;

	EXPECT_EQ(10.0, monom1.Coeff());
	for (size_t i = 0; i < VARS_COUNT; i++) {
		EXPECT_EQ(i, monom1.Power(i));
	}
}

TEST(TestMonomLib, div_and_assignment_monom_with_num) {
	int powers1[VARS_COUNT] = { 0, 1, 2 };
	Monom monom1(6.0, powers1);
	monom1 /= 2.0;

	EXPECT_EQ(3.0, monom1.Coeff());
	for (size_t i = 0; i < VARS_COUNT; i++) {
		EXPECT_EQ(i, monom1.Power(i));
	}
}

TEST(TestMonomLib, evaluate_monom_null_point) {
	int powers1[VARS_COUNT] = { 3, 1, 2 };
	Monom monom1(0.0, powers1);
	double point[3] = { 2, 4, 5 };

	EXPECT_EQ(0.0, monom1.evaluate(point));
}

TEST(TestMonomLib, evaluate_monom) {
	int powers1[VARS_COUNT] = { 3, 1, 2 };
	Monom monom1(6.0, powers1);
	double point[3] = { 2, 4, 5 };
	
	EXPECT_EQ(4800.0, monom1.evaluate(point));
}
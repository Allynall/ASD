#pragma once
#include <iostream>

#define VARS_COUNT 3

class Monom {
	double _coeff;
	int _powers[VARS_COUNT];
public:
	Monom(); //++
	Monom(double coeff, const int* powers); //++
	Monom(const Monom& other); //++

	double Coeff() const noexcept; //++
	int Power(size_t pos) const noexcept; //++

	Monom operator+(const Monom& other) const;  //++
	Monom operator-(const Monom& other) const;  //++
	Monom operator*(const Monom& other) const noexcept; //++
	Monom operator/(const Monom& other) const; //++

	Monom operator*(double num) const noexcept; //++
	Monom operator/(double num) const; //++

	bool operator==(const Monom& other) const; //++
	bool operator!=(const Monom& other) const; //++

	Monom& operator=(const Monom& other); //++

	Monom operator-() const; //++

	Monom& operator+=(const Monom& other); //++
	Monom& operator-=(const Monom& other); //++
	Monom& operator*=(const Monom& other); //++
	Monom& operator/=(const Monom& other); //++
	Monom& operator*=(double num) noexcept; //++
	Monom& operator/=(double num); //++

	double evaluate(const double* values) const; //++

	friend std::ostream& operator<<(std::ostream& os, const Monom& monom); //++
	friend std::istream& operator>>(std::istream& is, Monom& monom); //++
};


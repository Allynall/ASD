#pragma once
#include <iostream>
#include "../lib_list/list.h"
#include "../lib_monom/monom.h"

class Polynom {
private:
	List<Monom> _monoms;
public:
	Polynom(); //++
	Polynom(const Polynom& other); //++
	Polynom(const std::string& str); //++
	Polynom(const Monom& monom); //++
    ~Polynom() = default;  //++

	const List<Monom>& Monoms() const noexcept; //++

	Polynom& operator=(const Polynom& other); //++

	Polynom operator-() const; //++

	Polynom operator+(const Polynom& other) const noexcept;  //++
	Polynom operator-(const Polynom& other) const noexcept;  //++
	Polynom operator*(const Polynom& other) const noexcept; //++
	//Polynom operator/(const Polynom& other) const; //++

	Polynom& operator+=(const Polynom& other) noexcept; //++
	Polynom& operator-=(const Polynom& other) noexcept; //++
	Polynom& operator*=(const Polynom& other) noexcept; //++
	//Polynom& operator/=(const Polynom& other); //++

	//С числом
	Polynom operator*(double num) const noexcept; //++
	Polynom operator/(double num) const; //++

	Polynom& operator*=(double num) noexcept; //++
	Polynom& operator/=(double num); //++

	//Полином с мономом
	Polynom operator+(const Monom& monom) const noexcept; //++
	Polynom operator-(const Monom& monom) const noexcept; //++
	Polynom operator*(const Monom& monom) const noexcept; //++
	Polynom operator/(const Monom& monom) const; //++

	Polynom& operator+=(const Monom& monom) noexcept; //++
	Polynom& operator-=(const Monom& monom) noexcept; //++
	Polynom& operator*=(const Monom& monom) noexcept; //++
	Polynom& operator/=(const Monom& monom); //++

	double evaluate(const double* values) const noexcept; //++

	friend std::ostream& operator<<(std::ostream& os, const Polynom& polynom); //++
	friend std::istream& operator>>(std::istream& is, Polynom& polynom); //++

private:
	void insert_sorted(const Monom& monom);
};

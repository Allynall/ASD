#include <iostream>
#include <stdexcept>
#include <math.h>

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


	// проверка подобия
	bool operator==(const Monom& other) const; //++
	bool operator!=(const Monom& other) const; //++

	Monom& operator=(const Monom& other); //++

	//унарный минус
	Monom operator-() const; //++

	Monom& operator+=(const Monom& other); //++
	Monom& operator-=(const Monom& other); //++
	Monom& operator*=(const Monom& other); //++
	Monom& operator/=(const Monom& other); //++
	Monom& operator*=(double num) noexcept; //++
	Monom& operator/=(double num); //++

	double evaluate(const double* values) const; //++

	friend std::ostream& operator<<(std::ostream& os, const Monom& monom); //++
	friend std::istream& operator>>(std::istream& is, Monom& monom); //
};

Monom::Monom() {
	_coeff = 0;
	for (int i = 0; i < VARS_COUNT; i++) {
		_powers[i] = 0;
	}
}

Monom::Monom(const Monom& other) {
	_coeff = other._coeff;
	for (int i = 0; i < VARS_COUNT; i++) {
		_powers[i] = other._powers[i];
	}
}

Monom::Monom(double coeff, const int* powers) : _coeff(coeff) {
	for (int i = 0; i < VARS_COUNT; i++) {
		_powers[i] = powers[i];
	}
}

double Monom::Coeff() const noexcept {
	return _coeff;
}
int Monom::Power(size_t pos) const noexcept {
	return _powers[pos];
}

bool Monom::operator==(const Monom& other) const{
	for (int i = 0; i < VARS_COUNT; i++) {
		if (_powers[i] != other._powers[i]) {
			return false;
		}
	}
	return true;
}

bool Monom::operator!=(const Monom& other) const {
	return !(*this == other);
}

Monom Monom::operator-() const {
	Monom result(*this);
	result._coeff = -result._coeff;
	return result;
}

Monom& Monom::operator=(const Monom& other) {
	if (this != &other) {
		_coeff = other._coeff;
		for (int i = 0; i < VARS_COUNT; i++) {
			_powers[i] = other._powers[i];
		}
	}
	return *this;
}

Monom Monom::operator+(const Monom& other) const {
	if (*this != other) {
		throw std::invalid_argument("Monomes are not similar");
	}
	Monom result(*this);
	result._coeff += other._coeff;
	return result;
}
Monom Monom::operator-(const Monom& other) const {
	if (*this != other) {
		throw std::invalid_argument("Monomes are not similar");
	}
	Monom result(*this);
	result._coeff -= other._coeff;
	return result;
}

Monom Monom::operator*(const Monom& other) const noexcept {
	Monom result;
	result._coeff = _coeff * other._coeff;
	for (int i = 0; i < VARS_COUNT; i++) {
		result._powers[i] = _powers[i] + other._powers[i];
	}
	return result;
}

Monom Monom::operator/(const Monom& other) const {
	Monom result;
	if (other._coeff == 0) {
		throw std::invalid_argument("Division by zero");
	}
	result._coeff = _coeff / other._coeff;
	for (int i = 0; i < VARS_COUNT; i++) {
		result._powers[i] = _powers[i] - other._powers[i];
		//powers 0
	}
	return result;
}

Monom Monom::operator*(double num) const noexcept {
	Monom result(*this);
	result._coeff *= num;
	return result;
}

Monom Monom::operator/(double num) const {
	Monom result(*this);
	result._coeff /= num;
	return result;
}

Monom& Monom::operator+=(const Monom& other) {
	*this = *this + other;
	return *this;
}

Monom& Monom::operator-=(const Monom& other) {
	*this = *this - other;
	return *this;
}

Monom& Monom::operator*=(const Monom& other) {
	*this = *this * other;
	return *this;
}

Monom& Monom::operator/=(const Monom& other) {
	*this = *this / other;
	return *this;
}

Monom& Monom::operator*=(double num) noexcept {
	_coeff *= num;
	return *this;
}

Monom& Monom::operator/=(double num) {
	if (num == 0) {
		throw std::invalid_argument("Division by zero");
	}
	_coeff /= num;
	return *this;
}

double Monom::evaluate(const double* values) const {
	if (_coeff == 0) return 0.0;

	double result = _coeff;
	for (int i = 0; i < VARS_COUNT; i++) {
		result *= (pow(values[i], _powers[i]));
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const Monom& monom) {

	os << "M(x, y, z) = ";

	if (monom._coeff == 0) {
		os << "0";
		return os;
	}

	bool isFirst = true;
	if (monom._coeff != 1 && monom._coeff != -1) {
		os << monom._coeff;
		isFirst = false;
	}
	else if (monom._coeff == -1) {
		os << "-";
		isFirst = false;
	}

	bool hasVars = false;
	char varNames[] = { 'x', 'y', 'z' }; 

	for (int i = 0; i < VARS_COUNT; i++) {
		if (monom._powers[i] != 0) {
			hasVars = true;

			os << varNames[i];
			if (monom._powers[i] != 1) {
				os << "^" << monom._powers[i];
			}
		}
	}
	return os;
}
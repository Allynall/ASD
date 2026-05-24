#include "../lib_monom/monom.h"
#include <stdexcept>
#include <math.h>

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

bool Monom::operator==(const Monom& other) const {
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
	}
	return result;
}

Monom Monom::operator*(double num) const noexcept {
	Monom result(*this);
	result._coeff *= num;
	return result;
}

Monom Monom::operator/(double num) const {
	if (num == 0) {
		throw std::invalid_argument("Division by zero");
	}
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
	*this = *this * num;
	return *this;
}

Monom& Monom::operator/=(double num) {
	*this = *this / num;
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
	if (monom._coeff == 0) {
		os << "0";
		return os;
	}


	if (monom._coeff != 1 && monom._coeff != -1) {
		os << monom._coeff;
	}
	else if (monom._coeff == -1) {
		os << "-";
	}

	char varNames[] = { 'x', 'y', 'z' };

	for (int i = 0; i < VARS_COUNT; i++) {
		if (monom._powers[i] != 0) {

			os << varNames[i];
			if (monom._powers[i] != 1) {
				os << "^" << monom._powers[i];
			}
		}
	}
	return os;
}

std::istream& operator>>(std::istream& is, Monom& monom) {
	double coeff = 0;
	int powers[VARS_COUNT] = { 0 };

	is >> coeff;

	if (coeff == 0) {
		monom = Monom(0, powers);
		return is;
	}

	char varNames[] = { 'x', 'y', 'z' };
	char c;
	int power;

	while (is >> c) {
		bool found = false;
		for (int i = 0; i < VARS_COUNT; i++) {
			if (c == varNames[i]) {
				found = true;
				if (is.peek() == '^') {
					is.get(); 

					if (is.peek() == '^') {
						throw std::invalid_argument("Invalid format: double ^^");
					}

					is >> power;
					powers[i] = power;
				}
				else {
					powers[i] = 1;
				}
				break;
			}
		}

		if (!found) {
			is.putback(c);
			break;
		}
	}

	monom = Monom(coeff, powers);
	return is;
}

#include "../lib_polynom/polynom.h"
#include <stdexcept>

#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <cmath>

Polynom::Polynom() {}

Polynom::Polynom(const Polynom& other) : _monoms(other._monoms) {}

Polynom::Polynom(const Monom& monom) {
	if (monom.Coeff() != 0) {
		_monoms.push_back(monom);
	}
}
const List<Monom>& Polynom::Monoms() const noexcept{
	return _monoms;
}
Polynom Polynom::operator-() const {
	Polynom result(*this);
	for (List<Monom>::Iterator it = (result._monoms).begin(); it != (result._monoms).end(); ++it) {
		*it = -(*it);
	}
	return result;
}

Polynom& Polynom::operator=(const Polynom& other) {
	if (this != &other) {
		_monoms = other._monoms;
	}
	return *this;
}

Polynom Polynom::operator+(const Polynom& other) const noexcept {
	Polynom result(*this);

	for (List<Monom>::Iterator it = other._monoms.begin(); it != other._monoms.end(); ++it) {
		result += *it;
	}

	return result;
}

Polynom Polynom::operator-(const Polynom& other) const noexcept {
	Polynom result(*this);

	for (List<Monom>::Iterator it = other._monoms.begin(); it != other._monoms.end(); ++it) {
		result -= *it;
	}

	return result;
}

Polynom Polynom::operator*(const Polynom& other) const noexcept {
	Polynom result;

	for (List<Monom>::Iterator it1 = _monoms.begin(); it1 != _monoms.end(); ++it1) {
		for (List<Monom>::Iterator it2 = other._monoms.begin(); it2 != other._monoms.end(); ++it2) {
			result += *it1 * *it2;
		}
	}
	return result;
}


Polynom Polynom::operator*(double num) const noexcept {
	Polynom result(*this);
	for (List<Monom>::Iterator it = result._monoms.begin(); it != result._monoms.end(); ++it) {
		*it *= num;
	}
	return result;
}

Polynom Polynom::operator/(double num) const {
	if (num == 0) {
		throw std::invalid_argument("Division by zero");
	}
	Polynom result(*this);
	for (List<Monom>::Iterator it = result._monoms.begin(); it != result._monoms.end(); ++it) {
		*it /= num;
	}
	return result;
}

Polynom& Polynom::operator+=(const Polynom& other) noexcept {
	*this = *this + other;
	return *this;
}

Polynom& Polynom::operator-=(const Polynom& other) noexcept {
	*this = *this - other;
	return *this;
}

Polynom& Polynom::operator*=(const Polynom& other) noexcept {
	*this = *this * other;
	return *this;
}

Polynom& Polynom::operator*=(double num) noexcept {
	for (List<Monom>::Iterator it = _monoms.begin(); it != _monoms.end(); ++it) {
		(*it) *= num;
	}
	return *this;
}

Polynom& Polynom::operator/=(double num) {
	for (List<Monom>::Iterator it = _monoms.begin(); it != _monoms.end(); ++it) {
		(*it) /= num;
	}
	return *this;
}

Polynom Polynom::operator+(const Monom& monom) const noexcept {
	Polynom result(*this);
	result.insert_sorted(monom);
	return result;
}

Polynom Polynom::operator-(const Monom& monom) const noexcept {
	Polynom result(*this);
	result.insert_sorted(-monom);
	return result;
}
Polynom Polynom::operator*(const Monom& monom) const noexcept {
	Polynom result;

	for (List<Monom>::Iterator it = _monoms.begin(); it != _monoms.end(); ++it) {
		result.insert_sorted((*it)* monom);
	}

	return result;
}

Polynom Polynom::operator/(const Monom& monom) const {
	if (monom.Coeff() == 0) {
		throw std::invalid_argument("Division by zero monom");
	}

	Polynom result;

	for (List<Monom>::Iterator it = _monoms.begin(); it != _monoms.end(); ++it) {
		result.insert_sorted((*it) / monom);
	}
	return result;
}
Polynom& Polynom::operator+=(const Monom& monom) noexcept {
	*this = *this + monom;  
	return *this;
}

Polynom& Polynom::operator-=(const Monom& monom) noexcept {
	*this = *this - monom;  
	return *this;
}

Polynom& Polynom::operator*=(const Monom& monom) noexcept {
	*this = *this * monom; 
	return *this;
}

Polynom& Polynom::operator/=(const Monom& monom) {
	*this = *this / monom;  
	return *this;
}

double Polynom::evaluate(const double* values) const noexcept {
	double result = 0;
	for (List<Monom>::Iterator it = _monoms.begin(); it != _monoms.end(); ++it) {
		result += (*it).evaluate(values);
	}
	return result;
}

Polynom::Polynom(const std::string& str) {
	if (str.empty()) return;
	std::string s = str;

	if (s.back() == '+' || s.back() == '-' || s.back() == ' ') {
		throw std::invalid_argument("Incorrect input: polynomial ends with operator or empty");
	}
	if (s.find("++") != std::string::npos ||
		s.find("--") != std::string::npos ||
		s.find("+-") != std::string::npos ||
		s.find("-+") != std::string::npos ||
		s.find("^^") != std::string::npos) {
		throw std::invalid_argument("Incorrect input: empty monom between operators");
	}

	s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
	if (s.empty() || s == "0") return;


	size_t pos = 0;
	size_t len = s.length();

	while (pos < len) {
		double sign = 1.0;
		if (s[pos] == '+') {
			pos++;
		}
		else if (s[pos] == '-') {
			sign = -1.0;
			pos++;
		}

		if (pos >= len) break;

		double coeff = 0.0;
		bool hasCoeff = false;


		if (std::isdigit(s[pos]) || s[pos] == '.') {
			size_t start = pos;
			bool foundPoint = false;
			while (pos < len && (std::isdigit(s[pos]) || s[pos] == '.')) {
				if (s[pos] == '.') {
					if (foundPoint) {
						throw std::invalid_argument("Incorrect input: multiple decimal points");
					}
					foundPoint = true;
				}
				pos++;
				coeff = std::stod(s.substr(start, pos - start));
			}
			hasCoeff = true;
		}

		if (!hasCoeff) {
			coeff = 1.0;
		}
		coeff *= sign;

		int powers[VARS_COUNT] = { 0, 0, 0 };

		while (pos < len && std::isalpha(s[pos])) {
			char var = s[pos];
			pos++;

			int idx = -1;
			if (var == 'x' || var == 'X') idx = 0;
			else if (var == 'y' || var == 'Y') idx = 1;
			else if (var == 'z' || var == 'Z') idx = 2;
			else {
				throw std::invalid_argument("Incorrect input");
			}

			int power = 1;
			if (pos < len && s[pos] == '^') {
				pos++;
				if (std::isdigit(s[pos])) {
					size_t start = pos;
					while (pos < len && std::isdigit(s[pos])) {
						pos++;
					}
					power = std::stoi(s.substr(start, pos - start));
				}
			}

			powers[idx] = power;
		}

		if (coeff != 0.0) {
			Monom monom(coeff, powers);
			insert_sorted(monom); 
		}

	}
}

std::istream& operator>>(std::istream& is, Polynom& polynom) {
	std::string input;
	std::getline(is, input); 

	polynom = Polynom(input); 

	return is;
}

std::ostream& operator<<(std::ostream& os, const Polynom& polynom) {
	const List<Monom>& monoms = polynom.Monoms();

	if (monoms.is_empty()) {
		os << "0";
		return os;
	}




	List<Monom>::Iterator it = monoms.begin();

	
	os << *it;  
	++it;

	while (it != monoms.end()) {
		double coeff = (*it).Coeff();
		if (coeff > 0) {
			os << " + " << *it;
		}
		else {
			os << " - " << -(*it);  
		}
		++it;
	}

	return os;
}


void Polynom::insert_sorted(const Monom& monom) {
	if (monom.Coeff() == 0) return;

	if (_monoms.is_empty()) {
		_monoms.push_back(monom);
		return;
	}

	List<Monom>::Iterator it = _monoms.begin();
	List<Monom>::Iterator prev;
	bool is_first = true;

	while (it != _monoms.end()) {
		bool same_powers = true;
		for (int i = 0; i < VARS_COUNT; i++) {
			if ((*it).Power(i) != monom.Power(i)) {
				same_powers = false;
				break;
			}
		}

		if (same_powers) {
			Monom temp = *it;
			temp += monom;

			if (temp.Coeff() == 0) {
				Node<Monom>* node_to_delete = it.getNode();
				++it;
				_monoms.erase(node_to_delete);
			}
			else {
				*it = temp;
			}
			return;
		}

		bool need_insert = true;
		for (int i = 0; i < VARS_COUNT; i++) {
			if (monom.Power(i) > (*it).Power(i)) {
				need_insert = true;
				break;
			}
			else if (monom.Power(i) < (*it).Power(i)) {
				need_insert = false;
				break;
			}
		}

		if (need_insert) {
			if (is_first) {
				_monoms.push_front(monom);
			}
			else {
				_monoms.insert(prev.getNode(), monom);
			}
			return;
		}

		prev = it;
		++it;
		is_first = false;
	}

	_monoms.push_back(monom);
}
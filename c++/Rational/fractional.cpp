#include "Fractional.hpp"

Fractional::Fractional() {
	_numerator = 0;
	_denominator = 1;
}

Fractional::Fractional(int numerator, int denominator) {
	_numerator = numerator;
	_denominator = denominator;
}

ostream& operator<<(ostream& os, const Fractional& Fractional) {
	os << Fractional._numerator << "/" << Fractional._denominator;
	return os;
}

Fractional operator+(const Fractional& lhs, const Fractional& rhs) {
	int numerator_result = lhs._numerator * rhs._denominator + rhs._numerator * lhs._denominator;
	int denominator_result = lhs._denominator * rhs._denominator;
	
	Fractional result(numerator_result, denominator_result);
	return result;
}

Fractional& Fractional::operator++() {
	_numerator *= 2;
	_denominator *= 2;

	return (*this);
}

Fractional Fractional::operator++(int) {
	Fractional before;
	before = (*this);

	_numerator *= 2;
	_denominator *= 2;

	return before;
}
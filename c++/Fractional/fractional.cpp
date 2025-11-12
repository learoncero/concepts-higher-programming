#include "fractional.hpp"

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

void Fractional::simplify() {
	// Handle edge case where numerator is 0
	if (_numerator == 0) {
		_denominator = 1;
		return;
	}

	// Handle negative denominators by moving the sign to numerator
	if (_denominator < 0) {
		_numerator = -_numerator;
		_denominator = -_denominator;
	}

	// Calculate GCD using Euclidean algorithm
	int a = abs(_numerator);
	int b = abs(_denominator);
	
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	
	int gcd = a;

	// Divide both numerator and denominator by GCD
	_numerator /= gcd;
	_denominator /= gcd;
}
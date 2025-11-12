#include <iostream>
using namespace std;

#ifndef FRACTIONAL__HPP
#define FRACTIONAL__HPP



class Fractional {
	friend ostream& operator<<(ostream&, const Fractional&);
	friend Fractional operator+(const Fractional& lhs, const Fractional& rhs);

private:
	int _numerator;
	int _denominator;

public:
	Fractional(int numerator = 0, int denominator = 1);
	Fractional(double value);

	Fractional& operator~();
	Fractional& operator++();
	Fractional operator++(int);

	void simplify();
};

Fractional operator+(const Fractional& lhs, const Fractional& rhs);

#endif // !FRACTIONAL__HPP

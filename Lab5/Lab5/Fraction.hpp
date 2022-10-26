#ifndef FRACTION_
#define FRACTION_
#pragma once

#include "Value.hpp"

class Fraction : public Value
{
private:
	int numerator;
	int denominator;
public:
	Fraction(int, int);
	~Fraction();

	Fraction& operator+ (Value const&) const override;
	Fraction& operator- (Value const&) const override;
	Fraction& operator/ (Value const&) const override;
	Fraction& operator* (Value const&) const override;

};

#endif // FRACTION_
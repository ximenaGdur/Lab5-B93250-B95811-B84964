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

	const Value& operator+ (const Value&) override;
	const Value& operator- (const Value&) override;
	const Value& operator/ (const Value&) override;
	const Value& operator* (const Value&) override;

};

#endif // FRACTION_
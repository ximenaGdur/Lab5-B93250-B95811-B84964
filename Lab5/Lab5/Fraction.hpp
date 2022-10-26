#ifndef FRACTION_HPP
#define FRACTION_HPP
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

		std::string toString() override;
};

#endif // FRACTION_HPP
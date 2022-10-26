#include "Fraction.hpp"

Fraction::Fraction(int aNumerator, int aDenominator)
	: Value {"Fraction"}
	, numerator{ aNumerator }
	, denominator{ aDenominator }
{
}

Fraction::~Fraction()
{
}

Fraction& Fraction::operator+(Value const& value) const
{
	Fraction result{ 0,0 };
	auto fraction = dynamic_cast<Fraction const*>(&value);
	
	result.numerator = (this->numerator * fraction->denominator) 
		+ (this->denominator * fraction->numerator);
	result.denominator = this->denominator * fraction->denominator;

	return result;
}

Fraction& Fraction::operator-(Value const& value) const
{
	Fraction result{ 0,0 };
	auto fraction = dynamic_cast<Fraction const*>(&value);

	result.numerator = (this->numerator * fraction->denominator) 
		- (this->denominator * fraction->numerator);
	result.denominator = this->denominator;

	return result;
}

Fraction& Fraction::operator*(Value const& value) const
{
	Fraction result{ 0,0 };
	auto fraction = dynamic_cast<Fraction const*>(&value);

	result.numerator = this->numerator * fraction->numerator;
	result.denominator = this->denominator * fraction->denominator;

	return result;
}

Fraction& Fraction::operator/(Value const& value) const
{
	Fraction result{ 0,0 };
	auto fraction = dynamic_cast<Fraction const*>(&value);

	result.numerator = this->numerator * fraction->denominator;
	result.denominator = this->denominator * fraction->numerator;
	return result;
}
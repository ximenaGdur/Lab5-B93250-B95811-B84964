#include "Fraction.hpp"

Fraction::Fraction(int aNumerator, int aDenominator)
	: Value {"Fraction"}
	, numerator{ aNumerator }
	, denominator{ aDenominator }
{
	if (aDenominator == 0) {
		denominator = 1;
	}
}

Fraction::~Fraction()
{
}

Fraction& Fraction::operator+(Value const& value) const
{
	Fraction* result = new Fraction(1,1);
	auto fraction = dynamic_cast<Fraction const*>(&value);
	
	result->numerator = (this->numerator * fraction->denominator) 
		+ (this->denominator * fraction->numerator);
	result->denominator = this->denominator * fraction->denominator;

	return *result;
}

Fraction& Fraction::operator-(Value const& value) const
{
	Fraction* result = new Fraction(1, 1);
	auto fraction = dynamic_cast<Fraction const*>(&value);

	result->numerator = (this->numerator * fraction->denominator) 
		- (this->denominator * fraction->numerator);
	result->denominator = this->denominator * fraction->denominator;

	return *result;
}

Fraction& Fraction::operator*(Value const& value) const
{
	Fraction* result = new Fraction(1, 1);
	auto fraction = dynamic_cast<Fraction const*>(&value);

	result->numerator = this->numerator * fraction->numerator;
	result->denominator = this->denominator * fraction->denominator;

	return *result;
}

Fraction& Fraction::operator/(Value const& value) const
{
	Fraction* result = new Fraction(1, 1);
	auto fraction = dynamic_cast<Fraction const*>(&value);

	result->numerator = this->numerator * fraction->denominator;
	result->denominator = this->denominator * fraction->numerator;

	return *result;
}

std::string Fraction::toString()
{
	std::string setString("");
	setString += std::to_string(numerator) + '/' + std::to_string(denominator);
	return setString;
}

#include "Fraction.hpp"

Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
}

Fraction::~Fraction()
{
}

const Value& Fraction::operator+(const Value& value)
{
	const Fraction fraction = static_cast<const Fraction> (value);

	//Fraction& catRef2 = dynamic_cast<Fraction&>((Value)value);  // Works

	//const_cast
	
	Fraction& res2 = const_cast<const Fraction&>(value);

	Fraction result;
	result.numerator = (this->numerator * fraction.denominator) 
		+ (this->denominator * fraction.numerator);
	result.denominator = this->denominator * fraction.denominator;
	return result;
}

const Fraction& Fraction::operator-(const Fraction& fraction)
{
	Fraction result;
	result.numerator = (this->numerator * fraction.denominator) 
		- (this->denominator * fraction.numerator);
	result.denominator = this->denominator;
	return result;
}

const Fraction& Fraction::operator*(const Fraction& fraction)
{
	Fraction result;
	result.numerator = this->numerator * fraction.numerator;
	result.denominator = this->denominator * fraction.denominator;
	return result;
}

const Fraction& Fraction::operator/(const Fraction& fraction)
{
	Fraction result;
	result.numerator = this->numerator * fraction.denominator;
	result.denominator = this->denominator * fraction.numerator;
	return result;
}
#include "Double.hpp"

Double::Double(double value)
	: Value ("Value")
	, myValue { value }
{
}

Double::~Double()
{
}

Double& Double::operator+(Value const& value) const {
	Double result{0};
	auto aDouble = dynamic_cast<Double const*>(&value);

	result.myValue = this->myValue + aDouble->myValue;
	
	return result;
}

Double& Double::operator-(Value const& value) const {
	Double result{0};
	auto aDouble = dynamic_cast<Double const*>(&value);

	result.myValue = this->myValue - aDouble->myValue;

	return result;
}

Double& Double::operator*(Value const& value) const {
	Double result{0};
	auto aDouble = dynamic_cast<Double const*>(&value);

	result.myValue = this->myValue * aDouble->myValue;

	return result;
}

Double& Double::operator/(Value const& value) const {
	Double result{0};
	auto aDouble = dynamic_cast<Double const*>(&value);

	result.myValue = this->myValue / aDouble->myValue;

	return result;
}

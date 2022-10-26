#include "Double.hpp"

Double::Double(std:string type)
	: Value("Double")
	, myValue{ value } { }

const Double& Double::operator+(const Double& value) {
	Double result;
	result.myValue = this->myValue + value.myValue;
	return result;
}

const Double& Double::operator-(const Double& value) {
	Double result;
	result.myValue = this->myValue - value.myValue;
	return result;
}

const Double& Double::operator*(const Double& value){
	Double result;
	result.myValue = this->myValue * value.myValue;
	return result;
}

const Double& Double::operator/(const Double& value) {
	Double result;
	result.myValue = this->myValue / value.myValue;
	return result;
}

#ifndef VALUE_
#define VALUE_
#pragma once

#include <string>

class Value
{
	private:
		std::string myType;
	public:
		Value(std::string);
		~Value();

		virtual const Value& operator+(const Value&) = 0;
		virtual const Value& operator-(const Value&) = 0;
		virtual const Value& operator/(const Value&) = 0;
		virtual const Value& operator*(const Value&) = 0;

};

#endif //VALUE_

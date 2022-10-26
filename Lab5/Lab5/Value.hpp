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

		virtual Value& operator+(Value const&) const = 0;
		virtual Value& operator-(Value const&) const = 0;
		virtual Value& operator/(Value const&) const = 0;
		virtual Value& operator*(Value const&) const = 0;
};

#endif //VALUE_

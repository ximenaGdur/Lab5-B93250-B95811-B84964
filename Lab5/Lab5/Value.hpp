#ifndef VALUE_HPP
#define VALUE_HPP
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

		virtual std::string toString() = 0;
};

#endif //VALUE_HPP

#ifndef DOUBLE_HPP
#define DOUBLE_HPP
#pragma once

#include "Value.hpp"

class Double : public Value
{
  private:
	  double myValue;

  public:
	Double(double value);
	~Double();

	Double& operator+(Value const&) const override;
	Double& operator-(Value const&) const override;
	Double& operator*(Value const&) const override;
	Double& operator/(Value const&) const override;

	std::string toString() override;
};

#endif // DOUBLE_HPP
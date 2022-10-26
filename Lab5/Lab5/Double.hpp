#ifndef DOUBLE_
#define DOUBLE_
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
};

#endif // DOUBLE_
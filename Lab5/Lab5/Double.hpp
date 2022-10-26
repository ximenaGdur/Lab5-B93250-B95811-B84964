#ifndef Double_
#define Double_
#pragma once

#include "Value.hpp"

class Double : public Value
{
  private:
	  double myValue;

  public:
	Double(double value);
	~Double();
	const Double& operator+(const Double&) override;
	const Double& operator-(const Double&) override;
	const Double& operator*(const Double&) override;
	const Double& operator/(const Double&) override;
};

#endif // Double_
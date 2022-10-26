#ifndef EVALUATOR_
#define EVALUATOR_
#pragma once

#include <map>
#include <string>
#include <stack>

#include "Value.hpp"

class Evaluator
{
 public:
	std::string expression;
	//std::stack<Value*> myStack;
	//std::map <char, Value*> map;

  private:
	Evaluator();
	~Evaluator();

	// Value& posfixAlgorithm();
	void posfixAlgorithm();


  public:
	Double* evaluate(std::string);
};

#endif //EVALUATOR_

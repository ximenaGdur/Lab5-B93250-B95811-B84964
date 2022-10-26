#ifndef EVALUATOR_
#define EVALUATOR_
#pragma once

#include <map>
#include <string>
#include <stack>

#include "Value.hpp"
#include "Double.hpp"

class Evaluator
{
  private:
	std::string expression;
	std::stack<Value*> myStack;
	std::map<char, Value*> map;

  public:
	Evaluator();
	~Evaluator();
	Value* evaluate(std::string, std::map<char, Value*>);

  private:
	Value* posfixAlgorithm();
};

#endif //EVALUATOR_

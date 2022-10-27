#ifndef EVALUATOR_
#define EVALUATOR_
#pragma once

#include <map>
#include <string>
#include <stack>
#include <vector>

#include "Value.hpp"
#include "Double.hpp"

class Evaluator
{
  private:
	std::string expression;
	std::stack<Value*> myStack;
	std::map<char, Value*> map;
	std::vector<Value*> referencesVector;

  public:
	Evaluator();
	~Evaluator();
	Value* evaluate(std::string, std::map<char, Value*>);

  private:
	Value* posfixAlgorithm();
	void resetDataEstructures();
};

#endif //EVALUATOR_

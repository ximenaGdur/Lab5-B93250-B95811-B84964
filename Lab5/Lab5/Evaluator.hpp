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
	std::stack<Value&> myStack;
private:
	Evaluator();
	~Evaluator();
	void posfixAlgorithm();
	Value& executeExpression();
public:
	Value& evaluate(std::string, std::map<char, Value&>);
};

#endif //EVALUATOR_


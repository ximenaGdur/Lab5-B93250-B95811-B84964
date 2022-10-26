#ifndef CONTROLLER_
#define CONTROLLER_
#pragma once

#include <iostream>

#include "Double.hpp"
#include "Evaluator.hpp"
#include "Fraction.hpp"
#include "Set.hpp"
#include "Value.hpp"

class Controller
{
	private:
		std::string alphabet;
		std::map<char, Value*> doubleMap;
		std::map<char, Value*> fractionMap;
		std::map<char, Value*> setMap;

	private:
		void executeEvaluatorDouble();
		void executeEvaluatorFraction();
		void executeEvaluatorSet();

	public:
		Controller();
		~Controller();
		void run();
};

#endif // CONTROLLER_
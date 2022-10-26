#include <set>

#include "Controller.hpp"

Controller::Controller()
	: alphabet{ "abcdefghijklmnopqrstuvwxyz" } {
	std::cout << "START:" << std::endl;
}

Controller::~Controller()
{
	std::cout << std::endl;
	for (auto& mapKey : doubleMap) {
		std::cout << "Deleting double: [" << mapKey.first << "]: " << mapKey.second << ": " << mapKey.second->toString() << std::endl;
		delete mapKey.second;
	}
	std::cout << std::endl;
	for (auto& mapKey : fractionMap) {
		std::cout << "Deleting fraction: [" << mapKey.first << "]: " << mapKey.second << ": " << mapKey.second->toString() << std::endl;
		delete mapKey.second;
	}
	std::cout << std::endl;
	for (auto& mapKey : setMap) {
		std::cout << "Deleting set: [" << mapKey.first << "]: " << mapKey.second << ": " << mapKey.second->toString() << std::endl;
		delete mapKey.second;
	}
}

void Controller::executeEvaluatorDouble()
{
	double aDouble = 1.0;

	for (char letter : alphabet) {
		Double* myDoubleValue =  new Double(aDouble);
		std::cout << "Creating: [" << letter << "]: " << myDoubleValue->toString() << std::endl;
		doubleMap[letter] = myDoubleValue;
		aDouble += 0.5;
	}
}

void Controller::executeEvaluatorFraction()
{
	int numerator = 1;
	int denominator = 2;

	for (char letter : alphabet) {
		Fraction* myFraction  = new Fraction(numerator, denominator);
		std::cout << "Creating: [" << letter << "]: " << myFraction->toString() << std::endl;
		fractionMap[letter] = myFraction;
		numerator++;
		denominator++;
	}
}

void Controller::executeEvaluatorSet()
{
	int startingNumber = 1;

	for (char letter : alphabet) {
		std::set <int> realSet({ startingNumber, startingNumber + 1 });
		Set* ourSet  = new Set(realSet);
		std::cout << "Creating: [" << letter << "]: " << ourSet->toString() << std::endl;
		setMap[letter] = ourSet;
		startingNumber++;
	}
}

void Controller::run()
{
	Evaluator evaluator1;
	executeEvaluatorDouble();
	std::cout << std::endl;
	Value* value = evaluator1.evaluate("ab+", doubleMap);
	//std::cout << std::endl << "RESULT: [" << value->toString() << std::endl;

	Evaluator evaluator2;
	executeEvaluatorFraction();
	std::cout << std::endl;
	//evaluator2.evaluate("ab*", fractionMap);

	Evaluator evaluator3;
	executeEvaluatorSet();
	std::cout << std::endl;
	//evaluator3.evaluate("ab/", setMap);
}

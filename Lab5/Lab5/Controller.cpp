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
		delete mapKey.second;
	}
	std::cout << std::endl;
	for (auto& mapKey : fractionMap) {
		delete mapKey.second;
	}
	std::cout << std::endl;
	for (auto& mapKey : setMap) {
		delete mapKey.second;
	}
}

void Controller::createDoubles()
{
	double aDouble = 1.0;

	for (char letter : alphabet) {
		Double* myDoubleValue =  new Double(aDouble);
		doubleMap[letter] = myDoubleValue;
		aDouble += 0.5;
	}
}

void Controller::createFractions()
{
	int numerator = 1;
	int denominator = 2;

	for (char letter : alphabet) {
		Fraction* myFraction  = new Fraction(numerator, denominator);
		fractionMap[letter] = myFraction;
		numerator++;
		denominator++;
	}
}

void Controller::createSets()
{
	int startingNumber = 1;

	for (char letter : alphabet) {
		std::set <int> realSet({ startingNumber, startingNumber + 1 });
		Set* ourSet  = new Set(realSet);
		setMap[letter] = ourSet;
		startingNumber++;
	}
}

void Controller::run()
{
	Value* value = nullptr;
	std::string expression = "ab+cd*e/-";

	Evaluator doubleEvaluator;
	createDoubles();
	std::cout << std::endl;
	value = doubleEvaluator.evaluate(expression, doubleMap);
	std::cout << std::endl << "Resultado de " << expression << " como Double: " << value->toString() << std::endl;
	
	Evaluator fractionEvaluator;
	createFractions();
	std::cout << std::endl;
	value = fractionEvaluator.evaluate(expression, fractionMap);
	std::cout << std::endl << "Resultado de " << expression << " como Fraction: " << value->toString() << std::endl;
	
	Evaluator setEvaluator;
	createSets();
	std::cout << std::endl;
	value = setEvaluator.evaluate(expression, setMap);
	std::cout << std::endl << "Resultado de " << expression << " como Set: " << value->toString() << std::endl;
}

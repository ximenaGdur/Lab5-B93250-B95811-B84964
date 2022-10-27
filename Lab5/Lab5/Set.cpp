#include <algorithm>
#include <iterator>

#include "Set.hpp"

Set::Set(std::set<int> aSet)
	: Value("Set")
	, mySet{aSet}
{}

Set::Set()
	: Value("Set")
{}

Set::~Set()
{
}
 
Set& Set::operator+(Value const& anotherSet) const
{
	// Union
	Set* result = new Set();
	auto set = dynamic_cast<Set const*>(&anotherSet);

	result->mySet = this->mySet;
	result->mySet.insert(set->mySet.begin(), set->mySet.end());

	return *result;
}

Set& Set::operator-(Value const& anotherSet) const
{
	// Diferencia
	Set* result = new Set();
	auto set = dynamic_cast<Set const*>(&anotherSet);

	std::set_difference(
		this->mySet.begin(), this->mySet.end(),
		set->mySet.begin(), set->mySet.end(),
		std::inserter(result->mySet, result->mySet.begin())
	);

	return *result;
}

Set& Set::operator/(Value const& anotherSet) const
{
	// Diferencia Simetrica
	Set* result = new Set();
	auto set = dynamic_cast<Set const*>(&anotherSet);

	std::set_symmetric_difference(
		this->mySet.begin(), this->mySet.end(),
		set->mySet.begin(), set->mySet.end(),
		std::inserter(result->mySet, result->mySet.begin())
	);

	return *result;
}

Set& Set::operator*(Value const& anotherSet) const
{
	// Interseccion
	Set* result = new Set();
	auto set = dynamic_cast<Set const*>(&anotherSet);

	std::set_intersection(
		this->mySet.begin(), this->mySet.end(),
		set->mySet.begin(), set->mySet.end(),
		std::inserter(result->mySet, result->mySet.begin())
	);

	return *result;
}

bool Set::isEmpty()
{
	bool result = false;

	if (this->mySet.empty()) {
		result = true;
	}

	return result;
}

std::string Set::toString()
{
	std::string setString("{");
	for (int number : mySet) {
		setString += std::to_string(number) + ',';
	}
	setString.pop_back();
	setString += '}';
	return setString;
}

#include <algorithm>
#include <iterator>

#include "Set.hpp"

Set::Set(std::set<int> aSet)
	: Value("Set")
	, mySet{aSet}
{}

Set::~Set()
{
}

const Set& Set::operator+(const Set& set)
{
	// Union
	Set result;
	result.mySet = this->mySet;
	result.mySet.insert(set.mySet.begin(), set.mySet.end());
	return result;
}

const Set& Set::operator-(const Set& set)
{
	// Diferencia
	Set result;

	std::set_difference(
		this->mySet.begin(), this->mySet.end(),
		set.mySet.begin(), set.mySet.end(),
		std::inserter(result.mySet, result.mySet.begin())
	);

	return result;
}

const Set& Set::operator/(const Set& set)
{
	// Diferencia Simetrica

	Set result;

	std::set_symmetric_difference(
		this->mySet.begin(), this->mySet.end(),
		set.mySet.begin(), set.mySet.end(),
		std::back_inserter(result.mySet)
	);

	return result;
}

const Set& Set::operator*(const Set& set)
{
	// Interseccion

	Set result;

	std::set_intersection(
		this->mySet.begin(), this->mySet.end(),
		set.mySet.begin(), set.mySet.end(),
		std::inserter(result.mySet, result.mySet.begin())
	);

	return result;
}

bool Set::isEmpty()
{
	bool result = false;
	if (this->mySet.empty()) {
		result = true;
	}
	return result;
}


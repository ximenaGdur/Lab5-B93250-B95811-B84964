#ifndef SET_
#define SET_
#pragma once

#include "Value.hpp"

#include <set>

class Set : public Value {
private:
    std::set<int> mySet;
public:
    Set(std::set<int>);
    Set();
    ~Set();

    Set& operator+ (Value const&) const override;
    Set& operator- (Value const&) const override;
    Set& operator/ (Value const&) const override;
    Set& operator* (Value const&) const override;

    bool isEmpty();
};

#endif // SET_

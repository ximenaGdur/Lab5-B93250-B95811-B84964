#ifndef SET_HPP
#define SET_HPP
#pragma once

#include "Value.hpp"

#include <iostream>
#include <set>

class Set : public Value {
    private:
        std::set<int> mySet;
    public:
        Set();
        Set(std::set<int>);
        ~Set();

        Set& operator+ (Value const&) const override;
        Set& operator- (Value const&) const override;
        Set& operator/ (Value const&) const override;
        Set& operator* (Value const&) const override;

        std::string toString() override;

        bool isEmpty();
};

#endif // SET_HPP

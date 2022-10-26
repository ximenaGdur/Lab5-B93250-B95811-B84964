#ifndef SET_
#define SET_
#pragma once

#include "Value.hpp"

#include <set>

class Set :
    public Value
{
    private:
        std::set<int> mySet;
    public:
        Set(std::set<int>);
        ~Set();
        const Set& operator+ (const Set&) override;
        const Set& operator- (const Set&) override;
        const Set& operator/ (const Set&) override;
        const Set& operator* (const Set&) override;
        bool isEmpty();
}
#endif // SET_
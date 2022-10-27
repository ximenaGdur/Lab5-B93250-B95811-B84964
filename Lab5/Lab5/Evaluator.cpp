#include "Evaluator.hpp"
#include "Double.hpp"
#include <iostream>

Evaluator::Evaluator()
    : expression{""}
{}

Evaluator::~Evaluator()
{
}

// Adaptado de: https://www.codespeedy.com/calculate-a-postfix-expression-using-stack-in-cpp/
Value* Evaluator::posfixAlgorithm()
{
    size_t expressionLength = expression.length();
    int indice = 0;
    for (size_t expressionIndex = 0; expressionIndex < expressionLength; expressionIndex++)
    {
        char currentCharacter = expression[expressionIndex];
        // if the character is an operand we push it in the stack
        if (currentCharacter != '+' && currentCharacter != '-' &&
            currentCharacter != '/' && currentCharacter != '*')
        {
            myStack.push(map[currentCharacter]);
        }
        else
        {
            // we pop the top two elements from the stack and save them in two integers
            Value* a = myStack.top();
            myStack.pop();
            Value* b = myStack.top();
            myStack.pop();

            switch (currentCharacter)
            {
                case '+':
                    referencesVector.push_back(&(*b + *a));
                    myStack.push(referencesVector[indice]);
                    indice++;
                    break;
                case '-':
                    referencesVector.push_back(&(*b - *a));
                    myStack.push(referencesVector[indice]);
                    indice++;
                    break;
                case '*':
                    referencesVector.push_back(&(*b * *a));
                    myStack.push(referencesVector[indice]);
                    indice++;
                    break;
                case '/':
                    referencesVector.push_back(&(*b / *a));
                    myStack.push(referencesVector[indice]);
                    indice++;
                    break;
            }
        }
    }

    Value* result = myStack.top();
    myStack.pop();

    return result;
}

void Evaluator::resetDataEstructures()
{
    expression = "";
    map.clear();

    int limit = referencesVector.size();
    for (int index = 0; index < limit; index++) {
        delete referencesVector[index];
    }
    referencesVector.clear();
}

Value* Evaluator::evaluate(std::string anExpression, std::map<char, Value*> aMap)
{
    expression = anExpression;
    map = aMap;
    Value* result = posfixAlgorithm();

    return result;
}

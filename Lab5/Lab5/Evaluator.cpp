#include "Evaluator.hpp"
#include "Double.hpp"
#include <iostream>

Evaluator::Evaluator()
    : expression{""}
{}

Evaluator::~Evaluator()
{
}

// Sacado de: https://www.codespeedy.com/calculate-a-postfix-expression-using-stack-in-cpp/
Value* Evaluator::posfixAlgorithm()
{
    size_t expressionLength = expression.length();
    for (size_t expressionIndex = 0; expressionIndex < expressionLength; expressionIndex++)
    {
        char currentCharacter = expression[expressionIndex];
        // if the character is an operand we push it in the stack
        if (currentCharacter != '+' && currentCharacter != '-' &&
            currentCharacter != '/' && currentCharacter != '*')
        {
            myStack.push(map[expression[expressionIndex]]);
        }
        else
        {
            // we pop the top two elements from the stack and save them in two integers
            Value* a = myStack.top();
            myStack.pop();
            Value* b = myStack.top();
            myStack.pop();

            switch (expression[expressionIndex])
            {
            case '+':
                myStack.push(&( *b + *a));
                break;
            case '-':
                myStack.push(&( *b - *a));
                break;
            case '*':
                myStack.push(&(*b * *a));
                break;
            case '/':
                myStack.push(&(*b / *a));
                break;
            }
        }
    }

    Value* result = (myStack.top());
    std::cout << std::endl << std::endl << "RESULT: [" << result << "]: " << result->toString() << std::endl << std::endl;
    // TODO: review this

    //returning the calculated result
    return result;
}

Value* Evaluator::evaluate(std::string anExpression, std::map<char, Value*> aMap)
{
    expression = anExpression;
    map = aMap;

    Value* result = posfixAlgorithm();

    return result;
}

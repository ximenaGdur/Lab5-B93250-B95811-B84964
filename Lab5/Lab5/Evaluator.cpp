#include "Evaluator.hpp"
#include "Double.hpp"

Evaluator::Evaluator()
    : expression{""}
{}

Evaluator::~Evaluator()
{
}

// Sacado de: https://www.codespeedy.com/calculate-a-postfix-expression-using-stack-in-cpp/
void Evaluator::posfixAlgorithm()
{
    //int expressionLength = expression.length();
    //for (int expressionIndex = 0; expressionIndex < expressionLength; expressionIndex++)
    //{
    //    char currentCharacter = expression[expressionIndex];
    //    // if the character is an operand we push it in the stack
    //    if (currentCharacter != '+' && currentCharacter != '-' &&
    //        currentCharacter != '/' && currentCharacter != '*')
    //    {
    //        myStack.push(map[expression[expressionIndex]]);
    //    }
    //    else
    //    {
    //        // we pop the top two elements from the stack and save them in two integers
    //        Value& a = myStack.top();
    //        myStack.pop();
    //        Value& b = myStack.top();
    //        myStack.pop();

    //        switch (expression[expressionIndex])
    //        {
    //        case '+':
    //            myStack.push(b + a);
    //            break;
    //        case '-':
    //            myStack.push(b - a);
    //            break;
    //        case '*':
    //            myStack.push(b * a);
    //            break;
    //        case '/':
    //            myStack.push(b / a);
    //            break;
    //        }
    //    }
    //}
    //Value& result = myStack.top();
    ////returning the calculated result
    //return result;
}

Double* Evaluator::evaluate(std::string anExpression)
{
    //expression = anExpression;
    //map = aMap;
    Double* d = new Double( 0.2 );
    return d;
}

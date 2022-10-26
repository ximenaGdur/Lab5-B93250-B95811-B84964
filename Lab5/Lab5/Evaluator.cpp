#include "Evaluator.hpp"

Evaluator::Evaluator():
    expression{""}
{}

Evaluator::~Evaluator()
{
}

//Sacado de: https://www.codespeedy.com/calculate-a-postfix-expression-using-stack-in-cpp/
void Evaluator::posfixAlgorithm()
{
    int len = expression.length();
    // loop to iterate through the expression
    for (int i = 0; i < len; i++)
    {
        // if the character is an operand we push it in the stack
        // we have considered single digits only here
        if (map[expression[i]] != '+' && map[expression[i]] != '-' && map[expression[i]] != '/' && map[expression[i]] != '*')
        {
            myStack.push(map[expression[i]] - '0');
        }
        // if the character is an operator we enter else block
        else
        {
            // we pop the top two elements from the stack and save them in two integers
            Value& a = myStack.top();
            myStack.pop();
            Value& b = myStack.top();
            myStack.pop();
            //performing the operation on the operands
            switch (expression[i])
            {
            case '+': // addition
                myStack.push(b + a);
                break;
            case '-': // subtraction
                myStack.push(b - a);
                break;
            case '*': // multiplication
                myStack.push(b * a);
                break;
            case '/': // division
                myStack.push(b / a);
                break;
            case '^': // exponent
                myStack.push(pow(b, a));
                break;
            }
        }
    }
    myStack.top()
    //returning the calculated result
    return ;
}

Value& Evaluator::executeExpression()
{
    // // O: insert return statement here
}

Value& Evaluator::evaluate(std::string, std::map<char, Value&>)
{
    Value value;
    return value;
}

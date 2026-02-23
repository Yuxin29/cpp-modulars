#pragma once

#include <string>
#include <stack>

// nverted Polish mathematical expression: Reverse Polish Notation (RPN),
// - Operators come after their operands
// - The expression is evaluated from left to right
// - A stack is usually used to process it
// !!!! Why RPN is useful
//      - No parentheses are needed
//      - No operator precedence rules are required
//      - Very easy for computers to evaluate
class PRN
{
private:
    std::stack<int> _data;
    std::string     _input;

    void        isValidInput(const std::string &input);
    void        loadInput(const std::string &input);

public:
    PRN(const std::string &input);
    ~ PRN();

    void        calculate();
};


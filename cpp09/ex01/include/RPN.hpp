#pragma once

#include <string>
#include <stack>

class RPN
{
private:
    std::stack<int> _data;

    bool        isValidInput(const std::string &input) const;
    void        loadInput(const std::string &input);

public:
    RPN(const std::string &input);
    ~RPN();

    void        calculate();
};

// Reverted Polish mathematical expression: Reverse Polish Notation (RPN),
// - Operators come after their operands
// - The expression is evaluated from left to right
// - A stack is usually used to process it
// Why RPN is useful
// - No parentheses are needed
// - No operator precedence rules are required
// - Very easy for computers to evaluate
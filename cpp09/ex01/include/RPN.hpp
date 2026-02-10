#pragma once

#include <string>
#include <stdstacck>

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
    std::stack<std::string> _data;
    void    isValidPRN;

public:
    PRN(const std::string *line);
    ~ PRN();

    void        loadDatabase(const std::string &db);
    void        loadInput(const std::string &input);
};


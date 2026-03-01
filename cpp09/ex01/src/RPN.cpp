#include "RPN.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cctype>

//The numbers used in this operation and passed as arguments will always be less than 10.
// Your program must be able to handle operations with these tokens: "+ - / *".
// 3 4 +
bool    RPN::isValidInput(const std::string &input) const{
    if (input.empty())
        return false;
    std::stringstream   ss(input);
    std::string         token;
    int                 state = 0;
    while (ss >> token){
        // nbrs 
        if (token.length() == 1 && std::isdigit(token[0]))
            state++;
        // Operators
        else if ((token == "+") || (token == "-") || (token == "*") || (token == "/")){
            if (state < 2)
                return false;
            state--;
        }
        // Invalid token
        else
            return false;
    }
    return (state == 1);
}

void    RPN::loadInput(const std::string &input){
    std::stringstream   ss(input);
    std::string         token;

     while (ss >> token){
        if (token.length() == 1 && std::isdigit(token[0]))
            _data.push(token[0] - '0');   
        else{
            int b = _data.top(); 
            _data.pop();
            int a = _data.top(); 
            _data.pop();
            if (token == "+") 
                _data.push(a + b);
            else if (token == "-") 
                _data.push(a - b);
            else if (token == "*") 
                _data.push(a * b);
            else if (token == "/"){
                if (b == 0)
                    throw std::runtime_error("Error");
                _data.push(a / b);
            }
        }
    }
}

RPN::RPN(const std::string &input){
    if (!isValidInput(input))
        throw std::runtime_error("Invalid input.");
    loadInput(input);
}

RPN::~ RPN(){
}

void    RPN::calculate(){
    std::cout << _data.top() << std::endl;
}
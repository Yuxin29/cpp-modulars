#include "RPN.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cctype>

/**
* @brief 	Load and calculate the RPN expression from an input string
* @param 	input the input string containing the RPN expression
* @return 	void, throw runtime_error if the input is invalid

* @rules    The numbers used in this operation and passed as arguments will always be less than 10.
            Your program must be able to handle operations with these tokens: "+ - / *".
* @example  3 4 + => 7
* @functions used  
            top  get the top
            pop  remove the top
*/
void    RPN::loadInput(const std::string &input){
    if (input.empty())
        throw std::runtime_error("Error");
    std::stringstream   ss(input);
    std::string         token;
    while (ss >> token){
        if (token.length() == 1 && std::isdigit(token[0]))
            _data.push(token[0] - '0');
        else if ((token == "+") || (token == "-") || (token == "*") || (token == "/")){
            if (_data.size() < 2)
                throw std::runtime_error("Error");
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
        else
            throw std::runtime_error("Error");
    }
    if (_data.size() != 1)
        throw std::runtime_error("Error");
}


/**
* @brief 	Calculate the result of the RPN expression and output it
* @param 	void
* @return 	void, throw runtime_error if the calculation cannot be performed
*/
void    RPN::calculate(){
    std::cout << _data.top() << std::endl;
}
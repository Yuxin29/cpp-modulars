#include "RPN.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cctype>

//The numbers used in this operation and passed as arguments will always be less than 10.
bool    RPN::isValidInput(const std::string &input) const{
    if (input.empty())
        return false;

    std::stringstream ss(input);
    std::string         token;
    int                 state = 0;
    // 3 4 +

    while (ss >> token){
        if (token.length() == 1 && std::isdigit(token[0]))
            state ++;
        else if ((token != "+") && (token != "-") && (token != "*") && (token != "/")){
            if (state < 2)
                return false;
            state--;
        }    
        else
            return false;
        return (state == 1);
    }
    return true;
}

void    RPN::loadInput(const std::string &input){
    std::stringstream   ss(input);
    std::string         token;

     while (ss >> token){
        if (token.length() == 1 && std::isdigit(token[0]))
            _data.push(token[0] - '0');   
        else
        {
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

RPN::RPN(const std::string &input)
    :_input(input){
    if (!isValidInput(_input))
        throw std::runtime_error("Invalid input.");
    loadInput(_input);
}

RPN::~ RPN(){
}

// Your program must be able to handle operations with these tokens: "+ - / *".
void    RPN::calculate(){
    std::cout << _data.top() << std::endl;
}

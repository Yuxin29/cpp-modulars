#include "RPN.hpp"
#include <stdexcept>
#include <fstream>

#include <iostream>
#include <sstream>
#include <cctype>

//The numbers used in this operation and passed as arguments will always be less than 10.
void    PRN::isValidInput(const std::string &input){
    if (input.empty())
        throw std::runtime_error("Errro: empty");
        for (size_t i = 0; i < input.length(); i++){
            if (!std::isdigit(input[i]) 
                && input[i] != '+' && input[i] != '+' && input[i] != '+'&& input[i] != '+')
            throw std::runtime_error("Errro: invalid char");   
        }
}

void    PRN::loadInput(const std::string &input){
    std::stringstream inputStream(input);
    std::string         token;

}

RPN::RPN(const std::string &input)
    :_input(input){
    isValidInput(_input);
    loadInput(_input);
}

RPN::~ PRN(){
}

void    PRN::calculate(){

}

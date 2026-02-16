#include "ScalarConverter.hpp"
#include <exception>
#include <iostream>
#include <cmath>    //std::ifinf....
#include <limits>   //std::numeric_limits

static void printChar(int i){
    if (i < 0 || i > 127){
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(i);
    if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
}

static void printInt(double d, int i){
    if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << i << "\n";
}

static void printFloat(float f, int i){
    if (std::isnan(f)){
        std::cout << "float: nanf\n";
        return;
    }
    if (std::isinf(f)){
        if (f < 0)
            std::cout << "float: " << "-inff\n";
        else
            std::cout << "float: " << "+inff\n";
        return;
    }
    std::cout << "float: " << f;
    if (f == i)
        std::cout << ".0";
    std::cout << "f\n";
}

static void printDouble(double d){
    if (std::isnan(d)){
        std::cout << "double: nan\n";
        return;}
    if (std::isinf(d)){
        if (d < 0)
            std::cout << "double: " << "-inf\n";
        else
            std::cout << "double: " << "+inf\n";
        return;
    }
    std::cout << "double: " << d;
    if (d == std::floor(d))  // rounded down double
        std::cout << ".0";
    std::cout << "\n";
}

// private internal helper to first tell what type it is.
LiteralType ScalarConverter::getLiteralType(const std::string &literal)
{
    size_t l = literal.length();

    //TYPE_PSEUDO_FLOAT
    if (literal == "nanf" || literal == "inff" || literal == "+inff" || literal == "-inff")
        return TYPE_PSEUDO_FLOAT;
    //TYPE_PSEUDO_DOUBLE
    if (literal == "nan" || literal == "inf" || literal == "+inf" || literal == "-inf")
        return TYPE_PSEUDO_DOUBLE;
    // TYPE_CHAR: eg 'a'
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return TYPE_CHAR;
    //TYPE_INT
    bool isInt = true;
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    for (; i < l; i++){
        if (!isdigit(literal[i])){
            isInt = false;
            break;
        }
    }
    if (isInt)
        return TYPE_INT;
    // TYPE_FLOAT
    bool isFloat = (literal.back() == 'f');
    if (isFloat){
        std::string num = literal.substr(0, l - 1);
        size_t f = 0;
        if (num[f] && (num[f] == '+' || num[f] == '-'))
            f++;
        if (!num[f])
            isFloat = false;
        bool hasPoint = false;
        bool hasNbrBefore = false;
        bool hasNbrAfter = false;
        for (; f < num.length(); f++){
            if (isdigit(num[f])){
                if (!hasPoint)
                    hasNbrBefore = true;
                else
                    hasNbrAfter = true;
            }
            else if (num[f] == '.'){
                if (hasPoint){
                    isFloat = false;
                    break;
                }
                hasPoint = true;
            }
            else {
                isFloat = false;
                break;
            }
        }
        if (!hasPoint || !hasNbrAfter || !hasNbrBefore)
            isFloat = false;
    }
    if (isFloat)
        return TYPE_FLOAT;
    //TYPE_DOUBLE
    bool isDouble = true;
    size_t d = 0;
    if (literal[d] && (literal[d] == '+' || literal[d] == '-'))
        d++;
    if (!literal[d])
        isDouble = false;
    bool hasPoint = false;
    bool hasNbrBefore = false;
    bool hasNbrAfter = false;
    for (; d < literal.length(); d++){
        if (isdigit(literal[d])){
            if (!hasPoint)
                hasNbrBefore = true;
            else
                hasNbrAfter = true;
        }
        else if (literal[d] == '.'){
            if (hasPoint){
                isDouble = false;
                break;
            }
            hasPoint = true;
        }
        else {
            isDouble = false;
            break;
        }
    }
    if (!hasPoint || !hasNbrAfter || !hasNbrBefore)
            isDouble = false;
    if (isDouble)
        return TYPE_DOUBLE;
    // TYPE_INVALID
    return TYPE_INVALID;
}

void ScalarConverter::convert(const std::string &literal){
    LiteralType type = getLiteralType(literal);
    
    if (type == TYPE_PSEUDO_FLOAT){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        return;
    }
    else if (type == TYPE_PSEUDO_DOUBLE){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }
    else if (type == TYPE_INVALID){
        std::cout << "Invalid input." << std::endl;
        return;    
    }
    double d = 0.0;
    bool conversion_safe = true;
    try {
        switch(type) {
        case TYPE_CHAR:
            d = static_cast<double>(literal[1]);            
            break;
        case TYPE_INT:
            d = static_cast<double>(std::stoi(literal));    
            break;
        case TYPE_FLOAT:
            d = static_cast<double>(std::stof(literal));    
            break;
        case TYPE_DOUBLE:
            d = std::stod(literal);                         
            break;
        default: // pseudo literals and invalid                                         
            conversion_safe = false;
            break;                      
        }
    }
    catch (const std::exception &){
        conversion_safe = false;
    }

    if (!conversion_safe)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);
    printChar(i);
    printInt(d, i);
    printFloat(f, i);
    printDouble(d);
    return ;
}
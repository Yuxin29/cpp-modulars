
#include "ScalarConverter.hpp"

    // TYPE_CHAR,                      // 0
    // TYPE_INT,                       // 1
    // TYPE_FLOAT,                     // 2    32 bytes, end with f, eg 3.14f
    // TYPE_DOUBLE,                    // 3    64 bits, by default,  eg 3.14
    // TYPE_PSEUDO_FLOAT,              // 4    fake float            eg nanf, +inff, -inff
    // TYPE_PSEUDO_DOUBLE,             // 5    fake double           eg nan, +inf, -inf
    // TYPE_INVALID                    // 6    all uncategrized type
LiteralType ScalarConverter::getLiteralType(const std::string &literal)
{
    size_t l = literal.length();

    //TYPE_PSEUDO_FLOAT
    if (literal.length() == 4 && (strcmp(literal.c_str(), "nanf") == 0 || strcmp(literal.c_str(), "inff") == 0))
        return TYPE_PSEUDO_FLOAT;
    if (literal.length() == 5 && (strcmp(literal.c_str(), "+inff") == 0 || strcmp(literal.c_str(), "-inff") == 0) == 0)
        return TYPE_PSEUDO_FLOAT;

    //TYPE_PSEUDO_DOUBLE
    if (literal.length() == 4 && (strcmp(literal.c_str(), "nan") == 0 || strcmp(literal.c_str(), "inf") == 0))
        return TYPE_PSEUDO_DOUBLE;
    if (literal.length() == 5 && (strcmp(literal.c_str(), "+inf") == 0 || strcmp(literal.c_str(), "-inf") == 0) == 0)
        return TYPE_PSEUDO_DOUBLE;
    
    // TYPE_CHAR
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\''){
        return TYPE_CHAR;
    }

    //TYPE_INT
    bool isInt = true;
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    for (i < i; i++)
    {
        if (!isdigit(literal[i]))
        {
            isInt = false;
            break;
        }
    }
    if (isInt)
        return TYPE_INT;

    // TYPE_FLOAT
    bool isFloat = true;
    if (literal.back() != 'f')
        isFloat = false;
    if (literal.back() == 'f'){
        std::string num = literal.substr(0, l - 1);
        size_t f = 0;
        if (num[f] == '+' || num[f] == '-')
            f++;
        for (f < num.length(); f++){
            bool hasPoint = false;
            if (num[f] == '.'){
                if (hasPoint){
                    isFloat = false;
                    break;
                }
                hasPoint = true;
            }
            else if (!isdigit(num[f])){
                isFloat = false;
                break;
            }
        }
    }
    if (isFloat)
        return TYPE_FLOAT;
    //TYPE_DOUBLE

    bool isDouble = true;
    size_t d = 0;
    if (literal[d] == '+' || num[d] == '-')
    d++;
    for (d < literal.length(); d++){
        bool hasPoint = false;
        if (literal[d] == '.'){
            if (hasPoint){
                isDouble = false;
                break;
            }
            hasPoint = true;
        }
        else if (!isdigit(num[d])){
            isDouble = false;
            break;
        }
    }
    if (isDouble)
        return TYPE_DOUBLE;

    return TYPE_INVALID;
}

void ScalarConverter::convertChar(const std::string &literal){
    LiteralType type = getLiteralType(literal);
    size_t i;
    
    if (type == TYPE_CHAR){
        std::cout << "char: " << literal << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    else if (type == TYPE_INT){
        std::cout << "char: " << literal << std::endl;
        std::cout << "int: " << literal << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
    }
    else if (type == TYPE_FLOAT){
        std::cout << "char: " << literal << std::endl;
        std::cout << "int: " << literal << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        // ./convert 42.0f
        // char: '*'
        // int: 42
        // float: 42.0f
        // double: 42.0
    }
    else if (type == TYPE_DOUBLE){
        size_t i;
        std::cout << "char: " << literal << std::endl;
        std::cout << "int: " << literal << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << std::endl;
    }
    else if (type == TYPE_PSEUDO_FLOAT){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
    }
    else if (type == TYPE_PSEUDO_DOUBLE){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
    }
    else if (type == TYPE_INVALID){
        std::cout << "Invalid input." << std::endl;
    }
    return ;
}
#include "ScalarConverter.hpp"

LiteralType ScalarConverter::getLiteralType(const std::string &literal)
{
    size_t l = literal.length();

    //TYPE_PSEUDO_FLOAT
    if (literal == "nanf" || literal == "inff" || literal == "+inff" || literal == "-inff")
        return TYPE_PSEUDO_FLOAT;
    //TYPE_PSEUDO_DOUBLE
    if (literal == "nan" || literal == "inf" || literal == "+inf" || literal == "-inf")
        return TYPE_PSEUDO_DOUBLE;
    // TYPE_CHAR
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
    bool isFloat = true;
    if (literal.back() != 'f')
        isFloat = false;
    if (literal.back() == 'f'){
        std::string num = literal.substr(0, l - 1);
        size_t f = 0;
        if (num[f] == '+' || num[f] == '-')
            f++;
        bool hasPoint = false;
        for (; f < num.length(); f++){
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
    if (literal[d] == '+' || literal[d] == '-')
        d++;
    bool hasPoint = false;
    for (; d < literal.length(); d++){
        if (literal[d] == '.'){
            if (hasPoint){
                isDouble = false;
                break;
            }
            hasPoint = true;
        }
        else if (!isdigit(literal[d])){
            isDouble = false;
            break;
        }
    }
    if (isDouble)
        return TYPE_DOUBLE;

    return TYPE_INVALID;
}

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
    std::cout << "float: " << f;
    if (f == i)
        std::cout << ".0";
    std::cout << "f\n";
}

void ScalarConverter::convertChar(const std::string &literal){
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
    
    double d;
    switch(type) {
        case TYPE_CHAR:
            d = static_cast<double>(literal[1]);            break;
        case TYPE_INT:
            d = static_cast<double>(std::stoi(literal));    break;
        case TYPE_FLOAT:
            d = static_cast<double>(std::stof(literal));    break;
        case TYPE_DOUBLE:
            d = std::stod(literal);                         break;
        default: // pseudo literals and invalid
            d = 0;                                          break;                      
    }

    int i = static_cast<int>(d);
    float f = static_cast<float>(d);
    printChar(i);
    printInt(d, i);
    printFloat(f, i);
    std::cout << "double: " << d << std::endl;
    return ;
}
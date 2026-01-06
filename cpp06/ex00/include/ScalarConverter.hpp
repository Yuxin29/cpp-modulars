#pragma once

#include <string>
#include <iostream>

// NaN: not a number, it is a illegal result mark, std::numeric_limits<double>::quiet_NaN(),  
//                                  eg. 0.0 / 0.0, sqrt(-1.0), 
// +inf: + endlessly big            eg double inf = std::numeric_limits<double>::infinity();
// -inf: - endlessly small          eg double -inf = -std::numeric_limits<double>::infinity();
enum LiteralType
{
    TYPE_CHAR,                      // 0
    TYPE_INT,                       // 1
    TYPE_FLOAT,                     // 2    32 bytes, end with f, eg 3.14f
    TYPE_DOUBLE,                    // 3    64 bits, by default,  eg 3.14
    TYPE_PSEUDO_FLOAT,              // 4    fake float            eg nanf, +inff, -inff
    TYPE_PSEUDO_DOUBLE,             // 5    fake double           eg nan, +inf, -inf
    TYPE_INVALID                    // 6    all uncategrized type
}

class ScalarConverter
{
private:
    static LiteralType getLiteralType(const std::string &literal);
public:
    //Write a class ScalarConverter that will contain only one static method "convert" 
    // that will take as a parameter a string representation of a C++ literal in its most common form 
    //and output its value in the following series of scalar types:
    static void convertChar(const std::string &literal);
};
#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2){
        (void)av;
        std::cout << "invalid arguement" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
}

//example output
// ./convert 0
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0
// ./convert nan
// char: impossible
// int: impossible
// float: nanf
// double: nan
// ./convert 42.0f
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0
// 9
// ./convert "'a'"
// char: 'a'
// int: 97
// float: 97.0f
// double: 97

// conversion unsafe tests:
// ./convert 999999999999999999999
// ./convert -999999999999999999999
// ./convert 1e999
// ./convert 42f42

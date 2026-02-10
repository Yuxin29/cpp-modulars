#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1){
        std::cout << "Error: non_valid input\n";
        return 1;
    }
    
    return 0;
}

// $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
// 42
// $> ./RPN "7 7 * 7 -"
// 42
// $> ./RPN "1 2 * 2 / 2 * 2 4 - +"
// 0
// $> ./RPN "(1 + 1)"
// Error
// $>


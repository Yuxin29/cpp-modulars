#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2){
        std::cout << "Error: non_valid input\n";
        return 1;
    }

    //Your program must process this expression and output the correct result on the standard output.
    // If an error occurs during the execution of the program an error message should be displayed on the standard error.
    try
    {
        RPN test(av[1]);
        test.calculate();
    }
    catch (std::exception &e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}

// $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
// 42
// how: 72 - 9 - 9 - 9 - 4 + 1 = 45 - 3

// $> ./RPN "7 7 * 7 -"
// 42
// $> ./RPN "1 2 * 2 / 2 * 2 4 - +"
// 0
// $> ./RPN "(1 + 1)"
// Error
// $>


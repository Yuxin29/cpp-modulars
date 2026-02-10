#include "PmergeMe.hpp"
#include <iostream>

//Your program must be able to use a positive integer sequence as argument.
static check_input(char **av)
{

}

int main(int ac, char **av)
{
    if (ac == 1){
        std::cout << "Error: non_valid input\n";
        return 1;
    }
    if (!check_input(av)) {
        std::cout << "Error: non_valid input\n";
        return 1;
    }

    return 0;
}
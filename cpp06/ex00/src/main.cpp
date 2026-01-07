
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2){
        (void)av;
        std::cout << "invalid arguement" << std::endl;
        return 1;
    }
    ScalarConverter::convertChar(av[1]);
}
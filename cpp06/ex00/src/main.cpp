
#include "ScalarConverter"

int main(int ac, char **av)
{
    if (ac != 2){
        std::cout << "" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
}
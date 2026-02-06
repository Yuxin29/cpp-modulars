#include "Harl.hpp"

//Give the name harlFilter to your executable.
int main(int ac, char **av)
{
    Harl harl;
     
    if (ac != 2){
        std::cout << "Wrong av number." << std::endl;
        return 1;
    }
    harl.complain(av[1]);
    return 0;
}

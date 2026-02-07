#include "ScavTrap.hpp"

int main()
{
    {
        std::cout << "----------" << std::endl;
        ScavTrap Adam = ScavTrap("Adam");
        ScavTrap Bob(Adam);
        Adam = ScavTrap("Charles");
    } 
    std::cout << std::endl;
    
    {
        std::cout << "----------" << std::endl;
        ScavTrap Adam = ScavTrap("Adam");
        Adam.print_state();
        Adam.guardGate();
        Adam.attack("aa");
        Adam.print_state();
        
    } 
    std::cout << std::endl;

    return 0;
}
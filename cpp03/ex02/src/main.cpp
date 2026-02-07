#include "FragTrap.hpp"

int main()
{
    {
        std::cout << "----------" << std::endl;
        FragTrap Adam = FragTrap("Adam");
        FragTrap Bob(Adam);
        Adam = FragTrap("Charles");
    }
    std::cout << std::endl;

    {
        std::cout << "----------" << std::endl;
        FragTrap Adam = FragTrap("Adam");
        Adam.print_state();
        Adam.highFivesGuys();
        Adam.attack("aa");
        Adam.print_state();
    } std::cout << std::endl;
}
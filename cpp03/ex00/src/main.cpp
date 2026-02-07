#include "ClapTrap.hpp"

int main()
{
    {
        std::cout << "---------- testing constuctors ----------" << std::endl;
        ClapTrap Adam = ClapTrap("Adam");
        ClapTrap Bob(Adam);
        Adam = ClapTrap("Charles");
    }
    std::cout << std::endl;
    {
        std::cout << "---------- basic testing ----------" << std::endl;
        ClapTrap Adam = ClapTrap("Adam");
        Adam.print_state();
        Adam.attack("someone");
        Adam.print_state();
        Adam.takeDamage(2);
        Adam.print_state();
        Adam.beRepaired(1);
        Adam.print_state();
        Adam.takeDamage(10);
        Adam.print_state();
    }
    std::cout << std::endl;
    {
        std::cout << "---------- death testing ----------" << std::endl;
        ClapTrap a("A");
        ClapTrap b("B");
        a.attack("B");
        a.takeDamage(5);
        a.beRepaired(3);
        a.print_state();
        b.print_state();
        // Test energy depletion
        for (int i = 0; i < 15; ++i)
            a.attack("B");
        // Test death
        a.takeDamage(100);
        // should not work
        a.beRepaired(5);
    }
    std::cout << std::endl;
    return 0;
}
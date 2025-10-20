#pragma once

#include "ClapTrap.hpp"

// ScavTrap will also have its own special capacity:
// void guardGate();
// This member function will display a message informing that ScavTrap is now in Gate
// keeper mode.
// Don’t forget to add more tests to your program.

class ScavTrap
    : public ClapTrap
{
//private:
    //no need, inherite from parent class ClapTrap ???

public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& another);
    ScavTrap& operator=(const ScavTrap &other);
    ~ScavTrap();

    //This member function will display a message informing that ScavTrap is now in Gate keeper mode.
    void guardGate();
    void attack(const std::string& target);
};


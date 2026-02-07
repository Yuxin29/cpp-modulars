#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
private:
    std::string _name;
    int         _hitPoint = 10;
    int         _energyPoint = 10;
    int         _attackDamagePoint = 0;

public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& another);
    ClapTrap& operator=(const ClapTrap &other);
    ~ClapTrap(); 
    
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void print_state(); //testing print, delete later
};

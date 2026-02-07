#pragma once

#include <string>
#include <iostream>

// Access-right    internal  child-class   external
// private	        yes	        no	        no
// protected	    yes	        yes	        no
// public	        yes	        yes	        yes
class ClapTrap
{
protected:
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

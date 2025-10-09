
#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <string>
#include <iostream>

/*
They both have a Weapon and a name. 
They also have a member function attack() that displays 
While HumanA takes the Weapon in its constructor, HumanB doesn’t.
• HumanB may not always have a Weapon, whereas HumanA will always be armed
*/
class HumanA
{
private:
    std::string name;
    
public:
    HumanA(std::string name, Weapon armer);	//Constructor: class method, eg.   Zombie z("Manday")   stack mem
	~HumanA();			                    //deconstructer

    void attack();
};

#endif

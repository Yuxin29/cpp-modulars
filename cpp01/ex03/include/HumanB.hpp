# pragma once

#include "Weapon.hpp"

// They both have a Weapon and a name. 
// They also have a member function attack() that displays 
// While HumanA takes the Weapon in its constructor, HumanB doesn’t.
// • HumanB may not always have a Weapon, whereas HumanA will always be armed
class HumanB
{
private:
    std::string _name;
    Weapon      *_weapon;//*, could be a solid weapon, could also be a nullptr

public:
    HumanB(std::string name);
	~HumanB();
    
    void setWeapon(Weapon &weapon);
    void attack();
};
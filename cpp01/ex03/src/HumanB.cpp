#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    if (weapon)//first null check weapon needed
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " attacks with nothing." << std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
    weapon = weapon;
}
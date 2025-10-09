#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon* weapon)
{
    this->name = name;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    //first null check weapon needed
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon *weapon)
{
    this->weapon = weapon;
}
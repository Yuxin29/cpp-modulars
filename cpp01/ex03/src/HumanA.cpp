#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
    :name(name), weapon(weapon) //& or const member variable must be initedted before the {}
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
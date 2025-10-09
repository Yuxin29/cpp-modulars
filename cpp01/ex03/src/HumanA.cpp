#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon armer)
{
    this->name = name;
    this->Weapon->setWeapon(armer);
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << HumanA->Weapon->getType << std::endl;
}
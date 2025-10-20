/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:25:27 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/20 18:58:38 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    :ClapTrap() //do I need this ??
{
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamagePoint = 20;
    std::cout << "ScavTrap being constructed without name." << std::endl;
}

// cavTrap will use the attributes of ClapTrap (update ClapTrap in consequence) and
// • Name, which is passed as parameter to a constructor
// • Hit points (100), represent the health of the ClapTrap
// • Energy points (50)
// • Attack damage (20)
ScavTrap::ScavTrap(std::string name)
    :ClapTrap(name)
{
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamagePoint = 20;
    std::cout << "ScavTrap being constructed: " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& another)
    :ClapTrap(another)
{
    std::cout << "copy ScavTrap from: " << another._name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other);  //first copy assint in parerent clase.
    std::cout << "copy assign ScavTrap from: " << other._name << " to this one." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap being deconstructed: " << _name << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap: " << _name << ": gate protection mode is on." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_hitPoint <= 0)
    {
        std::cout << "ScavTrap: " << _name << " is dead: out of hit-points." << std::endl;
        return;
    }
    if (_energyPoint <= 0)
    {
        std::cout << "ScavTrap: " << _name << " is out of energy points to attack." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target 
    << ", causing " << _attackDamagePoint << " points of damage!" << std::endl;
    _energyPoint -= 1;
}
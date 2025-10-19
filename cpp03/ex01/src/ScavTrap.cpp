/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:25:27 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/18 14:25:36 by yuwu             ###   ########.fr       */
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

/*
ClapTrap::ClapTrap(const ClapTrap& another)
{
    std::cout << "copy ClapTrap: " << another._name << std::endl;
    this->_name = another._name;
    this->_hitPoint = another._hitPoint;
    this->_energyPoint = another._energyPoint;
    this->_attackDamagePoint = another._attackDamagePoint;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "copy assign ClapTrap: " << other._name << " to this one." << std::endl;
    this->_name = other._name;
    this->_hitPoint = other._hitPoint;
    this->_energyPoint = other._energyPoint;
    this->_attackDamagePoint = other._attackDamagePoint;
    return *this;
}
*/

ScavTrap::ScavTrap(const ScavTrap& another)
    :ClapTrap(another)
{
    //do I need to do something:
    std::cout << "copy ScavTrap: " << another._name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "copy assign ScavTrap: " << other._name << " to this one." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap being deconstructed: " << _name << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << _name << ": gate protection mode is on." << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:22:59 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/20 18:10:28 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap being constructed without name." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    :_name(name)
{
    std::cout << "ClapTrap being constructed: " << name << std::endl;
}

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

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap being deconstructed: " << _name << std::endl;
}

// ClapTrap <name> attacks <target>, causing <damage> points of damage!
// Attacking and repairing cost 1 energy point each. 
// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
void ClapTrap::attack(const std::string& target)
{
    if (_hitPoint <= 0)
    {
        std::cout << _name << " is dead: out of hit-points." << std::endl;
        return;
    }
    if (_energyPoint <= 0)
    {
        std::cout << _name << " is out of energy points to attack." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target 
    << " causing " << _attackDamagePoint << " points of damage!" << std::endl;
    _energyPoint -= 1;
}
    
//health level down when take damage
void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << _name << " takes damages of " << amount << " points."<< std::endl;
   _hitPoint -= amount;
//    if (_hitPoint < 0) 
//         _hitPoint = 0;
}

// Attacking and repairing cost 1 energy point each. 
// When ClapTrap repairs itself, it gets <amount> hit points back.
// use energy but get nore ehlting
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoint <= 0)
    {
        std::cout << _name << " is dead: out of hit-points." << std::endl;
        return;
    }
    if (_energyPoint <= 0)
    {
        std::cout << _name << " is out of energy points to repair." << std::endl;
        return;
    }
    std::cout << _name << " is repairing itself with points: " << amount << std::endl;
    _energyPoint -= 1;
    _hitPoint += amount;
}

void ClapTrap::print_state()
{
    std::cout << _name << ": _hitPoint = " << _hitPoint << std::endl;
    std::cout << _name << ": _energyPoint = " << _energyPoint << std::endl;
    std::cout << _name << ": _attackDamagePoint = " << _attackDamagePoint << std::endl;
    std::cout << "*******" << std::endl;
}

// Of course, ClapTrap can’t do anything if it has no hit points or energy points left.
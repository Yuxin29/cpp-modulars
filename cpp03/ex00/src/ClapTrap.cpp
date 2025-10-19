/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:22:59 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/18 16:00:01 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap being constructed with out name." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap being constructed: " << name << std::endl;
    _name = name;
}

ClapTrap::ClapTrap(const ClapTrap& another)
{
    std::cout << "copy ClapTrap: " << another._name << std::endl;
    this->_name = another._name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "copy assign ClapTrap: " << other._name << " to this one." << std::endl;
    this->_name = other._name;
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
    if (_hitPoint <= 0 || _energyPoint <= 0)
    {
        std::cout << _name << " is runnign out of hit- or ennerge- points." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target 
    << " causing " << 1 << " points of damage!" << std::endl;
    _energyPoint -= 1;
    _hitPoint -= 1;
}
    
void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << _name << " takes damages of " << amount << " points."<< std::endl;
    _attackDamagePoint -= amount;
}

// Attacking and repairing cost 1 energy point each. 
// When ClapTrap repairs itself, it gets <amount> hit points back. 
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoint <= 0 | _energyPoint <= 0)
    {
        std::cout << _name << " is runnign out of ennerge-points to repair." << std::endl;
        return;
    }
    std::cout << _name << " is reparing itself with points: " << amount << std::endl;
    _energyPoint -= 1;
}

void ClapTrap::print_state()
{
    std::cout << _name << ": _hitPoint = " << _hitPoint << std::endl;
    std::cout << _name << ": _energyPoint = " << _energyPoint << std::endl;
    std::cout << _name << ": _attackDamagePoint = " << _attackDamagePoint << std::endl;
    std::cout << "*******" << std::endl;
}

// Of course, ClapTrap can’t do anything if it has no hit points or energy points left.
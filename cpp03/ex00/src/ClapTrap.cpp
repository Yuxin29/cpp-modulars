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

// The constructors and destructor must also display a message, 
// so your peer-evaluators can easily see they have been called.
ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap being constructed: " << name << std::endl;
    _name = name;
}

ClapTrap::ClapTrap(const ClapTrap& another)
{
    std::cout << "msg" << std::endl;
    this->_name = another._name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    this->_name = other._name;
    return *this;

}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap being deconstructed" << std::endl;
}

// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
// When ClapTrap repairs itself, it gets <amount> hit points back. 

// Attacking and repairing cost 1 energy point each. 
// Of course, ClapTrap can’t do anything if it has no hit points or energy points left.

// ClapTrap <name> attacks <target>, causing <damage> points of damage!
void ClapTrap::attack(const std::string& target)
{
    if (_hitPoint <= 0 | _energyPoint <= 0)
    {
        std::cout << _name << " is runnign out of attacking-points." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << "  attacks " << target << " causing " << 1 << " points of damage!" << std::endl;
    _energyPoint -= 1;
}
    
void ClapTrap::takeDamage(unsigned int amount)
{
    _attackDamagePoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoint <= 0 | _energyPoint <= 0)
    {
        std::cout << _name << " is runnign out of ennerge-points to repair." << std::endl;
        return;
    }
    std::cout << _name << " is reparing itself with points: " << amount << std::endl;
    _attackDamagePoint -= amount;
    _energyPoint -= 1;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:22:59 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 11:39:09 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap: ClapTrap being constructed without name." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    :_name(name)
{
    std::cout << "ClapTrap: ClapTrap being constructed: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& another)
{
    std::cout << "ClapTrap: copy ClapTrap from: " << another._name << std::endl;
    this->_name = another._name;
    this->_hitPoint = another._hitPoint;
    this->_energyPoint = another._energyPoint;
    this->_attackDamagePoint = another._attackDamagePoint;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap: copy assign ClapTrap from: " << other._name << " to this one." << std::endl;
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

//_hitPoint = 10;           health level            life / blood level
//_energyPoint = 10;        Energy level            movement level
//_attackDamagePoint = 0;   Attack damage level      
// Attacking and repairing cost 1 energy point each.
// Of course, ClapTrap can’t do anything if it has no hit points or energy points left.
void ClapTrap::attack(const std::string& target)
{
    if (_hitPoint <= 0)
    {
        std::cout << _name << " is dead: out of hit-points." << std::endl;
        return;
    }
    if (_energyPoint <= 0)
    {
        std::cout << _name << " can not attack: out of energy-points." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target 
    << ", causing " << _attackDamagePoint << " points of damage!" << std::endl;
    _energyPoint -= 1;
}
    
//health level down when take damage
// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoint <= 0)
    {
        std::cout << _name << " can not take more damages." << std::endl;
        return;
    }
    int damage = static_cast<int>(amount);
    _hitPoint -= damage;
    if (_hitPoint < 0) 
        _hitPoint = 0;
    std::cout << "ClapTrap: " << _name << " takes damages of " << damage << " points."<< std::endl;
}

// Attacking and repairing cost 1 energy point each. 
// Of course, ClapTrap can’t do anything if it has no hit points or energy points left.
// When ClapTrap repairs itself, it gets <amount> hit points back.
// use energy but get more heathy
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoint <= 0)
    {
        std::cout << _name << " is dead: out of hit-points. can not be repaired anymore" << std::endl;
        return;
    }
    if (_energyPoint <= 0)
    {
        std::cout << _name << " can not repair: out of energy-points." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " is repairing itself, revocering points of: " << amount << std::endl;
    _energyPoint -= 1;
    _hitPoint += amount;
}

void ClapTrap::print_state()
{
    std::cout << "ClapTrap " << _name << ": _hitPoint = " << _hitPoint << std::endl;
    std::cout << "ClapTrap " << _name << ": _energyPoint = " << _energyPoint << std::endl;
    std::cout << "ClapTrap " << _name << ": _attackDamagePoint = " << _attackDamagePoint << std::endl;
    std::cout << "*******" << std::endl;
}

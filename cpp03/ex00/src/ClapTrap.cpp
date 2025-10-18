/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:22:59 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/18 14:39:44 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// The constructors and destructor must also display a message, 
// so your peer-evaluators can easily see they have been called.
ClapTrap(std::string name)
{
    std::cout << "ClapTrap being constructed: " << name << std::endl;
}

ClapTrap(const ClapTrap& another)
{
    std::cout << "msg" << std::endl;
}

ClapTrap& operator=(const ClapTrap &other)
{
    std::cout << "msg" << std::endl;
}

~ClapTrap()
{
    std::cout << "ClapTrap being deconstructed" << std::endl;
}

// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
// When ClapTrap repairs itself, it gets <amount> hit points back. 

// Attacking and repairing cost 1 energy point each. 
// Of course, ClapTrap can’t do anything if it has no hit points or energy points left.

// In all of these member functions, you have to print a message to describe what happens. 
// ClapTrap <name> attacks <target>, causing <damage> points of damage!
void ClapTrap::attack(const std::string& target)
{
     std::cout << "msg" << std::endl;
}
    
void ClapTrap::takeDamage(unsigned int amount)
{
     std::cout << "msg" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
     std::cout << "msg" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:27:59 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/20 18:59:00 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
    :ClapTrap() //do I need this ??
{
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamagePoint = 30;
    std::cout << "FragTrap being constructed without name." << std::endl;
}

// cavTrap will use the attributes of ClapTrap (update ClapTrap in consequence) and
// • Name, which is passed as parameter to a constructor
// • Hit points (100), represent the health of the ClapTrap
// • Energy points (50)
// • Attack damage (20)
FragTrap::FragTrap(std::string name)
    :ClapTrap(name)
{
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamagePoint = 30;
    std::cout << "FragTrap being constructed: " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& another)
    :ClapTrap(another)
{
    //do I need to do something:
    std::cout << "copy FragTrap from: " << another._name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
    ClapTrap::operator=(other);
    std::cout << "copy assign FragTrap from: " << other._name << " to this one." << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap being deconstructed: " << _name << std::endl;
}

//This member function displays a positive high fives request on the standard output.
void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap: " << _name << ": requests a positive high five!" << std::endl;
}
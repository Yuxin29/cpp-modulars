/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:48:40 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/05 16:48:42 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

//Constructor: class method, object level op, eg.   Zombie z("Manday")   stack mem
Weapon::Weapon(std::string type)
{
    this->type = type;
}

//deconstructer
Weapon::~Weapon()
{
}

const std::string& Weapon::getType(void)
{
    return (type);
}

void Weapon::setType(std::string new_type)
{
    this->type = new_type;
}

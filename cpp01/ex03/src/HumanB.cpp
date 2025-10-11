/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:50:17 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 17:01:06 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
: _name(name), _weapon(NULL)
{
}

HumanB::~HumanB()
{
}

//first null check weapon needed
void HumanB::attack()
{
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " has no weapon." << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}

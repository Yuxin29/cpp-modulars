/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:49:59 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 17:06:34 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//& or const member variable must be initedted before the {}
HumanA::HumanA(std::string name, Weapon& weapon)
:_name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

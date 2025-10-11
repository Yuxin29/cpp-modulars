/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:49:32 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 16:55:42 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

// They both have a Weapon and a name. 
// They also have a member function attack() that displays 
// While HumanA takes the Weapon in its constructor, HumanB doesn’t.
// • HumanB may not always have a Weapon, whereas HumanA will always be armed
class HumanB
{
private:
    std::string _name;
    Weapon  *_weapon;//*, could be a solid weapon, could also be a nullptr

public:
    HumanB(std::string name);
	~HumanB();
    
    void setWeapon(Weapon &weapon);
    void attack();
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:49:21 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 17:06:01 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

// They both have a Weapon and a name. 
// They also have a member function attack() that displays 
// While HumanA takes the Weapon in its constructor, HumanB doesn’t.
// • HumanB may not always have a Weapon, whereas HumanA will always be armed
class HumanA
{
private:
    std::string _name;
    Weapon& _weapon; //&, reference, it is already existing, local.
     
public:
    HumanA(std::string name, Weapon& weapon);
	~HumanA();
    
    void attack();
};

#endif

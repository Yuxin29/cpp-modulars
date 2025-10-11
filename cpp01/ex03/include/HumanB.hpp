/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:49:32 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 13:49:34 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <string>
#include <iostream>

/*
They both have a Weapon and a name. 
They also have a member function attack() that displays 
While HumanA takes the Weapon in its constructor, HumanB doesn’t.
• HumanB may not always have a Weapon, whereas HumanA will always be armed
*/
class HumanB
{
private:
    std::string name;
    //Weapon *weapon; //*, could be a solid weapon, could also be a nullptr

public:
    Weapon *weapon; //*, could be a solid weapon, could also be a nullptr

    HumanB(std::string name);	//Constructor: class method, eg.   Zombie z("Manday")   stack mem
	~HumanB();			                    //deconstructer
    
    void setWeapon(Weapon weapon);
    void attack();
};

#endif

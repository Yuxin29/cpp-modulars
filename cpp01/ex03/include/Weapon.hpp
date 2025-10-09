/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:49:45 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/05 16:49:48 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

/*
Implement a Weapon class that has:
• A private attribute type, which is a string.
• A getType() member function that returns a const reference to type.
• A setType() member function that sets type using the new one passed as parameter
*/
class Weapon
{
private:
    std::string type;
    
public:
    //Weapon();                   //Constructor: class method, eg.   Zombie z;            stack mem
    Weapon(std::string name);	//Constructor: class method, eg.   Zombie z("Manday")   stack mem
	~Weapon();			        //deconstructer

    void getType(void);
    void setType(std::string new_name);
};

#endif

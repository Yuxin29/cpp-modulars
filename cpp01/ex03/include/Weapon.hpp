/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:49:45 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 16:48:19 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

// • A private attribute type, which is a string.
// • A getType() member function that returns a const reference to type.
// • A setType() member function that sets type using the new one passed as parameter
class Weapon
{
private:
    std::string type;
    
public:
    Weapon(std::string type);
	~Weapon();

    const std::string& getType(void);
    void setType(std::string new_type);
};

#endif

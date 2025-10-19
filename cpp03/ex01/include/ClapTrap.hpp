/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:10:33 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/18 15:53:01 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
protected:
    std::string _name;
    int         _hitPoint = 10;
    int         _energyPoint = 10;
    int         _attackDamagePoint = 0;

public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& another);
    ClapTrap& operator=(const ClapTrap &other);
    ~ClapTrap(); 
    
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void print_state(); //testing print, delete later
};

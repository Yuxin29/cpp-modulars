/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:10:33 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 11:45:28 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

// Access-right    internal  child-class   external
// private	        yes	        no	        no
// protected	    yes	        yes	        no
// public	        yes	        yes	        yes
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

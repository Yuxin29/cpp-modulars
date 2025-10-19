/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:27:35 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/18 14:27:39 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class FragTrap
    : public ClapTrap
{

public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& another);
    FragTrap& operator=(const FragTrap &other);
    ~FragTrap(); 
    
    void highFivesGuys(void);
};

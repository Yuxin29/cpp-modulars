/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:25:04 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/18 14:25:14 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    {
        ClapTrap Adam = ClapTrap("Adam");
        ClapTrap Bob(Adam);
        Adam = ClapTrap("Charles");
    } std::cout << "----------" << std::endl;
    
    {
        ClapTrap Adam = ClapTrap("Adam");
        Adam.print_state();
        Adam.attack("someone");
        Adam.print_state();
        Adam.takeDamage(2);
        Adam.print_state();
        Adam.beRepaired(1);
        Adam.print_state();
    }
}
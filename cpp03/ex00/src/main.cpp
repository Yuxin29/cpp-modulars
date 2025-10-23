/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:22:07 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 11:37:21 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        Adam.takeDamage(10);
        Adam.print_state();
    }
    {
        ClapTrap a("A");
        ClapTrap b("B");
        a.attack("B");
        a.takeDamage(5);
        a.beRepaired(3);
        a.print_state();
        b.print_state();
        // Test energy depletion
        for (int i = 0; i < 15; ++i)
            a.attack("B");

        // Test death
        a.takeDamage(100);
        a.beRepaired(5);  // should not work
    }
}
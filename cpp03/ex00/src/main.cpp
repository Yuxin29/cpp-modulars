/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:22:07 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/18 16:04:54 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//Implement and turn in your own tests to ensure your code works as expected.
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:25:04 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/20 18:18:02 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    {
        ScavTrap Adam = ScavTrap("Adam");
        ScavTrap Bob(Adam);
        Adam = ScavTrap("Charles");
    } std::cout << "----------" << std::endl;
    
    {
        ScavTrap Adam = ScavTrap("Adam");
        Adam.print_state();
        Adam.guardGate();
        Adam.attack("aa");
        Adam.print_state();
        
    } std::cout << "----------" << std::endl;
}
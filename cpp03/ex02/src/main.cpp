/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:22:07 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/20 18:24:37 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    {
        FragTrap Adam = FragTrap("Adam");
        FragTrap Bob(Adam);
        Adam = FragTrap("Charles");
    }
    {
        FragTrap Adam = FragTrap("Adam");
        Adam.print_state();
        Adam.highFivesGuys();
        Adam.attack("aa");
        Adam.print_state();
    } std::cout << "----------" << std::endl;
}
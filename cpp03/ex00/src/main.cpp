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
    ClapTrap Mike = ClapTrap("Mike");
    ClapTrap Adam = ClapTrap("Adam");

    Mike.attack("someone");
    Mike.takeDamage(10);
    Adam.beRepaired(1);
}
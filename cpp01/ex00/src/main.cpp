/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:50:02 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/09 12:35:55 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    //heap zombie
    std::cout << "------now here comes a heap Zombie------" << std::endl;
    Zombie* testZombie = newZombie("boy");
    testZombie->announce();
    delete (testZombie);
    std::cout << "------heap Zombie test done------" << std::endl << std::endl;

    //stack zombie
    std::cout << "------now here comes a stack Zombie------" << std::endl;
    randomChump("girl z");
    std::cout << "------stack Zombie test done------" << std::endl;
    return 0;
}

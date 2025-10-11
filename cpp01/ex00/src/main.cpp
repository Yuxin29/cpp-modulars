/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:50:02 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 15:42:34 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    //heap zombies
    std::cout << "------now here comes a heap Zombie------" << std::endl;
    Zombie* testZombie = newZombie("boy");
    testZombie->announce();
    delete (testZombie);
    Zombie* emptyZombie = newZombie("");
    emptyZombie->announce();
    delete (emptyZombie);
    std::cout << "------heap Zombie test done------" << std::endl << std::endl;

    //stack zombie
    std::cout << "------now here comes a stack Zombie------" << std::endl;
    randomChump("girl z");
    randomChump("");
    std::cout << "------stack Zombie test done------" << std::endl;
    
    return 0;
}

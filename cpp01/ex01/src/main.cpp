/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:50:02 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 16:14:06 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    //heap zombie
    std::cout << "------now here comes heap Zombie arrays------" << std::endl;
    Zombie* boy_horde = zombieHorde(4, "boy");
    for (int i = 0; i < 4; i++)
    {
        std::cout << "this is Zombie index: " << i << std::endl;
        boy_horde[i].announce();
    }
    delete[] boy_horde;
    std::cout << "------heap Zombie arrays test done------" << std::endl << std::endl;

    std::cout << "------now here comes 0-Zombie arrays------" << std::endl;
    Zombie* none_horde = zombieHorde(0, "none");
    for (int i = 0; i < 0; i++)
    {
        std::cout << "this is Zombie index: " << i << std::endl;
        none_horde[i].announce();
    }
    delete[] none_horde;
    std::cout << "------0-Zombie arrays test done------" << std::endl << std::endl;

    std::cout << "------now here comes empty-Zombie arrays------" << std::endl;
    Zombie* empty_horde = zombieHorde(3, "");
    for (int i = 0; i < 3; i++)
    {
        std::cout << "this is Zombie index: " << i << std::endl;
        empty_horde[i].announce();
    }
    delete[] empty_horde;
    std::cout << "------empty-Zombie arrays test done------" << std::endl << std::endl;

    return 0;
}
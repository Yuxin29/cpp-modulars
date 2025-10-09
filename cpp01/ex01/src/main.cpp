/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:50:02 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/09 13:09:49 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    //heap zombie
    std::cout << "------now here comes heap Zombie arrays------" << std::endl;
    Zombie* horde = zombieHorde(4, "boy");
    for (int i = 0; i < 4; i++)
    {
        std::cout << "this is Zombie index " << i << std::endl;
        horde[i].announce();
    }
    // for (int i = 3; i >= 0; i--)
    // {
    //     std::cout << "this is Zombie index " << i << " being destroyed. " << std::endl;
    //     delete &horde[i];
    // }
    delete[] horde;
    std::cout << "------heap Zombie arrays test done------" << std::endl << std::endl;

    return 0;
}
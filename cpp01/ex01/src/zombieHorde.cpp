/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:49:12 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 16:10:54 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//return 0; //return (nullptr); / return NULL;
Zombie* zombieHorde(int N, std::string name)
{
    if (N < 1)
        return 0;
    Zombie *horde = new(std::nothrow) Zombie[N];
    if (!horde) //do I need to error check here??
    {
        std::cout << "Error: Failed to allocate mem for zombie horde." << std::endl;
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }
    return (horde);
}
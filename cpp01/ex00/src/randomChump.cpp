/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:49:00 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/07 19:00:07 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

//It creates a zombie, name it, and the zombie announces itself.
// stack memory
void    randomChump(std::string name)
{
    Zombie z(name);
    z.announce();
}

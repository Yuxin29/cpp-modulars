/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:49:12 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 15:36:04 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// It creates a zombie, name it, and return it so you can use it outside of the functionscope.
// "use it outside of the functionscope". -> exists and use independently
// heap memory, needs to delete it manully
Zombie* newZombie(std::string name)
{
    return (new Zombie(name));
}
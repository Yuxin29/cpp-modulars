/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:49:12 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/07 18:59:04 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

// It creates a zombie, name it, and return it so you can use it outside of the functionscope.
// use it outside of the functionscope. -> exits and use indepently
// heap memory, needs to delete it manullt
Zombie* newZombie(std::string name)
{
    return (new Zombie(name));
}
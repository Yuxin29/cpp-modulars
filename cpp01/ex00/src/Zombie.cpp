/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:48:40 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/11 16:00:13 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

//Constructor: class method, object level op, stack mem
Zombie::Zombie(std::string name)
: name(name)
{
}

//deconstructer
// The destructor must print a msg with the name of the zombie for debugging.
Zombie::~Zombie()
{
    std::cout << this->name << " is now destroyed." << std::endl;
}
    
void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
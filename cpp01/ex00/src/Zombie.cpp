/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:48:40 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/09 12:37:07 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//Constructor: class method, class level op, eg.   Zombie z;            stack mem
// Zombie::Zombie()
// {
// }

//Constructor: class method, object level op, eg.   Zombie z("Manday")   stack mem
Zombie::Zombie(std::string name)
{
    this->name = name;
}

//deconstructer
Zombie::~Zombie()
{
    std::cout << this->name << " is now destroyed." << std::endl;
}
    
void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:48:40 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/06 20:20:56 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>


//Constructor: class method, eg.   Zombie z;            stack mem
Zombie::Zombie()
{
}

//Constructor: class method, eg.   Zombie z("Manday")   stack mem
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
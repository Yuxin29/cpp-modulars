/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:23:58 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/24 12:08:33 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
    : Animal()
{
    _type = "Dog";
    std::cout << "Dog: " << _type << " constructed." << std::endl;
}

Dog::Dog(const Dog& other)
   : Animal(other)
{
    std::cout << "Copy dog " << _type << "." << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    Animal::operator=(other);
    std::cout << "Copy assign dog " << _type << "." << std::endl;
    return *this;
}

Dog::~Dog()
{    
    std::cout << "Dog: " << _type << " deconstructed." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "wuffffff" << std::endl;
}

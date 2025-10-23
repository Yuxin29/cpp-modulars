/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:23:58 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 14:03:58 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
    : Animal()
{
    _type = "Dog";
    std::cout << "Dog: " << _type << " begin constructed." << std::endl;
}

Dog::Dog(const Dog& other)
   : Animal(other)
{
    this->_type = other._type;
}

Dog& Dog::operator=(const Dog &other)
{
    Animal::operator=(other);
    this->_type = other._type;
    return *this;
}

Dog::~Dog()
{    
    std::cout << "Dog: " << _type << " begin deconstructed." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "wuffffff" << std::endl;
}


const Brain &Dog::getBrain() const
{
    return *_brain;
}

Brain &Dog::getBrain()
{   
    return *_brain;
}
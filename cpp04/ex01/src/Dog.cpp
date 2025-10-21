/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:23:58 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/21 19:12:39 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
    : Animal()
{
    type = "Dog";
    std::cout << "Dog: " << type << " begin constructed." << std::endl;
}

Dog::Dog(const Dog& other)
   : Animal(other)
{
    this->type = other.type;
}

Dog& Dog::operator=(const Dog &other)
{
    Animal::operator=(other);
    this->type = other.type;
    return *this;
}

Dog::~Dog()
{    
    delete _brain;   
    std::cout << "Dog: " << type << " begin deconstructed." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "wuffffff" << std::endl;
}

std::string Dog::getType() const
{
    return type;
}

const Brain &Dog::getBrain() const
{
    return *_brain;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:23:58 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/24 12:46:20 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
    : Animal()
{
    _type = "Dog";
    std::cout << "Dog: " << _type << " constructed." << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog& other)
    : Animal(other)
{
    _brain = new Brain(*other._brain);// deep copy
}

Dog& Dog::operator=(const Dog &other)
{
    if (this != &other) 
    {
        Animal::operator=(other);
        *_brain = *other._brain; //deepcopy
    }
    return *this;
}

Dog::~Dog()
{    
    delete _brain;
    std::cout << "Dog: " << _type << " deconstructed." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "wuffffff" << std::endl;
}


Brain &Dog::getBrain()
{ 
    return *_brain;
}

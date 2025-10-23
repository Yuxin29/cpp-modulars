/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:23:58 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 14:28:21 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
    : Animal()
{
    _type = "Dog";
    _brain = new Brain();
    std::cout << "Dog: " << _type << " begin constructed." << std::endl;
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
        delete _brain;                     // replease old copy
        _brain = new Brain(*other._brain); // deep copy
    }
    return *this;
}

Dog::~Dog()
{    
    delete _brain;
    std::cout << "Dog: " << _type << " begin deconstructed." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "wuffffff" << std::endl;
}


Brain &Dog::getBrain()
{ 
    return *_brain;
}

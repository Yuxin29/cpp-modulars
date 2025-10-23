/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:24:31 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 14:28:10 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
    : Animal()
{
    std::cout << "Cat: " << _type << " begin constructed." << std::endl;
    _type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat& other)
    : Animal(other)
{
    _brain = new Brain(*other._brain);// deep copy
}

Cat& Cat::operator=(const Cat &other)
{
    if (this != &other) 
    {
         Animal::operator=(other);
        delete _brain;                     // replease old copy
        _brain = new Brain(*other._brain); // deep copy
    }
    return *this;
}

Cat::~Cat()
{    
    delete _brain;
    std::cout << "Cat: " << _type << " begin deconstructed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "miaoooooo." << std::endl;
}

Brain &Cat::getBrain()
{
    return *_brain;
}
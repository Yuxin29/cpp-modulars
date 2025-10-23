/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:24:31 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 14:03:54 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
    : Animal()
{
    _type = "Cat";
    std::cout << "Cat: " << _type << " begin constructed." << std::endl;
}

Cat::Cat(const Cat& other)
    : Animal(other)
{
}

Cat& Cat::operator=(const Cat &other)
{
    Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{    
    std::cout << "Cat: " << _type << " begin deconstructed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "miaoooooo." << std::endl;
}

const Brain &Cat::getBrain() const
{
    return *_brain;
}

Brain &Cat::getBrain()
{   
    return *_brain;
}
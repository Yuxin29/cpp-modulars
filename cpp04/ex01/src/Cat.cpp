/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:24:31 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/21 19:08:27 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
    : Animal()
{
    type = "Cat";
    _brain = new Brain();
    std::cout << "Cat: " << type << " begin constructed." << std::endl;
}

Cat::Cat(const Cat& other)
    : Animal(other)
{
    this->type = other.type;
}

Cat& Cat::operator=(const Cat &other)
{
    Animal::operator=(other);
    this->type = other.type;
    return *this;
}

Cat::~Cat()
{
    delete _brain;    
    std::cout << "Cat: " << type << " begin deconstructed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "miaoooooo." << std::endl;
}

std::string Cat::getType() const
{
    return type;
}

const Brain &Cat::getBrain() const
{
    return *_brain;
}
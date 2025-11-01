/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:24:31 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/24 11:47:57 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
    : Animal()
{
    _type = "Cat";
    std::cout << "Cat: " << _type << " constructed." << std::endl;
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
    std::cout << "Cat: " << _type << " deconstructed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "miaoooooo." << std::endl;
}

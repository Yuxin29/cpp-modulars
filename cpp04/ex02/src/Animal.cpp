/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:20:59 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 13:11:57 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    _type = "Pet";
    std::cout << "Animal: " << _type << " begin constructed." << std::endl;
}

Animal::Animal(const Animal& other)
{
    this->_type = other._type;
}

Animal& Animal::operator=(const Animal &other)
{
    this->_type = other._type;
    return *this;
}

Animal::~Animal()
{    
    std::cout << "Animal: " << _type << " begin deconstructed." << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "woaaa I am an animal." << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}
    

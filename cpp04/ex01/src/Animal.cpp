/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:20:59 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/20 20:24:17 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    type = "Pet";
    std::cout << "Animal: " << type << " begin constructed." << std::endl;
}

Animal::Animal(const Animal& other)
{
    this->type = other.type;
}

Animal& Animal::operator=(const Animal &other)
{
    this->type = other.type;
    return *this;
}

Animal::~Animal()
{    
    std::cout << "Animal: " << type << " begin deconstructed." << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "woaaa I am an animal." << std::endl;
}

std::string Animal::getType() const
{
    return type;
}
    

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:26:25 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 13:27:25 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    _type = "WrongPet";
    std::cout << "WrongAnimal: " << _type << " begin constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    this->_type = other._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    this->_type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{    
    std::cout << "WrongAnimal: " << _type << " begin deconstructed." << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "woaaa I am a Wrong animal." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return _type;
}
    
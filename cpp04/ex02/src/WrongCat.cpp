/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:28:01 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/23 13:49:54 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
    : WrongAnimal()
{
    _type = "WrongCat";
    std::cout << "WrongCat: " << _type << " begin constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
    : WrongAnimal(other)
{
    this->_type = other._type;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    WrongAnimal::operator=(other);
    this->_type = other._type;
    return *this;
}

WrongCat::~WrongCat()
{    
    std::cout << "WrongCat: " << _type << " begin deconstructed." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "niaoooooo." << std::endl;
}

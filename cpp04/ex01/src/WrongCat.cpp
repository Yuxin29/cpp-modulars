/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:28:01 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/24 12:12:12 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
    : WrongAnimal()
{
    _type = "WrongCat";
    std::cout << "WrongCat: " << _type << " constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
    : WrongAnimal(other)
{
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat()
{    
    std::cout << "WrongCat: " << _type << " deconstructed." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "niaoooooo." << std::endl;
}

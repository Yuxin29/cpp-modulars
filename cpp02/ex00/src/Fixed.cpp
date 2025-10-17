/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:52:43 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/17 15:38:28 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor		create and initiate
Fixed::Fixed()
{
    _fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

//Copy constructor		    initiate this obj using another obj
Fixed::Fixed(const Fixed& another)      
//: _fixedPointValue(another._fixedPointValue).  lighter, better, will use this later
{
    std::cout << "Copy constructor called" << std::endl;
    *this = another; 
}

//Copy assignment operator	    asign an obj to another exiting obj     how to use it c = b;
//return a *this to support assining chain
// -->>copy = first copy, then asigne????
//--->>check this != &other to avoid "self-asigning"
Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        std::cout << "getRawBits member function called" << std::endl;
        this->_fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

//Destructor: release resources
Fixed::~Fixed()
{
   std::cout << "Destructor called" << std::endl;
}
    
//returns the raw value of the fixed-point value.
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}
   
//sets the raw value of the fixed-point number.
void Fixed::setRawBits(int const raw)
{
    _fixedPointValue = raw;
}

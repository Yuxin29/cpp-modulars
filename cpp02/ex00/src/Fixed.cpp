/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:52:43 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/16 10:52:56 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor		    create and initiate
Fixed::Fixed()
{
    _FixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

//Copy constructor		    initiate this obj using another obj
Fixed::Fixed(const Fixed& another)
//: _FixedPointValue(another._FixedPointValue)
{
    std::cout << "Copy constructor called " << std::endl;
    *this = another; 
    //this->_FixedPointValue = another._FixedPointValue;
}

//Copy assignment operator	    asign an obj to another exiting obj 
Fixed& Fixed::operator=(const Fixed &other)
{
    //--->>check this != &other to avoid "self-asigning", return a *this to support assining chain
    //c = b;
    std::cout << "Copy assignment operator called" << std::endl;
    std::cout << "getRawBits member function called" << std::endl;
    this->_FixedPointValue = other._FixedPointValue;
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
    return _FixedPointValue;
}
   
//sets the raw value of the fixed-point number.
void Fixed::setRawBits(int const raw)
{
    _FixedPointValue = raw;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:54:14 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/16 12:05:06 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

// -------------------------------------- Othodox Calonical Form elements -------------------------------------- 
Fixed::Fixed()
{
    _fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    _fixedPointValue = value << _fractionalBitsNumber;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    _fixedPointValue = value * (1 << _fractionalBitsNumber);
    std::cout << "Float constructor called" << std::endl;
}

//Copy constructor		    initiate this obj using another obj
Fixed::Fixed(const Fixed& another)
{
    std::cout << "Copy constructor called " << std::endl;
    this->_fixedPointValue = another._fixedPointValue;
}

//Copy assignment operator	    asign an obj to another exiting obj 
Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) //--->>check this != &other to avoid "self-asigning"
    {
        std::cout << "getRawBits member function called" << std::endl;
        this->_fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed()
{
   std::cout << "Destructor called" << std::endl;
}

//-------------------------------------- Setters and Getters --------------------------------------
//get / set the raw value of the fixed-point value.
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    _fixedPointValue = raw;
}

//-------------------------------------- toFloat and toInt --------------------------------------
//converts the fixed-point value to a floating-point value.
float Fixed::toFloat( void ) const
{
    return (float)_fixedPointValue / (1 << _fractionalBitsNumber);
}

// converts the fixed-point value to an integer value.
int Fixed::toInt( void ) const
{
    return _fixedPointValue >> _fractionalBitsNumber;
}

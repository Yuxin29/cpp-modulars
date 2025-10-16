/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:54:14 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/16 11:34:28 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

//Default constructor		    create and initiate
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    _fixedPointValue = value << _fractionalBitsNumber;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    _fixedPointValue = value; //not correctl
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
    //--->>check this != &other to avoid "self-asigning", return a *this to support assining chain
    //c = b;
    std::cout << "Copy assignment operator called" << std::endl;
    std::cout << "getRawBits member function called" << std::endl;
    this->_fixedPointValue = other._fixedPointValue;
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

    
//converts the fixed-point value to a floating-point value.
float Fixed::toFloat( void ) const
{
    return (float)_fixedPointValue / (1 << _fractionalBitsNumber);
}

// converts the fixed-point value to an integer value.
int Fixed::toInt( void ) const
{
    return _FixedPointValue >> _FractionalBitsNumber;
}

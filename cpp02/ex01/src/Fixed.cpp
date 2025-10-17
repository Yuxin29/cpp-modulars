/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:54:14 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/17 16:21:57 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* 
_fractionalBitsNumber = 8;
real_value = 42.42
--> fixedPointValue = 42.42 * (1 << 8) = 42.42 * 2^8  = round(42.42 × 256) ≈ 10859      // round: normal round, int: round down
--> fixedPointValue = 42 >> 8) = 42 * 2^8  = 10842                                      // int: not need to round                   <----
--> toFloat: 10859 / (1 << 8)  = 10859 / 2^8  = 10859 / 256 ≈ 42.421875                 //round down ?? with a few fractors             |
--> toInt: 10859 >> 8 = 10859 / 2^8  >> 8 = roundf(10859 / 256)                         // not need to round: al ready rounded here --->|
float       roundf( float num ); <cmath>
*/

// This function allows a Fixed obj to be directly used with output streams
// It converts the internal fixed-point value to a floating-point representation 
// and inserts it into the output stream.
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

//for int, no need for roundf
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    if (value > INT_MAX >> _fractionalBitsNumber)
        _fixedPointValue = INT_MAX;
    else if (value < INT_MIN >> _fractionalBitsNumber)
        _fixedPointValue = INT_MIN;
    else
        _fixedPointValue = value << _fractionalBitsNumber;
}

// need manully roundf, otherwise force to int(= round down)
// cannot directly roundf(value << _fractionalBitsNumber), because << can only be used for int
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    float tmp = roundf(value * (1 << _fractionalBitsNumber));
    if (tmp > INT_MAX)
        tmp = INT_MAX;
    else if (tmp < INT_MIN)
        tmp = INT_MIN;
    _fixedPointValue = static_cast<int>(tmp);
}

Fixed::Fixed(const Fixed& another)
: _fixedPointValue(another._fixedPointValue)
{
    std::cout << "Copy constructor called " << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
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
    return static_cast<int>(_fixedPointValue >> _fractionalBitsNumber);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:55:14 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/16 16:38:01 by yuwu             ###   ########.fr       */
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
    _fixedPointValue = roundf(value * (1 << _fractionalBitsNumber));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& another)
{
    std::cout << "Copy constructor called " << std::endl;
    this->_fixedPointValue = another._fixedPointValue;
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
float Fixed::toFloat( void ) const
{
    return (float)_fixedPointValue / (1 << _fractionalBitsNumber);
}

int Fixed::toInt( void ) const
{
    return _fixedPointValue >> _fractionalBitsNumber;
}

//-------------------------------------- 6 comparison operators  --------------------------------------
//The 6 comparison operators: >, <, >=, <=, == and !=.
bool Fixed::operator>(const Fixed &another) const  //the  const at the end make sure that this is not modified
{
    if (_fixedPointValue > another._fixedPointValue)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed &another) const
{
    if (_fixedPointValue < another._fixedPointValue)
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed &another) const
{
    if (_fixedPointValue >= another._fixedPointValue)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &another) const
{
    if (_fixedPointValue <= another._fixedPointValue)
        return true;
    return false;
}

bool Fixed::operator==(const Fixed &another) const
{
    if (_fixedPointValue == another._fixedPointValue)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &another) const
{
    if (_fixedPointValue != another._fixedPointValue)
        return true;
    return false;
}    

//-------------------------------------- 4 arithmetic operators  --------------------------------------
// Fixed const b(Fixed(5.05f) * Fixed(2));  Usage
//return a new Fixed !!!!!!!!!!!!!!!!!why not static at the begining
Fixed Fixed::operator+(const Fixed &another) const
{
    Fixed res;
    res._fixedPointValue = _fixedPointValue + another._fixedPointValue;
    return res;
}

Fixed Fixed::operator-(const Fixed &another) const
{
    Fixed res;
    res._fixedPointValue = _fixedPointValue - another._fixedPointValue;
    return res;
}   

Fixed Fixed::operator*(const Fixed &another) const
{
    Fixed res;
    res._fixedPointValue = _fixedPointValue * another._fixedPointValue;
    return res;
}

Fixed Fixed::operator/(const Fixed &another) const
{
    Fixed res;
    res._fixedPointValue = _fixedPointValue / another._fixedPointValue;  //need to consider devider can not be minus
    return res;
}
    
//-------------------------------------- 4 4 increment/decrement (pre and post) operators  --------------------------------------
// that will increase or decrease the fixed-point value from the smallest representable ϵ such as 1 + ϵ > 1.
// ++i      pre increment
// i++      post increment
    
//-------------------------------------- max and min operators  --------------------------------------
// • A static member function min that takes as parameters two references on fixed-point numbers, 
// and returns a reference to the smallest one.
// • A static member function min that takes as parameters two references to constant fixed-point numbers, 
// and returns a reference to the smallest one.
Fixed &Fixed::min(Fixed& a, Fixed& b) //static at hte beginging
{
    if (a._fixedPointValue < b._fixedPointValue)
        return (a);
    return (b);
    //case a = b included in 2nd case
}
//more to go
// static const Fixed &min(const Fixed &a, const Fixed& b); //if input is const, return also const
// static Fixed &max(Fixed &a, Fixed& b);
// static const Fixed &max(const Fixed &a, const Fixed& b); //if input is const, return also const
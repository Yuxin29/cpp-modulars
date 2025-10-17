/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:55:14 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/17 16:25:54 by yuwu             ###   ########.fr       */
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

//the  const at the end make sure that this is not modified
bool Fixed::operator>(const Fixed &another) const
{
    return (_fixedPointValue > another._fixedPointValue);
}

bool Fixed::operator<(const Fixed &another) const
{
    return (_fixedPointValue < another._fixedPointValue);
}

bool Fixed::operator>=(const Fixed &another) const
{
    return (_fixedPointValue >= another._fixedPointValue);
}

bool Fixed::operator<=(const Fixed &another) const
{
    return (_fixedPointValue <= another._fixedPointValue);
}

bool Fixed::operator==(const Fixed &another) const
{
    return (_fixedPointValue == another._fixedPointValue);
}

bool Fixed::operator!=(const Fixed &another) const
{
    return (_fixedPointValue != another._fixedPointValue);
}    

//-------------------------------------- 4 arithmetic operators  --------------------------------------

// Fixed const b(Fixed(5.05f) * Fixed(2));  Usage
// return a new Fixed !!!!!!!!!!!!!!!!!
// overflow is absolutely needed in *, but only optional/ couldb be there in + and -

Fixed Fixed::operator+(const Fixed &another) const
{
    long long tmp = static_cast<long long>(_fixedPointValue) + another._fixedPointValue;
    Fixed res;
    res._fixedPointValue = static_cast<int>(tmp);
    return res;
}

Fixed Fixed::operator-(const Fixed &another) const
{
    long long tmp = static_cast<long long>(_fixedPointValue) - another._fixedPointValue;
    Fixed res;
    res._fixedPointValue = static_cast<int>(tmp);
    return res;
}   

Fixed Fixed::operator*(const Fixed &another) const
{
    long long tmp = static_cast<long long>(_fixedPointValue) * another._fixedPointValue;
    Fixed res;
    res._fixedPointValue = static_cast<int>(tmp >> _fractionalBitsNumber);
    return res;
}

//error case could be: throw std::runtime_error("division by zero");
Fixed Fixed::operator/(const Fixed &another) const
{
    if (another._fixedPointValue == 0)
    {
        std::cout << "Error: division by zero." << std::endl;
        return Fixed();
    }
    long long tmp = static_cast<long long>(_fixedPointValue << _fractionalBitsNumber);
    Fixed res;
    res._fixedPointValue = static_cast<int>(tmp / another._fixedPointValue);
    return res;
}

//-------------------------------------- 4 increment/decrement (pre and post) operators  --------------------------------------

// that will increase or decrease the fixed-point value from the smallest representable ϵ such as 1 + ϵ > 1.
// ++i      pre increment
// i++      post increment
// why not void &operator++();   //pre  ++i
// because in cpp, pre-increment should allow chaining pre-increment
// like ++(++a); (++a).operator++(); 

//this is pre
Fixed &Fixed::operator++()
{
    ++_fixedPointValue;
    return *this;  
}

//this is post. int no use, just to differentia.
Fixed Fixed::operator++(int)
{
    Fixed old(*this);
    ++_fixedPointValue;
    return old;
}

Fixed &Fixed::operator--()
{
    --_fixedPointValue;
    return *this;  
}

Fixed Fixed::operator--(int)
{
    Fixed old(*this);
    --_fixedPointValue;
    return old;
}
    
//-------------------------------------- max and min operators  --------------------------------------

// A static member function min that takes as parameters two references on fixed-point numbers, 
// and returns a reference to the smallest one.
// A static member function min that takes as parameters two references to constant fixed-point numbers, 
// and returns a reference to the smallest one.

// in cpp, static is only in hpp file
Fixed &Fixed::min(Fixed& a, Fixed& b)
{
    if (a._fixedPointValue < b._fixedPointValue)
        return (a);
    return (b);
    //case a = b included in 2nd case  // RETHINK
}

//if input is const, return also const
const Fixed &Fixed::min(const Fixed &a, const Fixed& b)
{
    if (a._fixedPointValue < b._fixedPointValue)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed& b)
{
    if (a._fixedPointValue > b._fixedPointValue)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed& b)
{
    if (a._fixedPointValue > b._fixedPointValue)
        return (a);
    return (b);
}